package com.depthwizard.backend.controller;

import com.depthwizard.backend.dto.HelloDTO;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {

    @GetMapping("/test")
    public HelloDTO sendHello() {
        return new HelloDTO("Hello world!");
    }

}