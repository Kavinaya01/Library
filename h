
    @PreAuthorize("hasAuthority('ADMIN')")
    @DeleteMapping("/delete/{id}")
    public ResponseEntity<Map<String, String>> deleteBook(@PathVariable Long id) {
        String message = bookService.deleteBookById(id);
        Map<String, String> response = new HashMap<>();
        response.put("message", message);
        return ResponseEntity.ok(response); // ✅ Ensure response is valid JSON
    }
   public String deleteBookById(Long id) {
        log.info("Attempting to delete book with ID '{}'", id);

        Optional<Book> bookOptional = bookRepository.findById(id);
        if (bookOptional.isEmpty()) {
            log.warn("Book with ID '{}' not found", id);
            return "Book not found!";
        }

        Book book = bookOptional.get();
        String isbn = book.getIsbn();

        // ✅ Check if the book is available before deleting
        if (!book.getStatus().equalsIgnoreCase("available")) {
            log.warn("Book '{}' cannot be deleted as it is currently borrowed.", book.getTitle());
            return "Book cannot be deleted because it is currently borrowed.";
        }

        // ✅ Get count of available books with the same ISBN
        List<Book> availableBooksWithSameIsbn = bookRepository.findByIsbnAndStatus(isbn, "available");

        // ✅ If only **one** copy is available, delete it fully
        if (availableBooksWithSameIsbn.size() == 1) {
            availableCopiesRepository.findByIsbn(isbn).ifPresent(availableCopies -> {
                availableCopiesRepository.delete(availableCopies);
                log.info("Deleted available copies entry for ISBN '{}'", isbn);
            });

            bookRepository.deleteById(id);
            log.info("Book '{}' deleted successfully!", book.getTitle());
            return "Book deleted successfully!";
        } else {
            // ✅ If multiple available copies exist, just reduce count
            availableCopiesRepository.findByIsbn(isbn).ifPresent(availableCopies -> {
                availableCopies.setCount(availableCopies.getCount() - 1);
                availableCopiesRepository.save(availableCopies);
                log.info("Decreased available copies count for ISBN '{}'. Remaining copies: {}", isbn, availableCopies.getCount());
            });

            bookRepository.deleteById(id);
            log.info("One available copy of '{}' deleted, but other copies remain.", book.getTitle());
            return "One available copy deleted, but other copies remain.";
        }
    }
  deleteBook(id: number) {
    this.bookService.deleteBook(id).subscribe({
      next: (response) => {
        if (response.message.includes("cannot be deleted")) {
          alert(response.message);  // ✅ Show alert if book is borrowed
        } else {
          console.log("Book deleted successfully:", response.message);
          alert(response.message);
          this.fetchBooks(); // ✅ Refresh book list after successful deletion
        }
      },
      error: (err) => {
        console.error("Error deleting book:", err);
        alert("Failed to delete book since Book has been Borrowed");
      }
    });
  } deleteBook(id: number): Observable<any> {
    const token = localStorage.getItem("jwtToken");
    const headers = new HttpHeaders().set("Authorization", `Bearer ${token}`);
  
    return this.http.delete(`${this.baseUrl}/delete/${id}`, { headers }).pipe(
      catchError((error) => {
        console.error("Error deleting book:", error);
        return throwError(() => new Error("Failed to delete book"));
      })
    );
  }
