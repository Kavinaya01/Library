availableBooks: any[] = [];

fetchBooks() {
  this.bookService.getAllBooks(0).subscribe((data) => {
    const bookMap = new Map();

    data.content.forEach((book: any) => {
      if (bookMap.has(book.title)) {
        bookMap.get(book.title).availableCopies++;
      } else {
        bookMap.set(book.title, {
          id: book.id,
          title: book.title,
          isbn: book.isbn,
          author: book.author,
          genre: book.genre,
          yearPublished: book.yearPublished,
          availableCopies: 1,
        });
      }
    });

    // Set filteredBooks and availableBooks arrays
    this.filteredBooks = Array.from(bookMap.values());
    this.availableBooks = this.filteredBooks.filter(b => b.availableCopies > 0);
  });
}
