package com.cts.controller;


import com.cts.dto.LoginRequest;
import com.cts.service.AuthService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/auth")
public class AuthController {

    @Autowired
    private AuthService authService;

    // Admin Login
    @PostMapping("/admin-login")
    public String adminLogin(@RequestBody LoginRequest loginRequest) {
        if (authService.authenticateAdmin(loginRequest)) {
            return "Admin login successful!";
        } else {
            return "Invalid admin credentials!";
        }
    }

    // Member Login
    @PostMapping("/member-login")
    public String memberLogin(@RequestBody LoginRequest loginRequest) {
        if (authService.authenticateMember(loginRequest)) {
            return "Member login successful!";
        } else {
            return "Invalid member credentials!";
        }
    }
}


