package com.depthwizard.backend.controller;

import com.depthwizard.backend.dto.MessageDTO;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {

    @GetMapping("/test")
    public MessageDTO sendHello() {
        return new MessageDTO("Hello world!");
    }

}