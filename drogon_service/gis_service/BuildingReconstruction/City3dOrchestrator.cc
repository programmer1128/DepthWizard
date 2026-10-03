#include "City3dOrchestrator.h"
#include "City3dInputBuilder.h"
#include "City3dResultImporter.h"
#include "City3dWorkerProcess.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

namespace fs = std::filesystem;

#ifndef DEPTHWIZARD_DEFAULT_CITY3D_BINARY
#define DEPTHWIZARD_DEFAULT_CITY3D_BINARY ""
#endif

City3dConfig City3dConfig::fromEnvironment()
{
     City3dConfig config;
     const auto value = [](const char* name) -> std::string
     {
          const char* text = std::getenv(name);
          return text == nullptr ? std::string() : std::string(text);
     };
     config.workerBinary = value("DEPTHWIZARD_CITY3D_BINARY").empty()
         ? fs::path(DEPTHWIZARD_DEFAULT_CITY3D_BINARY) : fs::path(value("DEPTHWIZARD_CITY3D_BINARY"));
     if (!value("DEPTHWIZARD_CITY3D_WORKDIR").empty()) config.workRoot = value("DEPTHWIZARD_CITY3D_WORKDIR");
     if (!value("DEPTHWIZARD_CITY3D_TIMEOUT_S").empty())
     {
          // The slice keeps each building within 10-15 s.
          const double seconds = std::clamp(std::atof(value("DEPTHWIZARD_CITY3D_TIMEOUT_S").c_str()), 10.0, 15.0);
          config.timeout = std::chrono::milliseconds(static_cast<long long>(seconds * 1000.0));
     }
     if (!value("DEPTHWIZARD_CITY3D_MAX_BUILDINGS").empty())
          config.maxBuildings = static_cast<std::size_t>(
              std::clamp(std::atoi(value("DEPTHWIZARD_CITY3D_MAX_BUILDINGS").c_str()), 1, 5));
     config.keepWorkDirectories = value("DEPTHWIZARD_CITY3D_KEEP_WORKDIR") == "1";
     return config;
}

City3dRunSummary City3dOrchestrator::run(
     const BuildingCollection& buildings,
     const RasterGrid<int32_t>& labels,
     const SemanticScene& semantics,
     const GeoreferencedSurfaceBundle& surface,
     const RasterGrid<float>& ndsm,
     const SpatialMetadata& metadata,
     float renderHeightScale,
     const City3dConfig& config,
     const std::string& jobId)
{
     const auto started = std::chrono::steady_clock::now();
     City3dRunSummary summary;

     // Analyse all buildings; keep the eligible ones, largest first.
     std::vector<City3dCandidate> eligible;
     for (const BuildingInstance& building : buildings.buildings)
     {
          City3dCandidate candidate = City3dInputBuilder::analyse(
              building, labels, semantics, surface, ndsm, metadata, config);
          if (candidate.eligible)
          {
               eligible.push_back(std::move(candidate));
               continue;
          }
          City3dBuildingOutcome outcome;
          outcome.buildingId = building.buildingId;
          outcome.route = "not_eligible";
          outcome.reason = candidate.reason;
          summary.outcomes.push_back(outcome);
     }
     summary.eligibleCount = eligible.size();
     std::stable_sort(eligible.begin(), eligible.end(), [](const City3dCandidate& a, const City3dCandidate& b)
     { return a.footprintAreaSquareMetres > b.footprintAreaSquareMetres; });

     std::error_code error;
     const bool binaryUsable = !config.workerBinary.empty() && ::access(config.workerBinary.c_str(), X_OK) == 0;
     const fs::path jobRoot = config.workRoot / jobId;
     for (std::size_t rank = 0; rank < eligible.size(); ++rank)
     {
          const City3dCandidate& candidate = eligible[rank];
          City3dBuildingOutcome outcome;
          outcome.buildingId = candidate.buildingId;
          outcome.points = candidate.points.size();
          outcome.heightSpreadMetres = candidate.heightSpreadMetres;
          if (rank >= config.maxBuildings)
          {
               outcome.route = "over_budget";
               outcome.reason = "building_limit";
               summary.outcomes.push_back(outcome);
               continue;
          }
          outcome.route = "attempted";
          const auto building = std::find_if(buildings.buildings.begin(), buildings.buildings.end(),
              [&](const BuildingInstance& b) { return b.buildingId == candidate.buildingId; });
          if (!binaryUsable)
          {
               outcome.reason = "worker_unavailable";
               summary.outcomes.push_back(outcome);
               continue;
          }

          // Each building gets its own fresh job directory.
          const fs::path directory = jobRoot / ("b" + std::to_string(candidate.buildingId));
          fs::remove_all(directory, error);
          std::string problem;
          if (!City3dInputBuilder::writeJob(candidate, *building, metadata, config, jobId, directory, problem))
          {
               outcome.reason = "input_write_failed";
               summary.outcomes.push_back(outcome);
               continue;
          }
          const City3dProcessResult process = runCity3dWorker(
              config.workerBinary, directory / "request.json", directory / "result", directory / "worker.log",
              config.timeout);
          outcome.elapsedMs = process.elapsedMs;
          outcome.logTail = readLogTail(directory / "worker.log", 2048);
          if (!process.started)
               outcome.reason = "worker_start_failed";
          else if (process.timedOut)
               outcome.reason = "worker_timeout";
          else if (process.exitCode != 0)
               outcome.reason = "worker_exit_" + std::to_string(process.exitCode);
          else
          {
               City3dImportResult imported = City3dResultImporter::import(
                   directory / "result", jobId + "-b" + std::to_string(candidate.buildingId), *building,
                   candidate, renderHeightScale, config);
               outcome.workerStatus = imported.workerStatus;
               if (imported.accepted)
               {
                    outcome.accepted = true;
                    outcome.reason = "accepted";
                    outcome.roofTriangles = imported.shell.roofIndices.size() / 3;
                    outcome.wallTriangles = imported.shell.wallIndices.size() / 3;
                    summary.acceptedShells.emplace(candidate.buildingId, std::move(imported.shell));
               }
               else
                    outcome.reason = imported.reason;
          }
          if (!config.keepWorkDirectories) fs::remove_all(directory, error);
          summary.outcomes.push_back(outcome);
     }
     if (!config.keepWorkDirectories && fs::is_empty(jobRoot, error)) fs::remove(jobRoot, error);
     summary.totalMs = std::chrono::duration_cast<std::chrono::milliseconds>(
         std::chrono::steady_clock::now() - started).count();
     return summary;
}

std::size_t City3dOrchestrator::attachAcceptedShells(BuildingCollection& buildings, const City3dRunSummary& summary)
{
     std::size_t attached = 0;
     for (BuildingInstance& building : buildings.buildings)
     {
          const auto shell = summary.acceptedShells.find(building.buildingId);
          if (shell == summary.acceptedShells.end()) continue;
          building.reconstructedShell = shell->second;
          ++attached;
     }
     return attached;
}

Json::Value City3dOrchestrator::toJson(const City3dRunSummary& summary)
{
     Json::Value root(Json::objectValue);
     root["mode"] = summary.mode;
     root["eligible"] = static_cast<Json::UInt64>(summary.eligibleCount);
     root["accepted"] = static_cast<Json::UInt64>(summary.acceptedShells.size());
     root["total_ms"] = static_cast<Json::Int64>(summary.totalMs);
     if (!summary.skippedReason.empty()) root["skipped"] = summary.skippedReason;
     Json::Value& outcomes = root["buildings"];
     outcomes = Json::Value(Json::arrayValue);
     for (const City3dBuildingOutcome& outcome : summary.outcomes)
     {
          Json::Value entry(Json::objectValue);
          entry["building_id"] = outcome.buildingId;
          entry["route"] = outcome.route;
          entry["reason"] = outcome.reason;
          if (outcome.route != "not_eligible")
          {
               entry["points"] = static_cast<Json::UInt64>(outcome.points);
               entry["height_spread_m"] = outcome.heightSpreadMetres;
          }
          if (outcome.route == "attempted")
          {
               entry["accepted"] = outcome.accepted;
               entry["elapsed_ms"] = static_cast<Json::Int64>(outcome.elapsedMs);
               entry["worker_status"] = outcome.workerStatus;
               entry["roof_triangles"] = static_cast<Json::UInt64>(outcome.roofTriangles);
               entry["wall_triangles"] = static_cast<Json::UInt64>(outcome.wallTriangles);
               entry["worker_log_tail"] = outcome.logTail;
          }
          outcomes.append(entry);
     }
     return root;
}
