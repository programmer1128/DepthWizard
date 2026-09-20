#pragma once

#include "../QualityControl/QualityControlService.h"
#include "../RasterDerivatives/RasterDerivativeService.h"
#include "../structures/Module7Types.h"

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
        bool succeeded = false;

        QualityReport qualityReport;

        /*
         * Products only exist when QC passes and derivative
         * generation succeeds.
         */
        std::optional<RasterProductSet> products;

        std::string failureReason;
    };

    explicit Module7Service(Config config = Config{});

    Result execute(
        const SurfaceBundle& surface,
        const BuildingCollection& buildings,
        const SemanticScene* semanticScene = nullptr
    ) const;

private:
    QualityControlService qualityControlService_;
    RasterDerivativeService rasterDerivativeService_;
};