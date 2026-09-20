#pragma once

#include "../QualityControl/QualityControlService.h"
#include "../RasterDerivatives/RasterDerivativeService.h"
#include "../structures/ExportStructs.h"
#include "../structures/InferenceStructs.h"
#include "../structures/SurfaceStructs.h"

#include <optional>
#include <string>

class Module7Service
{
public:

    struct Config
    {
        QualityControlService::Config qualityControl;
        RasterDerivativeService::Config derivatives;
    };

    struct Result
    {
        /*
         * true means Module 7 completed successfully.
         *
         * A QC WARN does not stop derivative generation.
         * A QC FAIL does.
         */
        bool succeeded{false};

        QualityReport qualityReport;

        /*
         * Present only when QC did not fail and derivative
         * generation completed.
         */
        std::optional<RasterProductSet> products;

        std::string failureReason;
    };

    explicit Module7Service(
        Config config = Config{}
    );

    Result execute(
        const GeoreferencedSurfaceBundle& surface,
        const BuildingCollection& buildings,
        const SemanticScene& semantics
    ) const;

private:

    QualityControlService qualityControlService_;
    RasterDerivativeService rasterDerivativeService_;
};