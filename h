<div class="container">
  <div class="back-button-container">
    <button class="back-button" (click)="goToAdminDashboard()">⬅</button>
  </div>

  <h2 class="mb-4">Manage Books</h2>

  <!-- Add Book Button -->
  <div class="text-right mb-3">
    <button class="btn btn-success" (click)="openAddBookModal()">➕ Add New Book</button>
  </div>
  <!-- Add/Edit Book Modal -->
  <div *ngIf="showAddBookModal" class="modal fade show d-block" tabindex="-1">
    <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header bg-success text-white">
          <h5 class="modal-title">{{ isEditing ? 'Edit Book' : 'Add New Book' }}</h5>
          <button type="button" class="close" (click)="closeAddBookModal()">&times;</button>
        </div>
        <div class="modal-body">
          <form (ngSubmit)="isEditing ? updateBook() : addBook()">
            <div class="form-group mb-2">
              <label>Title:</label>
              <input type="text" class="form-control" [(ngModel)]="bookForm.title" name="title" required>
            </div>
            <div class="form-group mb-2">
              <label>Author:</label>
              <input type="text" class="form-control" [(ngModel)]="bookForm.author" name="author" required>
            </div>
            <div class="form-group mb-2">
              <label>Genre:</label>
              <input type="text" class="form-control" [(ngModel)]="bookForm.genre" name="genre">
            </div>
            <div class="form-group mb-2">
              <label>ISBN:</label>
              <input type="text" class="form-control" [(ngModel)]="bookForm.isbn" name="isbn">
            </div>
            <div class="form-group mb-2">
              <label>Year Published:</label>
              <input type="number" class="form-control" [(ngModel)]="bookForm.yearPublished" name="yearPublished">
            </div>
            <div class="modal-footer">
              <button type="button" class="btn btn-secondary" (click)="closeAddBookModal()">Cancel</button>
              <button type="submit" class="btn btn-success">
                {{ isEditing ? 'Update Book' : 'Add Book' }}
              </button>
            </div>
          </form>
        </div>
      </div>
    </div>
  </div>
  <div class="search-bar d-flex justify-content-center mb-3">
  
    <input
    type="text"
    class="form-control w-50"
    [(ngModel)]="searchQuery"
    (input)="searchBooks()"
    placeholder="Search books by any field..."
  />
  
  
    <button class="btn btn-primary ms-2" (click)="searchBooks()">Search</button>
  </div>
  
  <!-- Not Found Message -->
  <div *ngIf="notFoundMessage" class="alert alert-warning text-center mt-3">
    {{ notFoundMessage }}
  </div>
  
  
  <!-- Book Cards -->
  <div class="row">
    <div class="col-md-4 mb-3" *ngFor="let book of filteredBooks">
      <div class="card-container" (click)="toggleFlip(book)">
        <div class="card h-100" [class.flipped]="book.isFlipped">
          <!-- Front -->
          <div class="card-front">
            <h5 class="card-title">{{ book.title }}</h5>
            <p class="card-text">Available Copies: {{ book.availableCopies }}</p>
          </div>
          <!-- Back -->
          <div class="card-back">
            <div class="card-body">
              <p class="card-text">Author: {{ book.author }}</p>
              <p class="card-text">Genre: {{ book.genre }}</p>
              <p class="card-text">ISBN: {{ book.isbn }}</p>
              <p class="card-text">Year: {{ book.yearPublished }}</p>
              <button class="btn btn-warning me-2" (click)="editBook(book)">Edit</button>
              <button class="btn btn-danger" (click)="deleteBook(book.id)">Delete</button>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
<!--vani-->


.back-button-container {
  position: absolute;
  top: 10px;
  left: 10px; /* ✅ Position in the top-left corner */
}

.back-button {
  background-color: #007bff;
  color: white;
  border: none;
  padding: 8px 12px;
  font-size: 16px;
  border-radius: 5px;
  cursor: pointer;
  transition: background-color 0.3s;
}

.back-button:hover {
  background-color: #0056b3;
}
 

.book-container {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(180px, 1fr)); /* ✅ Smaller cards */
    gap: 15px; /* ✅ Reduces space between cards */
    justify-content: center;
    padding: 15px;
  }
  
  .card-container {
    width: 100%;
    max-width: 220px; /* ✅ Smaller width */
    height: 280px; /* ✅ Smaller height */
    perspective: 1000px;
    cursor: pointer;
    display: flex;
    justify-content: center;
  }
  
  .card {
    width: 100%;
    height: 100%;
    transition: transform 0.6s;
    transform-style: preserve-3d;
    position: relative;
    border-radius: 8px;
    box-shadow: 2px 2px 8px rgba(0, 0, 0, 0.2);
  }
  
  .card-front,
  .card-back {
    position: absolute;
    width: 100%;
    height: 100%;
    backface-visibility: hidden;
    padding: 10px;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    text-align: center;
  }
  
  .card-front {
    background: #edf5fd;
    color: rgb(0, 0, 0);
  }
  
  .card-back {
    background: #f8f9fa;
    color: black;
    transform: rotateY(180deg);
  }
  
  .card.flipped {
    transform: rotateY(180deg);
  }
  
  .search-bar {
    display: flex;
    justify-content: center;
    align-items: center;
    gap: 10px;
    padding: 10px;
  }
  
  .search-container {
    display: flex;
    align-items: center;
    border: 2px solid #007bff;
    border-radius: 8px;
    padding: 5px;
    background: white;
  }
  
  .search-input {
    border: none;
    outline: none;
    padding: 8px;
    font-size: 16px;
    width: 200px;
  }
  
  .search-btn {
    background: transparent;
    border: none;
    font-size: 20px;
    cursor: pointer;
    color: #007bff;
  }
  
  .filter-dropdown {
    border: 2px solid #007bff;
    border-radius: 8px;
    padding: 8px;
    font-size: 16px;
  }
  
  /* ✅ Responsive adjustments for better spacing */
  @media screen and (max-width: 768px) {
    .book-container {
      grid-template-columns: repeat(2, 1fr); /* ✅ 2 cards per row on smaller screens */
    }
  }
  
  @media screen and (max-width: 480px) {
    .book-container {
      grid-template-columns: 1fr; /* ✅ Single-column layout on mobile */
    }
  }
  
