import rasterio
import numpy as np

file_path = "new.tif"

with rasterio.open(file_path) as src:

    for band_number in range(1, src.count + 1):

        band = src.read(band_number)

        print(f"\nBand {band_number}")
        print("Shape:", band.shape)
        print("Data type:", band.dtype)
        print("Minimum:", band.min())
        print("Maximum:", band.max())
        print("Mean:", band.mean())