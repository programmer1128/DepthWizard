# from PIL import Image
# from transformers import AutoImageProcessor
# import rasterio
# import numpy as np


# class TensorPreprocessor:

#     def __init__(self):
#         self.processor = AutoImageProcessor.from_pretrained(
#             "depth-anything/Depth-Anything-V2-Small-hf"
#         )

#     def read_image(self, file_path):

#         metadata = None

#         if file_path.lower().endswith((".tif", ".tiff")):

#             with rasterio.open(file_path) as src:

#                 # Read first 3 bands
#                 bands = src.read([1, 2, 3])

#                 # Save geospatial metadata
#                 metadata = {
#                     "crs": src.crs,
#                     "transform": src.transform,
#                     "bounds": src.bounds,
#                     "width": src.width,
#                     "height": src.height,
#                     "resolution": src.res,
#                 }

#             # (3,H,W) → (H,W,3)
#             rgb = np.transpose(bands, (1, 2, 0))

#             # uint16 → 0-255 RGB
#             rgb = rgb.astype(np.float32)

#             min_val = rgb.min()
#             max_val = rgb.max()

#             if max_val > min_val:
#                 rgb = (rgb - min_val) / (max_val - min_val)

#             rgb = (rgb * 255).astype(np.uint8)

#             image = Image.fromarray(rgb)

#         else:

#             image = Image.open(file_path).convert("RGB")

#         return image, metadata

#     def normalize_to_4d_tensor(self, image):

#         inputs = self.processor(
#             images=image,
#             return_tensors="pt"
#         )

#         return inputs["pixel_values"]

#     def process(self, file_path):

#         image, metadata = self.read_image(file_path)

#         tensor = self.normalize_to_4d_tensor(image)

#         return tensor, metadata


from PIL import Image
from transformers import AutoImageProcessor
import rasterio
from rasterio.enums import ColorInterp
import numpy as np


class TensorPreprocessor:

    def __init__(self):
        self.processor = AutoImageProcessor.from_pretrained(
            "depth-anything/Depth-Anything-V2-Small-hf"
        )

    def read_image(self, file_path):
        """
        Reads JPG/PNG or GeoTIFF and returns:

            image     -> PIL RGB image
            metadata  -> GeoTIFF metadata or None

        Every input reaching Depth Anything is converted to
        exactly 3 channels: RGB.
        """

        # ---------------------------------------------------------
        # JPG / PNG / normal image
        # ---------------------------------------------------------

        if not file_path.lower().endswith((".tif", ".tiff")):

            image = Image.open(file_path).convert("RGB")

            return image, None

        # ---------------------------------------------------------
        # GeoTIFF
        # ---------------------------------------------------------

        with rasterio.open(file_path) as src:

            metadata = {
                "crs": src.crs,
                "transform": src.transform,
                "bounds": src.bounds,
                "width": src.width,
                "height": src.height,
                "resolution": src.res,
                "count": src.count,
                "dtype": src.dtypes,
                "nodata": src.nodata,
                "descriptions": src.descriptions,
            }

            band_count = src.count

            # -----------------------------------------------------
            # 1 BAND
            # -----------------------------------------------------
            if band_count == 1:

                band = src.read(1)

                # Make grayscale → RGB
                rgb = np.stack(
                    [band, band, band],
                    axis=-1
                )

            # -----------------------------------------------------
            # 2 BANDS
            # -----------------------------------------------------
            elif band_count == 2:

                bands = src.read([1, 2])

                # Use band 1 as R
                # band 2 as G
                # average them for B
                rgb = np.stack(
                    [
                        bands[0],
                        bands[1],
                        (bands[0].astype(np.float32)
                         + bands[1].astype(np.float32)) / 2
                    ],
                    axis=-1
                )

            # -----------------------------------------------------
            # 3 BANDS
            # -----------------------------------------------------
            elif band_count == 3:

                bands = src.read([1, 2, 3])

                rgb = np.transpose(
                    bands,
                    (1, 2, 0)
                )

            # -----------------------------------------------------
            # 4+ BANDS
            # -----------------------------------------------------
            else:

                rgb_bands = self._find_rgb_bands(src)

                bands = src.read(rgb_bands)

                rgb = np.transpose(
                    bands,
                    (1, 2, 0)
                )

        # ---------------------------------------------------------
        # Normalize to uint8 RGB
        # ---------------------------------------------------------

        rgb = self._normalize_rgb(rgb)

        image = Image.fromarray(rgb, mode="RGB")

        return image, metadata

    # =============================================================
    # FIND RGB BANDS
    # =============================================================

    def _find_rgb_bands(self, src):
        """
        Find Red, Green and Blue bands using GeoTIFF metadata.

        Returns:
            [red_band, green_band, blue_band]
        """

        # ---------------------------------------------------------
        # First: check Rasterio color interpretation
        # ---------------------------------------------------------

        color_interpretations = src.colorinterp

        red = None
        green = None
        blue = None

        for index, interpretation in enumerate(
            color_interpretations,
            start=1
        ):

            if interpretation == ColorInterp.red:
                red = index

            elif interpretation == ColorInterp.green:
                green = index

            elif interpretation == ColorInterp.blue:
                blue = index

        if red and green and blue:
            return [red, green, blue]

        # ---------------------------------------------------------
        # Second: check band descriptions
        # ---------------------------------------------------------

        descriptions = src.descriptions

        for index, description in enumerate(
            descriptions,
            start=1
        ):

            if description is None:
                continue

            name = description.lower()

            if red is None and "red" in name:
                red = index

            if green is None and "green" in name:
                green = index

            if blue is None and "blue" in name:
                blue = index

        if red and green and blue:
            return [red, green, blue]

        # ---------------------------------------------------------
        # Fallback
        # ---------------------------------------------------------

        raise ValueError(
            f"GeoTIFF contains {src.count} bands, but RGB bands "
            "could not be identified from the GeoTIFF metadata. "
            "Provide an RGB band mapping for this dataset."
        )

    # =============================================================
    # NORMALIZATION
    # =============================================================

    def _normalize_rgb(self, rgb):
        """
        Convert arbitrary numeric raster values to uint8 RGB.

        Invalid values such as NaN and Inf are replaced with 0.
        Each channel is independently stretched using the
        2nd–98th percentile.
        """

        rgb = rgb.astype(np.float32)

        output = np.zeros_like(rgb, dtype=np.uint8)

        for channel in range(3):

            band = rgb[:, :, channel]

            valid = np.isfinite(band)

            if not np.any(valid):
                continue

            values = band[valid]

            low = np.percentile(values, 2)
            high = np.percentile(values, 98)

            # Start with zeros so NaN/Inf remain 0
            normalized = np.zeros_like(band, dtype=np.float32)

            if high > low:

                valid_pixels = np.clip(
                    band[valid],
                    low,
                    high
                )

                normalized[valid] = (
                    (valid_pixels - low)
                    / (high - low)
                    * 255.0
                )

            output[:, :, channel] = np.clip(
                normalized,
                0,
                255
            ).astype(np.uint8)

        return output

    # =============================================================
    # IMAGE → 4D TENSOR
    # =============================================================

    def normalize_to_4d_tensor(self, image):

        inputs = self.processor(
            images=image,
            return_tensors="pt"
        )

        return inputs["pixel_values"]

    # =============================================================
    # COMPLETE PROCESSING
    # =============================================================

    def process(self, file_path):

        image, metadata = self.read_image(file_path)

        tensor = self.normalize_to_4d_tensor(image)

        return tensor, metadata