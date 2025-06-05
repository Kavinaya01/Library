<div class="container mt-4">
  <div class="back-button-container mb-3">
    <button class="btn btn-outline-secondary back-button" (click)="goToAdminDashboard()">⬅ Back</button>
  </div>

  <h2 class="text-center mb-4 gradient-title">Manage Members</h2>

  <!-- Add Member Button -->
  <div class="text-end mb-4">
    <button class="btn btn-success add-member-btn" (click)="openAddModal()">➕ Add Member</button>
  </div>

  <!-- Member Profile Cards Grid -->
  <div class="row">
    <div class="col-md-4 mb-4" *ngFor="let member of members">
      <div class="card shadow h-100 profile-card">
        <div class="card-body text-center">
          <img src="https://cdn-icons-png.flaticon.com/512/149/149071.png" class="rounded-circle mb-3 profile-img" alt="Profile Image">
          <h5 class="card-title">{{ member.name }}</h5>
          <p class="card-text"><strong>ID:</strong> {{ member.memberId }}</p>
          <p class="card-text"><strong>Email:</strong> {{ member.email }}</p>
          <p class="card-text"><strong>Phone:</strong> {{ member.phone }}</p>
          <p class="card-text"><strong>Address:</strong> {{ member.address }}</p>
          <span class="badge bg-info status-badge">{{ member.membershipStatus }}</span>
          <div class="mt-3">
            <button class="btn btn-warning btn-sm me-2 action-btn" (click)="openEditModal(member)">Edit</button>
            <button class="btn btn-danger btn-sm action-btn" (click)="deleteMember(member.memberId)">Delete</button>
          </div>
        </div>
      </div>
    </div>
  </div>

  <!-- Pagination Controls -->
  <div class="d-flex justify-content-between mt-3">
    <button class="btn btn-purple" (click)="prevPage()" [disabled]="page === 0">Previous</button>
    <span class="text-white"> Page {{ page + 1 }} of {{ totalPages }} </span>
    <button class="btn btn-purple" (click)="nextPage()" [disabled]="page >= totalPages - 1">Next</button>
  </div>
</div>

<style>
body {
  background: linear-gradient(to right, #1C1C1E, #4B0082);
  font-family: 'Segoe UI', sans-serif;
  margin: 0;
  padding: 0;
  min-height: 100vh;
}

.container {
  background: #ffffff;
  border-radius: 20px;
  padding: 40px;
  margin-top: 40px;
  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
  animation: fadeInUp 1s ease forwards;
}

.back-button {
  background-color: #4B0082;
  color: #ffffff;
  border: none;
  padding: 10px 20px;
  font-size: 1rem;
  border-radius: 30px;
  transition: background-color 0.3s ease, transform 0.3s ease;
}

.back-button:hover {
  background-color: #6A0DAD;
  transform: scale(1.05);
  box-shadow: 0 0 10px rgba(106, 13, 173, 0.4);
}

.gradient-title {
  font-size: 2rem;
  font-weight: bold;
  background: linear-gradient(90deg, #5e005e, #8e008e);
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;
}

.add-member-btn {
  border-radius: 30px;
  padding: 10px 20px;
  font-weight: 500;
  transition: background-color 0.3s ease, transform 0.3s ease;
}

.add-member-btn:hover {
  background-color: #28a745;
  transform: scale(1.05);
}

.profile-card {
  border-radius: 20px;
  transition: transform 0.3s ease, box-shadow 0.3s ease;
}

.profile-card:hover {
  transform: scale(1.03);
  box-shadow: 0 8px 25px rgba(0, 0, 0, 0.15);
}

.profile-img {
  width: 100px;
  height: 100px;
  object-fit: cover;
  border: 3px solid #4B0082;
}

.status-badge {
  font-size: 0.85rem;
  padding: 0.5em 1em;
  border-radius: 50px;
}

.action-btn {
  border-radius: 20px;
  font-size: 0.85rem;
  transition: background-color 0.3s ease, transform 0.3s ease;
}

.action-btn:hover {
  transform: scale(1.05);
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
</style>
