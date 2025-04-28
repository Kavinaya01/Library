package com.cts.dto;

import lombok.*;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class BookRequest {
    private String title;
    private String author;
    private String genre;
    private String isbn;
    private int yearPublished;
    private int availableCopies;
}
