package com.cts.model;

import jakarta.persistence.*;
import lombok.*;

@Entity
@Table(name = "available_copies")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class AvailableCopies {

    @Id
    @Column(unique = true)
    private String isbn;

    private int count;
}
