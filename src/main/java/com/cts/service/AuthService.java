package com.cts.service;


import com.cts.dto.LoginRequest;
import com.cts.model.Member;
import com.cts.repository.MemberRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class AuthService {

    private static final String ADMIN_EMAIL = "admin@example.com";
    private static final String ADMIN_PASSWORD = "admin123";

    @Autowired
    private MemberRepository memberRepository;

    // Admin Login
    public boolean authenticateAdmin(LoginRequest loginRequest) {
        return ADMIN_EMAIL.equals(loginRequest.getEmail()) && ADMIN_PASSWORD.equals(loginRequest.getPassword());
    }

    // Member Login
    public boolean authenticateMember(LoginRequest loginRequest) {
        Member member = memberRepository.findByEmail(loginRequest.getEmail());
        if (member != null && member.getPassword().equals(loginRequest.getPassword())) {
            return true;
        }
        return false;
    }
}


