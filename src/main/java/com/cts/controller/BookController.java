package com.cts.controller;

import com.cts.dto.BookRequest;
import com.cts.model.Book;
import com.cts.service.BookService;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/books")
public class BookController {

    @Autowired
    private BookService bookService;
    
    @PostMapping("/add")
    public String addBook(@RequestBody BookRequest book) {
    	return bookService.addBook(book);
    }

    @GetMapping("/all")
    public List<Book> listAllBooks() {
        return bookService.getAllBooks();
    }

    @DeleteMapping("/delete/{id}")
    public String deleteBook(@PathVariable Long id) {
        return bookService.deleteBookById(id);
    }

    @GetMapping("/isbn/{isbn}")
    public Optional<Book> getBookByIsbn(@PathVariable String isbn) {
        return bookService.getBookByIsbn(isbn);
    }

    @GetMapping("/author/{author}")
    public List<Book> getBooksByAuthor(@PathVariable String author) {
        return bookService.getBooksByAuthor(author);
    }

    @GetMapping("/title/{title}")
    public List<Book> getBooksByTitle(@PathVariable String title) {
        return bookService.getBooksByTitle(title);
    }

    @GetMapping("/year/{year}")
    public List<Book> getBooksByYearPublished(@PathVariable int year) {
        return bookService.getBooksByYearPublished(year);
    }

    @GetMapping("/genre/{genre}")
    public List<Book> getBooksByGenre(@PathVariable String genre) {
        return bookService.getBooksByGenre(genre);
    }
}
