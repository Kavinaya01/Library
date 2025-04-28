package com.cts.service;

import com.cts.dto.BookRequest;
import com.cts.model.Book;
import com.cts.model.AvailableCopies;
import com.cts.repository.BookRepository;
import com.cts.repository.AvailableCopiesRepository;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class BookService {

    @Autowired
    private BookRepository bookRepository;

    @Autowired
    private AvailableCopiesRepository availableCopiesRepository;

    public String addBook(BookRequest request) {
        if (bookRepository.existsByIsbn(request.getIsbn())) {
            AvailableCopies availableCopies = availableCopiesRepository.findById(request.getIsbn()).orElse(null);
            if (availableCopies != null) {
                availableCopies.setCount(availableCopies.getCount() + 1);
                availableCopiesRepository.save(availableCopies);
                return "Book already exists. Incremented available copies count.";
            }
        } else {
            Book book = new Book();
            book.setTitle(request.getTitle());
            book.setAuthor(request.getAuthor());
            book.setGenre(request.getGenre());
            book.setIsbn(request.getIsbn());
            book.setYearPublished(request.getYearPublished());

            bookRepository.save(book);

            AvailableCopies availableCopies = new AvailableCopies();
            availableCopies.setIsbn(request.getIsbn());
            availableCopies.setCount(1); // Initialize count to 1 for new book

            availableCopiesRepository.save(availableCopies);
            return "Book added successfully!";
        }
        return "Error adding book.";
    }

    public List<Book> getAllBooks() {
        return bookRepository.findAll();
    }

    public String deleteBookById(Long id) {
        Optional<Book> bookOptional = bookRepository.findById(id);
        if (bookOptional.isPresent()) {
            bookRepository.deleteById(id);
            return "Book deleted successfully!";
        } else {
            return "Book not found!";
        }
    }

    public Optional<Book> getBookByIsbn(String isbn) {
        return bookRepository.findByIsbn(isbn);
    }

    public List<Book> getBooksByAuthor(String author) {
        return bookRepository.findByAuthor(author);
    }

    public List<Book> getBooksByTitle(String title) {
        return bookRepository.findByTitle(title);
    }

    public List<Book> getBooksByYearPublished(int year) {
        return bookRepository.findByYearPublished(year);
    }

    public List<Book> getBooksByGenre(String genre) {
        return bookRepository.findByGenre(genre);
    }
}
