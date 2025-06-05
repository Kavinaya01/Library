
import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { MemberService } from '../../../service/member/member.service';
import { Router } from '@angular/router';
import { HttpErrorResponse } from '@angular/common/http';

@Component({
 selector: 'app-manage-members',
 standalone:false,
 templateUrl: './manage-members.component.html',
 styleUrls: ['./manage-members.component.css']
})
export class ManageMembersComponent implements OnInit {
 members: any[] = [];

  page: number = 0;
  totalPages: number = 0;
  showAddModal: boolean = false;
  selectedMember: any = {};

  registerForm!: FormGroup;

  constructor(
    private memberService: MemberService,
    private router: Router,
    private fb: FormBuilder
  ) {}

  

   newMember = {
     memberId: '',
     name: '',
     email: '',
     phone: '',
     address: '',
     password: '',
     membershipStatus: 'Active' // or 'Inactive' as default
    };
    

  ngOnInit(): void {
    this.initializeForm();
    this.fetchMembers();
  }

  initializeForm() {
    this.registerForm = this.fb.group({
      name: ['', [Validators.required]],
      email: ['', [Validators.required, Validators.email]],
      phone: ['', [Validators.required, Validators.pattern('^[0-9]{10}$')]],
      address: ['', [Validators.required]],
      password: ['', [Validators.required, Validators.minLength(6)]]
    });
  }
  get email() { return this.registerForm.get('email'); }
  get phone() { return this.registerForm.get('phone'); }
  get address() { return this.registerForm.get('address'); }
  get password() { return this.registerForm.get('password'); }

  fetchMembers() {
    this.memberService.getAllMembers(this.page).subscribe({
      next: (response) => {
        this.members = response.content;
        this.totalPages = response.totalPages;
        console.log(`Fetched page ${this.page + 1} of ${this.totalPages}`);
      },
      error: (error) => {
        console.error('Error fetching members:', error);
        alert('Failed to load members. Please try again.');
      }
    });
  }

  nextPage() {
    if (this.page < this.totalPages - 1) {
      this.page++;
      this.fetchMembers();
      alert(`Page changed to ${this.page + 1}`);
    } else {
      alert('You are already on the last page.');
    }
  }

  prevPage() {
    if (this.page > 0) {
      this.page--;
      this.fetchMembers();
      alert(`Page changed to ${this.page + 1}`);
    } else {
      alert('You are already on the first page.');
    }
  }
  

  openAddModal() {
    this.showAddModal = true;
    this.registerForm.reset();
    console.log('Opening Add Member modal');
  }

  closeAddModal() {
    this.showAddModal = false;
    console.log('Closing Add Member modal');
  }

  addMember() {
    if (this.registerForm.invalid) return;
  
    const payload = {
      name: this.registerForm.value.name,
      email: this.registerForm.value.email,
      phone: this.registerForm.value.phone,
      address: this.registerForm.value.address,
      password: this.registerForm.value.password,
      membershipStatus: 'Active'
    };
  
    console.log('Sending member registration request:', payload);
  
    this.memberService.addMember(payload).subscribe({
      next: (response) => {
        console.log('Server Response:', response);
        alert('New member added!');
        this.closeAddModal();
        this.fetchMembers();
      },
      error: (error) => {
        console.error('Error adding member:', error);
        alert(`Error: ${error.message || error.error}`);
      }
    });
  }
  
  openEditModal(member: any) {
    this.selectedMember = { ...member };
    console.log(`Editing member: ${member.name} (ID: ${member.memberId})`);
  }

  closeEditModal() {
    this.selectedMember = null;
    console.log('Closing edit modal');
  }

  updateMember(memberId: number, updatedData: any) {
    this.memberService.updateMember(memberId, updatedData).subscribe({
      next: (response) => {
        console.log("Update successful:", response);
        alert("Member updated successfully!");
        
        const index = this.members.findIndex(m => m.memberId === memberId);
        if (index !== -1) {
          this.members[index] = { ...updatedData }; // ✅ Updates UI immediately
        }
  
        this.closeEditModal();
      },
      error: (error) => {
        console.error("Update failed:", error);
        alert("Error updating member!");
      }
    });
  }
  

  deleteMember(memberId: number) {
    if (confirm('Are you sure you want to delete this member?')) {
      this.memberService.deleteMember(memberId).subscribe({
        next: () => {
          console.log(`Member with ID ${memberId} deleted successfully`);
          alert('Member deleted successfully!');
          this.fetchMembers();
        },
        error: (error) => {
          console.error('Error deleting member:', error);
          alert('Failed to delete member. Make sure you have Admin access.');
        }
      });
    }
  }

  goToAdminDashboard() {
    this.router.navigate(['/admin-dashboard']);
  }
}



<div class="back-button-container">
  <button class="back-button btn-small" (click)="goToAdminDashboard()">
    <i class="bi bi-arrow-left"></i> Back
  </button>
</div>

<!-- Title -->
<h2 class="text-center">Manage Members</h2>

<!-- Add Member Button -->
<div class="text-end mb-3">
  <button class="btn btn-success btn-sm" data-bs-toggle="modal" data-bs-target="#addMemberModal">
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
          <button class="btn btn-warning btn-sm me-2" data-bs-toggle="modal" data-bs-target="#editMemberModal" (click)="openEditModal(member)">
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
  <button class="btn btn-purple btn-sm" (click)="prevPage()" [disabled]="page === 0">
    <i class="bi bi-chevron-left"></i> Previous
  </button>
  <span class="text-white">Page {{ page + 1 }} of {{ totalPages }}</span>
  <button class="btn btn-purple btn-sm" (click)="nextPage()" [disabled]="page >= totalPages - 1">
    Next <i class="bi bi-chevron-right"></i>
  </button>
</div>

<!-- Add Member Modal -->
<div class="modal fade" id="addMemberModal" tabindex="-1" aria-labelledby="addMemberLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header bg-success text-white">
        <h5 class="modal-title">Add New Member</h5>
        <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
      </div>
      <div class="modal-body">
        <form (ngSubmit)="addMember()" #addMemberForm="ngForm" novalidate>
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
          <div class="modal-footer">
            <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cancel</button>
            <button type="submit" class="btn btn-success">Add Member</button>
          </div>
        </form>
      </div>
    </div>
  </div>
</div>

<!-- Edit Member Modal -->
<div class="modal fade" id="editMemberModal" tabindex="-1" aria-labelledby="editMemberLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header bg-secondary text-white">
        <h5 class="modal-title">Edit Member</h5>
        <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
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
          <div class="modal-footer">
            <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cancel</button>
            <button type="submit" class="btn btn-success">Save Changes</button>
          </div>
        </form>
      </div>
    </div>
  </div>
</div>


updateMember(memberId: number, updatedData: any) {
  this.memberService.updateMember(memberId, updatedData).subscribe({
    next: (response) => {
      console.log("Update successful:", response);
      alert("Member updated successfully!");

      const index = this.members.findIndex(m => m.memberId === memberId);
      if (index !== -1) {
        // Preserve the memberId in the updated object
        this.members[index] = {
          ...this.members[index], // retain all old values including memberId
          ...updatedData // overwrite updated fields only
        };
      }

      this.closeEditModal();
    },
    error: (error) => {
      console.error("Update failed:", error);
      alert("Error updating member!");
    }
  });
}
