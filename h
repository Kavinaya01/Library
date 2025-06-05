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
              <button type="submit" class="btn btn-success" [disabled]="addMemberForm.invalid">Add Member</button>
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
