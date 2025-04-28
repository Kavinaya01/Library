package com.cts.repository;


import com.cts.model.AvailableCopies;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface AvailableCopiesRepository extends JpaRepository<AvailableCopies, String> {
}
