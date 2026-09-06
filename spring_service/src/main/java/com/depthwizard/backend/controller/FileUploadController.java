package com.depthwizard.backend.controller;

import com.depthwizard.backend.dto.MessageDTO;
import com.depthwizard.backend.storage.StorageFileNotFoundException;
import com.depthwizard.backend.storage.StorageService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

@Controller
@CrossOrigin("*")
public class FileUploadController {
    private final StorageService storageService;

    @Autowired
    public FileUploadController(StorageService storageService) {
        this.storageService = storageService;
    }

    @PostMapping("/chunk")
    public ResponseEntity<MessageDTO> uploadChunk(
            @RequestParam("file") MultipartFile chunk,
            @RequestParam("chunkIndex") int chunkIndex,
            @RequestParam("totalChunks") int totalChunks,
            @RequestParam("fileName") String fileName,
            @RequestParam("uploadId") String uploadId) {

        try {
            storageService.storeChunk(chunk, chunkIndex, totalChunks, fileName, uploadId);
            return ResponseEntity.ok(new MessageDTO("Chunk " + chunkIndex + " received."));
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR)
                    .body(new MessageDTO("Failed to upload chunk: " + e.getMessage()));
        }
    }
    @ExceptionHandler(StorageFileNotFoundException.class)
    public ResponseEntity<?> handleStorageFileNotFound(StorageFileNotFoundException exc) {
        return ResponseEntity.notFound().build();
    }
}
