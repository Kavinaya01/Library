<div class="container">
  <div class="back-button-container">
    <button class="back-button" (click)="goToAdminDashboard()">⬅ </button>
  </div>
  <h2 class="mb-4">Manage Books</h2>


    <button class="btn btn-primary mb-3" (click)="toggleManageBooks()">
      {{ showManageBooks ? 'Hide' : 'Add New Book' }}
    </button>
  
    <div *ngIf="showManageBooks" class="card p-3 mb-4">
      <form>
        <div class="mb-2">
          <input type="text" class="form-control" placeholder="Title" [(ngModel)]="bookForm.title" name="title" required />
        </div>
        <div class="mb-2">
          <input type="text" class="form-control" placeholder="Author" [(ngModel)]="bookForm.author" name="author" required />
        </div>
        <div class="mb-2">
          <input type="text" class="form-control" placeholder="Genre" [(ngModel)]="bookForm.genre" name="genre" />
        </div>
        <div class="mb-2">
          <input type="text" class="form-control" placeholder="ISBN" [(ngModel)]="bookForm.isbn" name="isbn" />
        </div>
        <div class="mb-2">
          <input type="number" class="form-control" placeholder="Year Published" [(ngModel)]="bookForm.yearPublished" name="yearPublished" />
        </div>
        <div>
          <button class="btn btn-success me-2" (click)="isEditing ? updateBook() : addBook()" type="button">
            {{ isEditing ? 'Update Book' : 'Add Book' }}
          </button>
          <button class="btn btn-secondary" type="button" (click)="resetForm()">Reset</button>
        </div>
      </form>
    </div>
  
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
              </div>
      
              <!-- Back of the card -->
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
