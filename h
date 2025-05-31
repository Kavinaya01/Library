@PostMapping("/member")
public ResponseEntity<?> memberLogin(@RequestBody LoginRequest loginRequest) {
    Optional<Member> optionalMember = authService.getMemberByEmail(loginRequest.getEmail());

    if (optionalMember.isPresent()) {
        Member member = optionalMember.get();

        if (passwordEncoder.matches(loginRequest.getPassword(), member.getPassword())) {
            loginService.saveLogin(member.getMemberId(), member.getEmail(), "MEMBER");

            // ✅ ADD THIS: include name in token payload
            String token = jwtUtil.generateToken(member.getEmail(), "ROLE_MEMBER", member.getName());

            return ResponseEntity.ok(new AuthResponse(token,"MEMBER"));
        }
    }

    return ResponseEntity.status(HttpStatus.UNAUTHORIZED).body("Invalid member credentials!");
}

public String generateToken(String email, String role, String memberName) {
    Map<String, Object> claims = new HashMap<>();
    claims.put("role", role);
    claims.put("memberName", memberName); // 👈 included in JWT payload
    return createToken(claims, email);
}
