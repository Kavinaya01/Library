@PutMapping("/books/update/{id}")
public ResponseEntity<Map<String, String>> updateBook(@PathVariable Long id, @RequestBody Book book) {
    // update logic here
    Map<String, String> response = new HashMap<>();
    response.put("message", "Book updated successfully!");
    return ResponseEntity.ok(response);
}
