<!-- Book Cards -->
<div class="row">
  <div class="col-sm-6 col-md-4 col-lg-3 mb-4" *ngFor="let book of filteredBooks">
    <div class="flip-card" (click)="toggleFlip(book)">
      <div class="flip-card-inner" [class.flipped]="book.isFlipped">
        <!-- Front Side -->
        <div class="flip-card-front shadow rounded bg-light text-center p-3 d-flex flex-column justify-content-center h-100">
          <h5 class="fw-bold">
            <i class="bi bi-book text-primary me-1"></i>{{ book.title }}
          </h5>
          <p class="text-muted">
            <i class="bi bi-box-seam me-1"></i>Available: {{ book.availableCopies }}
          </p>
        </div>

        <!-- Back Side -->
        <div class="flip-card-back shadow rounded bg-white p-3 h-100 d-flex flex-column justify-content-between">
          <div>
            <p><i class="bi bi-person me-1 text-secondary"></i><strong>Author:</strong> {{ book.author }}</p>
            <p><i class="bi bi-tags me-1 text-secondary"></i><strong>Genre:</strong> {{ book.genre }}</p>
            <p><i class="bi bi-123 me-1 text-secondary"></i><strong>ISBN:</strong> {{ book.isbn }}</p>
            <p><i class="bi bi-calendar me-1 text-secondary"></i><strong>Year:</strong> {{ book.yearPublished }}</p>
          </div>
          <div class="mt-2 d-flex justify-content-between">
            <button class="btn btn-warning btn-sm" (click)="editBook(book)">
              <i class="bi bi-pencil-square me-1"></i>Edit
            </button>
            <button class="btn btn-danger btn-sm" (click)="deleteBook(book.id)">
              <i class="bi bi-trash me-1"></i>Delete
            </button>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>


.back-button-container {
  position: absolute;
  top: 10px;
  left: 10px;
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

/* Flip Card Layout */
.flip-card {
  perspective: 1000px;
  height: 280px;
  cursor: pointer;
}

.flip-card-inner {
  position: relative;
  width: 100%;
  height: 100%;
  transition: transform 0.6s;
  transform-style: preserve-3d;
}

.flip-card-inner.flipped {
  transform: rotateY(180deg);
}

.flip-card-front,
.flip-card-back {
  position: absolute;
  width: 100%;
  height: 100%;
  border-radius: 10px;
  backface-visibility: hidden;
  padding: 15px;
  box-shadow: 0 2px 8px rgba(0, 0, 0, 0.2);
}

.flip-card-front {
  background-color: #edf5fd;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
}

.flip-card-back {
  background-color: #f8f9fa;
  transform: rotateY(180deg);
  display: flex;
  flex-direction: column;
  justify-content: space-between;
}

.flip-card-back p {
  margin-bottom: 6px;
}

/* Search Bar */
.search-bar {
  display: flex;
  justify-content: center;
  align-items: center;
  flex-wrap: wrap;
  gap: 10px;
  padding: 10px;
}

.search-bar input.form-control {
  max-width: 400px;
}

.search-bar .btn {
  white-space: nowrap;
}

/* Responsive Adjustments */
@media screen and (max-width: 768px) {
  .flip-card {
    height: 250px;
  }
}

@media screen and (max-width: 576px) {
  .flip-card {
    height: 230px;
  }
}

<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.10.5/font/bootstrap-icons.css">
