package com.depthwizard.backend.storage;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.MalformedURLException;
import java.nio.file.*;
import java.util.Objects;
import java.util.stream.Stream;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.Resource;
import org.springframework.core.io.UrlResource;
import org.springframework.stereotype.Service;
import org.springframework.util.FileSystemUtils;
import org.springframework.web.multipart.MultipartFile;

@Service
public class FileSystemStorageService implements StorageService {

    private final Path rootLocation;
    private static final Logger log = LoggerFactory.getLogger(FileSystemStorageService.class);

    @Autowired
    public FileSystemStorageService(StorageProperties properties) {

        if (properties.getLocation().trim().isEmpty()) {
            throw new StorageException("File upload location can not be Empty.");
        }

        this.rootLocation = Paths.get(properties.getLocation());
    }

    @Override
    public void store(MultipartFile file) {
        try {
            if (file.isEmpty()) {
                throw new StorageException("Failed to store empty file.");
            }
            Path destinationFile = this.rootLocation.resolve(
                            Paths.get(Objects.requireNonNull(file.getOriginalFilename())))
                    .normalize().toAbsolutePath();
            if (!destinationFile.getParent().equals(this.rootLocation.toAbsolutePath())) {
                // This is a security check
                throw new StorageException(
                        "Cannot store file outside current directory.");
            }
            try (InputStream inputStream = file.getInputStream()) {
                Files.copy(inputStream, destinationFile,
                        StandardCopyOption.REPLACE_EXISTING);
            }
        } catch (IOException e) {
            throw new StorageException("Failed to store file.", e);
        }
    }

    public void storeChunk(MultipartFile chunk, int chunkIndex, int totalChunks, String fileName, String uploadId) {
        try {
            Path tempDir = this.rootLocation.resolve("temp_" + uploadId);
            if (!Files.exists(tempDir)) {
                Files.createDirectories(tempDir);
            }

            // Save chunk with its index name (e.g., chunk_0, chunk_1)
            Path chunkPath = tempDir.resolve("chunk_" + chunkIndex);
            Files.copy(chunk.getInputStream(), chunkPath, StandardCopyOption.REPLACE_EXISTING);
            log.info("Saved chunk_{} in {}", chunkIndex, tempDir);
            // Check if this is the last chunk (or if all chunks are present)
            assembleFileIfComplete(tempDir, fileName, totalChunks);
        } catch (IOException e) {
            throw new StorageException("Failed to store chunk", e);
        }
    }

    private void assembleFileIfComplete(Path tempDir, String fileName, int totalChunks) throws IOException {
        // Verify all chunks are uploaded
        for (int i = 0; i < totalChunks; i++) {
            if (!Files.exists(tempDir.resolve("chunk_" + i))) {
                return; // Not all chunks have arrived yet
            }
        }

        // All chunks are here! Stitch them together.
        log.info("Starting file assembly...");
        Path finalDestination = this.rootLocation.resolve(fileName);
        try (OutputStream out = Files.newOutputStream(finalDestination, StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING)) {
            for (int i = 0; i < totalChunks; i++) {
                Path chunkPath = tempDir.resolve("chunk_" + i);
                Files.copy(chunkPath, out);
                log.info("Copied chunk_{} to {}", i, finalDestination);
                Files.delete(chunkPath); // Clean up individual chunk
            }
        }

        // Delete the temporary staging directory
        Files.delete(tempDir);
        log.info("Copying done, temp dir deleted");
    }

    @Override
    public Stream<Path> loadAll() {
        try {
            return Files.walk(this.rootLocation, 1)
                    .filter(path -> !path.equals(this.rootLocation))
                    .map(this.rootLocation::relativize);
        } catch (IOException e) {
            throw new StorageException("Failed to read stored files", e);
        }

    }

    @Override
    public Path load(String filename) {
        return rootLocation.resolve(filename);
    }

    @Override
    public Resource loadAsResource(String filename) {
        try {
            Path file = load(filename);
            Resource resource = new UrlResource(file.toUri());
            if (resource.exists() || resource.isReadable()) {
                return resource;
            } else {
                throw new StorageFileNotFoundException(
                        "Could not read file: " + filename);

            }
        } catch (MalformedURLException e) {
            throw new StorageFileNotFoundException("Could not read file: " + filename, e);
        }
    }

    @Override
    public void deleteAll() {
        FileSystemUtils.deleteRecursively(rootLocation.toFile());
    }

    @Override
    public void init() {
        try {
            Files.createDirectories(rootLocation);
        } catch (IOException e) {
            throw new StorageException("Could not initialize storage", e);
        }
    }
}
