package com.cts.controller;

import com.cts.dto.LoginRequest;
import com.cts.dto.MemberRequest;
import com.cts.dto.AuthResponse;
import com.cts.model.Admin;
import com.cts.model.Member;
import com.cts.security.JwtTokenUtil;
import com.cts.service.AuthService;
import com.cts.service.LoginService;
import com.cts.service.MemberService;

import lombok.extern.slf4j.Slf4j;

import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.*;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.web.bind.annotation.*;

@Slf4j
@RestController
@CrossOrigin(origins = "http://localhost:4200")
@RequestMapping("/login")
public class AuthController {

    @Autowired
    private AuthService authService;

    @Autowired
    private LoginService loginService;
    @Autowired
    private MemberService memberService;

    @Autowired
    private JwtTokenUtil jwtUtil;

    @Autowired
    private PasswordEncoder passwordEncoder;

    @PostMapping("/admin")
    public ResponseEntity<?> adminLogin(@RequestBody LoginRequest loginRequest) {
        Admin admin = authService.getAdminByEmail(loginRequest.getEmail());

        if (admin != null && passwordEncoder.matches(loginRequest.getPassword(), admin.getPassword())) {
            loginService.saveLogin(admin.getAdminId(), admin.getEmail(), "ADMIN");
            String token = jwtUtil.generateToken(admin.getEmail(), "ROLE_ADMIN");
            return ResponseEntity.ok(new AuthResponse(token,"ADMIN"));
        } else {
            return ResponseEntity.status(HttpStatus.UNAUTHORIZED).body("Invalid admin credentials!");
        }
    }

    @PostMapping("/member")
    public ResponseEntity<?> memberLogin(@RequestBody LoginRequest loginRequest) {
        Optional<Member> optionalMember = authService.getMemberByEmail(loginRequest.getEmail());

        if (optionalMember.isPresent()) {
            Member member = optionalMember.get();

            if (passwordEncoder.matches(loginRequest.getPassword(), member.getPassword())) {
                loginService.saveLogin(member.getMemberId(), member.getEmail(), "MEMBER");
                String token = jwtUtil.generateToken(member.getEmail(), "ROLE_MEMBER");
                return ResponseEntity.ok(new AuthResponse(token,"MEMBER"));
            }
        }

        return ResponseEntity.status(HttpStatus.UNAUTHORIZED).body("Invalid member credentials!");
    }

    @PostMapping("/register")
    public ResponseEntity<?> registerMember(@RequestBody MemberRequest memberDTO) {
        log.info("Registering member with email '{}'", memberDTO.getEmail());

        // Encrypt the password before saving
        memberDTO.setPassword(passwordEncoder.encode(memberDTO.getPassword()));

        Member registeredMember = memberService.registerMember(memberDTO);
        return ResponseEntity.status(HttpStatus.CREATED).body(registeredMember);
    }
    

}
//baarathi
