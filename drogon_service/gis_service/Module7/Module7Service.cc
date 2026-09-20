#include "Module7Service.h"

#include <exception>
#include <utility>

Module7Service::Module7Service(Config config)
    : qualityControlService_(
          std::move(config.qualityControl)
      ),
      rasterDerivativeService_(
          std::move(config.derivatives)
      )
{
}

Module7Service::Result Module7Service::execute(
    const GeoreferencedSurfaceBundle& surface,
    const BuildingCollection& buildings,
    const SemanticScene& semantics
) const
{
    Result result;

    /*
     * ------------------------------------------------------------
     * STEP 1
     * Scientific quality control
     * ------------------------------------------------------------
     */
    result.qualityReport =
        qualityControlService_.validate(
            surface,
            buildings,
            semantics
        );

    /*
     * FAIL = stop the Module 7 pipeline.
     *
     * WARN = continue, but preserve the warning in the report.
     *
     * This distinction is useful because a warning such as lower
     * confidence does not necessarily make the raster mathematically
     * unusable, whereas a failed surface identity check does.
     */
    if (result.qualityReport.status == QualityStatus::FAIL)
    {
        result.succeeded = false;

        result.failureReason =
            "Module 7 quality control failed. "
            "The surface is not cleared for downstream processing.";

        return result;
    }

    /*
     * ------------------------------------------------------------
     * STEP 2
     * Generate GIS derivative products
     * ------------------------------------------------------------
     */
    try
    {
        RasterProductSet products =
            rasterDerivativeService_.generate(
                surface
            );

        result.products =
            std::move(products);

        result.succeeded = true;
    }
    catch (const std::exception& ex)
    {
        result.succeeded = false;

        result.failureReason =
            std::string(
                "Module 7 raster derivative generation failed: "
            ) + ex.what();

        result.qualityReport.status =
            QualityStatus::FAIL;

        result.qualityReport.safeForAbsoluteOutput =
            false;

        result.qualityReport.violations.push_back(
            result.failureReason
        );
    }
    catch (...)
    {
        result.succeeded = false;

        result.failureReason =
            "Module 7 raster derivative generation failed "
            "with an unknown error.";

        result.qualityReport.status =
            QualityStatus::FAIL;

        result.qualityReport.safeForAbsoluteOutput =
            false;

        result.qualityReport.violations.push_back(
            result.failureReason
        );
    }

    return result;
}