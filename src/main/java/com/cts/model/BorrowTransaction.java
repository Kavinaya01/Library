package com.cts.model;

import java.util.Date;

import jakarta.persistence.Entity;
import jakarta.persistence.Table;

@Entity
@Table(name="borrow")
public class BorrowTransaction {
	private int borrow_id;
	private Book book_id;
	private Member member_id;
	private Date borrow_date;
	private Date return_date;
	private String borrow_status;
}
