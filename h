// Overloaded method to include memberName in the token
public String generateToken(String email, String role, String memberName) {
    Key key = Keys.hmacShaKeyFor(Decoders.BASE64.decode(secret));
    return Jwts.builder()
            .setSubject(email)
            .claim("role", role)
            .claim("memberName", memberName) // 👈 Add memberName to payload
            .setIssuedAt(new Date())
            .setExpiration(new Date(System.currentTimeMillis() + expirationTime))
            .signWith(key, SignatureAlgorithm.HS256)
            .compact();
}
