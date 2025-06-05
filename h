<div class="container mt-4">
  <div class="back-button-container mb-3">
    <button class="back-button" (click)="goToAdminDashboard()">⬅ Back</button>
  </div>

  <h2 class="text-center mb-4">Manage Members</h2>

  <!-- Add Member Button -->
  <div class="text-right mb-3">
    <button class="btn btn-success" (click)="openAddModal()">➕ Add Member</button>
  </div>

  <!-- Member Profile Cards Grid -->
  <div class="row">
    <div class="col-md-4 mb-4" *ngFor="let member of members">
      <div class="card shadow h-100">
        <div class="card-body text-center">
          <img src="https://cdn-icons-png.flaticon.com/512/149/149071.png" class="rounded-circle mb-3" width="100" height="100" alt="Profile Image">
          <h5 class="card-title">{{ member.name }}</h5>
          <p class="card-text"><strong>ID:</strong> {{ member.memberId }}</p>
          <p class="card-text"><strong>Email:</strong> {{ member.email }}</p>
          <p class="card-text"><strong>Phone:</strong> {{ member.phone }}</p>
          <p class="card-text"><strong>Address:</strong> {{ member.address }}</p>
          <span class="badge bg-info">{{ member.membershipStatus }}</span>
          <div class="mt-3">
            <button class="btn btn-warning btn-sm me-2" (click)="openEditModal(member)">Edit</button>
            <button class="btn btn-danger btn-sm" (click)="deleteMember(member.memberId)">Delete</button>
          </div>
        </div>
      </div>
    </div>
  </div>

  <!-- Pagination Controls -->
  <div class="d-flex justify-content-between mt-3">
    <button class="btn btn-purple" (click)="prevPage()" [disabled]="page === 0">Previous</button>
    <span> Page {{ page + 1 }} of {{ totalPages }} </span>
    <button class="btn btn-purple" (click)="nextPage()" [disabled]="page >= totalPages - 1">Next</button>
  </div>

  <!-- Add Member Modal -->
  <div *ngIf="showAddModal" class="modal fade show d-block" tabindex="-1">
    <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header bg-success text-white">
          <h5 class="modal-title">Add New Member</h5>
          <button type="button" class="close" (click)="closeAddModal()">&times;</button>
        </div>
        <div class="modal-body">
          <form (ngSubmit)="addMember()" #addMemberForm="ngForm" novalidate>
            <div class="form-group">
              <label>ID:</label>
              <input type="text" class="form-control" [(ngModel)]="newMember.memberId" name="id" required>
            </div>
            <div class="form-group">
              <label>Name:</label>
              <input type="text" class="form-control" [(ngModel)]="newMember.name" name="name" required>
            </div>
            <div class="form-group">
              <label>Email:</label>
              <input type="email" class="form-control" [(ngModel)]="newMember.email" name="email" required>
            </div>
            <div class="form-group">
              <label>Phone:</label>
              <input type="text" class="form-control" [(ngModel)]="newMember.phone" name="phone" required>
            </div>
            <div class="form-group">
              <label>Address:</label>
              <input type="text" class="form-control" [(ngModel)]="newMember.address" name="address" required>
            </div>
            <div class="form-group">
              <label>Password:</label>
              <input type="password" class="form-control" [(ngModel)]="newMember.password" name="password" required>
            </div>
            <div class="form-group">
              <label>Status:</label>
              <select class="form-control" [(ngModel)]="newMember.membershipStatus" name="status" required>
                <option value="Active">Active</option>
                <option value="Inactive">Inactive</option>
              </select>
            </div>
            <div class="modal-footer">
              <button type="button" class="btn btn-secondary" (click)="closeAddModal()">Cancel</button>
              <button type="submit" class="btn btn-success" (click)="addMember()">Add Member</button>

            </div>
          </form>
        </div>
      </div>
    </div>
  </div>

  <!-- Edit Member Modal -->
  <div *ngIf="selectedMember" class="modal fade show d-block" tabindex="-1">
    <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header bg-secondary text-white">
          <h5 class="modal-title">Edit Member</h5>
          <button type="button" class="close" (click)="closeEditModal()">&times;</button>
        </div>
        <div class="modal-body">
          <form (ngSubmit)="updateMember(selectedMember.memberId, selectedMember)">
            <div class="form-group">
              <label>Name:</label>
              <input type="text" class="form-control" [(ngModel)]="selectedMember.name" name="editName">
            </div>
            <div class="form-group">
              <label>Email:</label>
              <input type="email" class="form-control" [(ngModel)]="selectedMember.email" name="editEmail">
            </div>
            <div class="form-group">
              <label>Phone:</label>
              <input type="text" class="form-control" [(ngModel)]="selectedMember.phone" name="editPhone">
            </div>
            <div class="form-group">
              <label>Address:</label>
              <input type="text" class="form-control" [(ngModel)]="selectedMember.address" name="editAddress">
            </div>
            <div class="form-group">
              <label>Status:</label>
              <select class="form-control" [(ngModel)]="selectedMember.membershipStatus" name="editStatus">
                <option value="Active">Active</option>
                <option value="Inactive">Inactive</option>
              </select>
            </div>
            <div class="modal-footer">
              <button type="button" class="btn btn-secondary" (click)="closeEditModal()">Cancel</button>
              <button type="submit" class="btn btn-success">Save Changes</button>
            </div>
          </form>
        </div>
      </div>
    </div>
  </div>
</div>


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

.back-button-container {
  margin-bottom: 20px;
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

h2.text-center {
  font-size: 2rem;
  font-weight: bold;
  background: linear-gradient(90deg, #5e005e, #8e008e);
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;
}

.text-right .btn-success {
  border-radius: 30px;
  padding: 10px 20px;
  font-weight: 500;
  transition: background-color 0.3s ease, transform 0.3s ease;
}

.text-right .btn-success:hover {
  background-color: #28a745;
  transform: scale(1.05);
}

.card {
  border-radius: 20px;
  transition: transform 0.3s ease;
}

.card:hover {
  transform: scale(1.02);
  box-shadow: 0 8px 20px rgba(0, 0, 0, 0.15);
}

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

.modal-content {
  border-radius: 15px;
  box-shadow: 0 10px 25px rgba(0, 0, 0, 0.3);
}

.modal-header,
.modal-footer {
  border-radius: 15px;
}

.modal-title {
  font-weight: bold;
}

.modal .form-control {
  border-radius: 10px;
  padding: 10px;
  border: 2px solid #ccc;
  transition: border-color 0.3s ease;
}

.modal .form-control:focus {
  border-color: #4B0082;
  outline: none;
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

.fadeInUp {
  animation: fadeInUp 1s ease forwards;
}

@media (max-width: 768px) {
  .container {
    padding: 20px;
  }

  .btn {
    width: 100%;
    margin-bottom: 10px;
  }

  .card-body {
    padding: 1rem;
  }
}
