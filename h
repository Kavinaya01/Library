/* General Styling */
body {
  background: linear-gradient(to right, #1C1C1E, #4B0082);
  font-family: 'Segoe UI', sans-serif;
  margin: 0;
  padding: 0;
  min-height: 100vh;
}

/* Container */
.container {
  background: #ffffff;
  border-radius: 20px;
  padding: 40px;
  margin-top: 40px;
  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
  animation: fadeInUp 1s ease forwards;
}

/* Back Button */
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

/* Title */
h2.text-center {
  font-size: 2rem;
  font-weight: bold;
  background: linear-gradient(90deg, #5e005e, #8e008e);
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;
}

/* Add Button */
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

/* Table Styling */
.table {
  margin-top: 20px;
  border-radius: 12px;
  overflow: hidden;
  border-collapse: separate;
  border-spacing: 0;
  box-shadow: 0 4px 12px rgba(0, 0, 0, 0.05);
}

.table th {
  background-color: #4B0082;
  color: #fff;
  text-align: center;
}

.table td {
  vertical-align: middle;
  text-align: center;
  border: 1px solid #e0cfff;
}

.table tbody tr:nth-child(odd) {
  background-color: #ffffff;
}

.table tbody tr:nth-child(even) {
  background-color: #f3e8ff;
}

.table-hover tbody tr:hover {
  background-color: #e0cfff;
}

/* Action Buttons */
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

/* Pagination */
.d-flex.justify-content-between {
  margin-top: 20px;
}

.btn-primary {
  border-radius: 30px;
  padding: 8px 20px;
  font-weight: 500;
  transition: background-color 0.3s ease, transform 0.3s ease;
}

.btn-primary:hover {
  background-color: #6A0DAD;
  transform: scale(1.05);
}

/* Modal Styling */
.modal-content {
  border-radius: 15px;
  box-shadow: 0 10px 25px rgba(0, 0, 0, 0.3);
}

.modal-header {
  border-top-left-radius: 15px;
  border-top-right-radius: 15px;
}

.modal-footer {
  border-bottom-left-radius: 15px;
  border-bottom-right-radius: 15px;
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

.fadeInUp {
  animation: fadeInUp 1s ease forwards;
}

/* Responsive */
@media (max-width: 768px) {
  .container {
    padding: 20px;
  }

  .table th,
  .table td {
    font-size: 0.9rem;
  }

  .btn {
    width: 100%;
    margin-bottom: 10px;
  }
}


/* Lavender-themed Pagination Buttons */
.btn-purple {
  background-color: #9370DB; /* Medium purple */
  color: #fff;
  border: none;
  border-radius: 30px;
  padding: 8px 20px;
  font-weight: 500;
  transition: background-color 0.3s ease, transform 0.3s ease;
}

.btn-purple:hover {
  background-color: #B57EDC; /* Light lavender */
  transform: scale(1.05);
}

.btn-purple:disabled {
  background-color: #5e2392;/* change this for the previous and next button colors*/
  color: #f5f5f5;
  cursor: not-allowed;
}
<div class="container mt-4">
  <div class="back-button-container">
    <button class="back-button" (click)="goToAdminDashboard()">⬅</button>
  </div>

  <h2 class="text-center mb-4">Manage Members</h2>

  <!-- Add Member Button -->
  <div class="text-right mb-3">
    <button class="btn btn-success" (click)="openAddModal()">➕ Add Member</button>
  </div>

  <!-- Table for Member List -->
  <table class="table table-bordered table-striped">
    <thead class="bg-primary text-white">
      <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Email</th>
        <th>Phone</th>
        <th>Address</th>
        <th>Status</th>
        <th>Actions</th>
      </tr>
    </thead>
    <tbody>
      <tr *ngFor="let member of members">
        <td>{{ member.memberId }}</td>
        <td>{{ member.name }}</td>
        <td>{{ member.email }}</td>
        <td>{{ member.phone }}</td>
        <td>{{ member.address }}</td>
        <td>{{ member.membershipStatus }}</td>
        <td>
          <button class="btn btn-warning btn-sm" (click)="openEditModal(member)">Edit</button>
          <button class="btn btn-danger btn-sm" (click)="deleteMember(member.memberId)">Delete</button>
        </td>
      </tr>
    Controls -->
  <div class="d-flex justify-content-between mt-3">
    <button class="btn btn-purple" (click)="prevPage()" [disabled]="page === 0">Previous</button>
    <span> Page {{ page + 1 }} of {{ totalPages }} </span>
    <button class="btn btn-purple" (click)="nextPage()" [disabled]="page >= totalPages - 1">Next</button>
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
              <button type="submit" class="btn btn-success" [disabled]="addMemberForm.invalid">Add Member</button>
            </div>
          </form>
        </div>
      </div>
    </div>
  </div>
