<!-- Back Button -->
<div class="back-button-container">
  <button class="back-button" (click)="goToAdminDashboard()">
    <i class="bi bi-arrow-left"></i> Back
  </button>
</div>

<!-- Title -->
<h2 class="text-center">Manage Members</h2>

<!-- Add Member Button -->
<div class="text-end mb-3">
  <button class="btn btn-success" (click)="openAddModal()">
    <i class="bi bi-plus-circle"></i> Add Member
  </button>
</div>

<!-- Member Cards Grid -->
<div class="row px-3">
  <div class="col-md-4 mb-4" *ngFor="let member of members">
    <div class="card shadow h-100">
      <div class="card-body text-center">
        <img src="https://cdn-icons-png.flaticon.com/512/149/149071.png" class="rounded-circle mb-3" width="100" height="100" alt="Profile Image">
        <h5 class="card-title">{{ member.name }}</h5>
        <p class="card-text"><i class="bi bi-person-badge"></i> <strong>ID:</strong> {{ member.memberId }}</p>
        <p class="card-text"><i class="bi bi-envelope"></i> <strong>Email:</strong> {{ member.email }}</p>
        <p class="card-text"><i class="bi bi-telephone"></i> <strong>Phone:</strong> {{ member.phone }}</p>
        <p class="card-text"><i class="bi bi-geo-alt"></i> <strong>Address:</strong> {{ member.address }}</p>
        <span class="badge bg-info">{{ member.membershipStatus }}</span>
        <div class="mt-3">
          <button class="btn btn-warning btn-sm me-2" (click)="openEditModal(member)">
            <i class="bi bi-pencil-square"></i> Edit
          </button>
          <button class="btn btn-danger btn-sm" (click)="deleteMember(member.memberId)">
            <i class="bi bi-trash"></i> Delete
          </button>
        </div>
      </div>
    </div>
  </div>
</div>

<!-- Pagination -->
<div class="d-flex justify-content-between align-items-center px-3 mt-4">
  <button class="btn btn-purple" (click)="prevPage()" [disabled]="page === 0">
    <i class="bi bi-chevron-left"></i> Previous
  </button>
  <span class="text-white">Page {{ page + 1 }} of {{ totalPages }}</span>
  <button class="btn btn-purple" (click)="nextPage()" [disabled]="page >= totalPages - 1">
    Next <i class="bi bi-chevron-right"></i>
  </button>
</div>



<!-- Bootstrap CSS -->
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
<!-- Bootstrap Icons -->
<link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.10.5/font/bootstrap-icons.css" rel="stylesheet">



body {
  background: linear-gradient(to right, #1C1C1E, #4B0082);
  font-family: 'Segoe UI', sans-serif;
  margin: 0;
  padding: 0;
  min-height: 100vh;
}

/* Back Button */
.back-button-container {
  margin: 20px;
}
.back-button {
  background-color: #4B0082;
  color: #ffffff;
  border: none;
  padding: 10px 20px;
  font-size: 1rem;
  border-radius: 30px;
  cursor: pointer;
  transition: background-color 0.3s ease, transform 0.3s ease;
}
.back-button:hover {
  background-color: #6A0DAD;
  transform: scale(1.05);
  box-shadow: 0 0 10px rgba(106, 13, 173, 0.4);
}

/* Heading */
h2.text-center {
  font-size: 2rem;
  font-weight: bold;
  margin-bottom: 30px;
  background: linear-gradient(90deg, #e100ff, #8e2de2);
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;
}

/* Add Member Button */
.text-end .btn-success {
  border-radius: 30px;
  padding: 10px 20px;
  font-weight: 500;
  margin: 10px 20px;
  transition: background-color 0.3s ease, transform 0.3s ease;
}
.text-end .btn-success:hover {
  background-color: #28a745;
  transform: scale(1.05);
}

/* Profile Cards */
.card {
  border-radius: 20px;
  transition: transform 0.3s ease, box-shadow 0.3s ease;
  animation: fadeInUp 0.7s ease forwards;
}
.card:hover {
  transform: scale(1.03);
  box-shadow: 0 8px 20px rgba(0, 0, 0, 0.15);
}
.card-body {
  padding: 1.5rem;
}

/* Profile Image */
.card-body img {
  border: 3px solid #4B0082;
  padding: 5px;
  background: white;
}

/* Card Buttons */
.btn-warning.btn-sm,
.btn-danger.btn-sm {
  border-radius: 20px;
  padding: 6px 12px;
  font-size: 0.85rem;
  transition: background-color 0.3s ease, transform 0.3s ease;
}
.btn-warning.btn-sm:hover {
  background-color: #ffc107;
  transform: scale(1.05);
}
.btn-danger.btn-sm:hover {
  background-color: #dc3545;
  color: #fff;
  transform: scale(1.05);
}

/* Status Badge */
.badge {
  font-size: 0.9rem;
  padding: 0.5em 0.8em;
  border-radius: 30px;
}

/* Pagination */
.d-flex.justify-content-between {
  margin: 30px 20px;
}
.btn-purple {
  background-color: #9370DB;
  color: #fff;
  border: none;
  border-radius: 30px;
  padding: 8px 20px;
  font-weight: 500;
  transition: background-color 0.3s ease, transform 0.3s ease;
}
.btn-purple:hover {
  background-color: #B57EDC;
  transform: scale(1.05);
}
.btn-purple:disabled {
  background-color: #5e2392;
  color: #f5f5f5;
  cursor: not-allowed;
}

/* Animation */
@keyframes fadeInUp {
  from {
    opacity: 0;
    transform: translateY(30px);
  }
  to {
    opacity: 1;
    transform: translateY(0);
  }
}

/* Responsive Buttons */
@media (max-width: 768px) {
  .btn {
    width: 100%;
    margin-bottom: 10px;
  }
  .card-body {
    padding: 1rem;
  }
}
