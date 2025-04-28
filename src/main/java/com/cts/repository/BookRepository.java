package com.cts.repository;

import com.cts.model.Book;

import java.util.List;
import java.util.Optional;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface BookRepository extends JpaRepository<Book, Long> {
    boolean existsByIsbn(String isbn);

	List<Book> findByTitle(String title);

	List<Book> findByAuthor(String author);

	Optional<Book> findByIsbn(String isbn);

	List<Book> findByYearPublished(int year);

	List<Book> findByGenre(String genre);
}
