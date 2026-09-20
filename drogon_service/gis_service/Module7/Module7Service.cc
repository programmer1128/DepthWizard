#include "Module7Service.h"

#include <exception>
#include <utility>

Module7Service::Module7Service(Config config)
    : qualityControlService_(std::move(config.qualityControl)),
      rasterDerivativeService_(std::move(config.derivatives))
{
}

Module7Service::Result Module7Service::execute(
    const SurfaceBundle& surface,
    const BuildingCollection& buildings,
    const SemanticScene* semanticScene
) const
{
    Result result;

    /*
     * ------------------------------------------------------------
     * STEP 1: Scientific Quality Control
     * ------------------------------------------------------------
     *
     * Module 7 is a checkpoint.
     *
     * We do not generate the final analytical products when
     * the surface fails its physical consistency checks.
     */
    result.qualityReport =
        qualityControlService_.validate(
            surface,
            buildings,
            semanticScene
        );

    if (!result.qualityReport.passed)
    {
        result.succeeded = false;

        result.failureReason =
            "Module 7 quality control failed. "
            "Surface is not cleared for downstream metric processing.";

        return result;
    }

    /*
     * ------------------------------------------------------------
     * STEP 2: Raster Derivative Generation
     * ------------------------------------------------------------
     */
    try
    {
        RasterProductSet products =
            rasterDerivativeService_.generate(surface);

        result.products = std::move(products);
        result.succeeded = true;
    }
    catch (const std::exception& ex)
    {
        result.succeeded = false;

        result.failureReason =
            std::string(
                "Raster derivative generation failed: "
            ) + ex.what();

        result.qualityReport.errors.push_back(
            result.failureReason
        );
    }
    catch (...)
    {
        result.succeeded = false;

        result.failureReason =
            "Raster derivative generation failed with "
            "an unknown error.";

        result.qualityReport.errors.push_back(
            result.failureReason
        );
    }

    return result;
}