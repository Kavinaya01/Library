import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { catchError, Observable, throwError } from 'rxjs';
import { tap } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class BorrowService {
  private apiUrl = '/borrow';

  constructor(private http: HttpClient) {}
  borrowBook(title: string, memberName: string): Observable<any> {
    return this.http.post(`${this.apiUrl}/${title}/${memberName}`, {}, {
      headers: { 'Content-Type': 'application/json' } // ✅ Ensure JSON format
    }).pipe(
      catchError(error => {
        console.error('Borrow Service Error:', error); // ✅ Log error
        return throwError(() => new Error(error.error?.message || 'Unknown error'));
      })
    );
  }
  
}


import { Component } from '@angular/core';
import { BookService } from '../../../service/book/book.service';
import { Router } from '@angular/router';
import { AuthService } from '../../../service/auth/auth.service';
import { BorrowService } from '../../../service/borrowBooks/borrow.service';
@Component({
  selector: 'app-view-books',
  standalone: false,
  templateUrl: './view-books.component.html',
  styleUrl: './view-books.component.css'
})
export class ViewBooksComponent {
   books: any[] = [];
    filteredBooks: any[] = [];
    
    searchQuery: string = '';
    selectedCategory: string = 'title'; 
    selectedGenre: string = '';  
    selectedAuthor: string = ''; 
    currentPage: number = 0;
  
    genres: string[] = [];
    authors: string[] = [];
  
    bookForm = {
      id: null,
      title: '',
      author: '',
      genre: '',
      isbn: '',
      yearPublished: '',
    };
  
    constructor(private authService: AuthService,private bookService: BookService,private borrowService:BorrowService, private router : Router) {}
    
    ngOnInit() {
      this.fetchBooks();
    }
  
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
              author: book.author,
              genre: book.genre,
              isbn: book.isbn,
              yearPublished: book.yearPublished,
              availableCopies: book.status === 'available' ? 1 : 0,
              isFlipped: false,
            });
          }
        });
  
        this.books = Array.from(bookMap.values());
        this.filteredBooks = this.books; 
  
        this.genres = [...new Set(this.books.map(book => book.genre))];
        this.authors = [...new Set(this.books.map(book => book.author))];
      });
    }
  
    filterBooks() {
      this.filteredBooks = this.books.filter((book) => {
        const matchesSearch = book[this.selectedCategory]?.toLowerCase().includes(this.searchQuery.toLowerCase());
        const matchesGenre = this.selectedGenre === '' || book.genre === this.selectedGenre;
        const matchesAuthor = this.selectedAuthor === '' || book.author === this.selectedAuthor;
        return matchesSearch && matchesGenre && matchesAuthor;
      });
    }
  
    toggleFlip(book: any) {
      book.isFlipped = !book.isFlipped;
    }
  
  
    searchBooks() {
      switch (this.selectedCategory) {
        case 'isbn':
          this.bookService.getBookByIsbn(this.searchQuery, this.currentPage).subscribe(data => this.books = data.content);
          break;
        case 'author':
          this.bookService.getBooksByAuthor(this.searchQuery, this.currentPage).subscribe(data => this.books = data.content);
          break;
        case 'title':
          this.bookService.getBooksByTitle(this.searchQuery, this.currentPage).subscribe(data => this.books = data.content);
          break;
        case 'year':
          this.bookService.getBooksByYear(Number(this.searchQuery), this.currentPage).subscribe(data => this.books = data.content);
          break;
        case 'genre':
          this.bookService.getBooksByGenre(this.searchQuery, this.currentPage).subscribe(data => this.books = data.content);
          break;
      }
    }

    borrowBook(title: string) {
      const memberName = this.authService.getCurrentMemberName();
    
      this.borrowService.borrowBook(title, memberName).subscribe(
        (response) => {
          console.log('Borrow API Response:', response); // ✅ Log full response
    
          if (response && response.Messages) {
            alert(`${response.Messages}\nBorrow ID: ${response.BorrowId}\nMember: ${response.MemberName}\nBook: ${response.BookTitle}\nBorrowed on: ${response.BorrowDate}\nReturn by: ${response.ReturnDate}`);
            this.fetchBooks();
          } else {
            alert('Unexpected response format');
          }
        },
        (error) => {
          console.error('Borrow API Error:', error); // ✅ Log full error object
          alert('Error borrowing book: ' + JSON.stringify(error));
        }
      );
    }
    
    
    goToUserDashboard() {
      this.router.navigate(['/admin-dashboard']); // ✅ Change this to match your actual route
    }
}

<div class="container">
    <div class="back-button-container">
      <button class="back-button" (click)="goToUserDashboard()">⬅ </button>
    </div>
    <h2 class="mb-4">View  Books</h2>

      <div class="search-bar">
          <div class="search-container">
            <input type="text" class="search-input" placeholder="Search..." [(ngModel)]="searchQuery" />
            <button class="search-btn" (click)="searchBooks()">
              🔍 <!-- Unicode search icon -->
            </button>
          </div>
        
          <select class="filter-dropdown" [(ngModel)]="selectedCategory">
            <option value="isbn">ISBN</option>
            <option value="author">Author</option>
            <option value="title">Title</option>
            <option value="year">Year Published</option>
            <option value="genre">Genre</option>
          </select>
          </div>
    
          <div class="row">
            <div class="col-md-4 mb-3" *ngFor="let book of filteredBooks">
              <div class="card-container" (click)="toggleFlip(book)">
                <div class="card h-100" [class.flipped]="book.isFlipped">
                  <!-- Front of the card -->
                  <div class="card-front">
                    <h5 class="card-title">{{ book.title }}</h5>
                    <p class="card-text">Available Copies: {{ book.availableCopies }}</p>
                    <button class="borrow-btn" (click)="borrowBook(book.title)">Borrow</button>
                  </div>
          
                  <!-- Back of the card -->
                  <div class="card-back">
                    <div class="card-body">
                      <p class="card-text">Author: {{ book.author }}</p>
                      <p class="card-text">Genre: {{ book.genre }}</p>
                      <p class="card-text">ISBN: {{ book.isbn }}</p>
                      <p class="card-text">Year: {{ book.yearPublished }}</p>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
          
  </div>
