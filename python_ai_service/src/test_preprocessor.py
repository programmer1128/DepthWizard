import os
import numpy as np
import rasterio

from tensor_preprocessor import TensorPreprocessor


INPUT_FILE = "new.tif"
OUTPUT_DIR = "outputs"


def save_outputs():

    os.makedirs(OUTPUT_DIR, exist_ok=True)

    # =========================================================
    # RUN YOUR EXISTING PREPROCESSOR
    # =========================================================

    preprocessor = TensorPreprocessor()

    tensor, metadata = preprocessor.process(INPUT_FILE)

    print("\n========== PREPROCESSING ==========")
    print("Input:", INPUT_FILE)
    print("Tensor shape:", tensor.shape)
    print("Tensor dtype:", tensor.dtype)

    # =========================================================
    # CONVERT MODEL TENSOR BACK TO IMAGE FORMAT
    # =========================================================
    #
    # tensor:
    # [1, 3, H, W]
    #
    # TIFF:
    # [3, H, W]
    #
    # Your TensorPreprocessor has already converted the image
    # into the format expected by the model.
    #
    # We save the actual 3-channel processed data as TIFF.
    # =========================================================

    depth_input = tensor.squeeze(0).numpy()

    # If tensor is normalized floating point,
    # convert it safely to uint8 for TIFF storage.

    depth_input = depth_input.astype(np.float32)

    output_channels = []

    for channel in range(3):

        band = depth_input[channel]

        valid = np.isfinite(band)

        output = np.zeros(
            band.shape,
            dtype=np.uint8
        )

        if np.any(valid):

            values = band[valid]

            low = values.min()
            high = values.max()

            if high > low:

                normalized = (
                    (band[valid] - low)
                    / (high - low)
                    * 255.0
                )

                output[valid] = np.clip(
                    normalized,
                    0,
                    255
                ).astype(np.uint8)

        output_channels.append(output)

    depth_input = np.stack(
        output_channels,
        axis=0
    )

    # =========================================================
    # CREATE new_depth_input.tif
    # =========================================================

    depth_tif = os.path.join(
        OUTPUT_DIR,
        "new_depth_input.tif"
    )

    height = depth_input.shape[1]
    width = depth_input.shape[2]

    with rasterio.open(
        depth_tif,
        "w",
        driver="GTiff",
        width=width,
        height=height,
        count=3,
        dtype="uint8"
    ) as dst:

        dst.write(depth_input)

    # =========================================================
    # CREATE new_metadata.tif
    # =========================================================
    #
    # The original GeoTIFF metadata is preserved here.
    # We use a tiny 1-band raster as the payload.
    #
    # The important part is the CRS + transform.
    # =========================================================

    metadata_tif = os.path.join(
        OUTPUT_DIR,
        "new_metadata.tif"
    )

    with rasterio.open(INPUT_FILE) as src:

        profile = src.profile.copy()

        profile.update(
            driver="GTiff",
            count=1,
            dtype="uint8"
        )

        with rasterio.open(
            metadata_tif,
            "w",
            **profile
        ) as dst:

            # Dummy raster data.
            # Metadata is the important part.
            dummy = np.zeros(
                (src.height, src.width),
                dtype=np.uint8
            )

            dst.write(
                dummy,
                1
            )

            dst.set_band_description(
                1,
                "Metadata reference"
            )

    # =========================================================
    # DONE
    # =========================================================

    print("\n========== OUTPUTS ==========")

    print("\nDepth Anything V2 input:")
    print(depth_tif)

    print("\nMetadata GeoTIFF:")
    print(metadata_tif)

    print("\nTensor originally produced:")
    print("Shape:", tensor.shape)
    print("Dtype:", tensor.dtype)


if __name__ == "__main__":
    save_outputs()