<div class="main-wrapper d-flex justify-content-center align-items-center">
  <div class="home-card shadow-lg p-4 fadeInUp">
    
    <!-- Header inside the card -->
    <div class="d-flex justify-content-between align-items-center mb-4">
      <div class="d-flex align-items-center">
        <img src="./logoo.gif" alt="Logo" class="logo-img mr-2">
        <h4 class="mb-0 library-title font-weight-bold">Library System</h4>
      </div>
      <div>
        <a routerLink="/login" class="text-link me-3">Login</a>
        <a routerLink="/register" class="text-link">Register</a>
      </div>
    </div>

    <!-- Hero Section -->
    <div class="row align-items-center">
      <div class="col-md-6 text-center text-md-left">
        <h1 class="display-4 highlight-text">Library Management System</h1>
        <p class="lead">
          A smart and efficient system to manage book lending, returns, and inventory for libraries of all sizes.
        </p>
        <div class="mt-4">
          <button routerLink="/login" class="btn btn-custom btn-lg animated-btn">Get Started</button>
        </div>
      </div>
      <div class="col-md-6 text-center mt-4 mt-md-0">
        <img src="./bg.png" alt="Library Illustration" class="img-fluid hero-image">
      </div>
    </div>
    <!-- Footer inside the card -->
    <footer class="card-footer text-center mt-5 pt-4 border-top">
      <p class="mb-1 text-muted">© 2025 Library System. All rights reserved.</p>
      <small class="text-muted">Designed with ❤️ for book lovers.</small>
    </footer>

  </div>
</div>


.main-wrapper {
  min-height: 100vh;
  background: linear-gradient(to right, #1C1C1E, #4B0082); /* Dark to deep plum */
  padding: 40px 20px;
}

.home-card {
  background-color: #ffffff;
  border-radius: 20px;
  max-width: 95%;
  width: 100%;
  padding: 40px;
  min-height: 80vh;
  display: flex;
  flex-direction: column;
  justify-content: center;
}

/* Logo */
.logo-img {
  width: 40px;
  height: 40px;
  object-fit: contain;
}

/* Hero image */
.hero-image {
  max-width: 100%;
  height: auto;
  object-fit: contain;
}

/* Highlighted heading */
.highlight-text {
  background: linear-gradient(90deg, #5e005e, #8e008e); /* Dusty rose to lavender gray */
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;
  font-weight: bold;
}

/* Custom button */
.btn-custom {
  background-color: #4B0082; /* Deep plum */
  color: #ffffff;
  border: none;
  padding: 0.75rem 1.5rem;
  border-radius: 0.25rem;
  transition: 0.3s ease-in-out;
}

.btn-custom:hover {
  background-color: #6A0DAD; /* Slightly lighter plum */
}

/* Animated buttons */
.btn-animated {
  transition: all 0.3s ease;
}

.btn-animated:hover {
  transform: scale(1.05);
  box-shadow: 0 0 10px rgba(75, 0, 130, 0.3);
}

.card-footer {
  background-color: transparent;
  font-size: 0.9rem;
  animation: fadeInUp 1s ease-in-out;
  color: #B8B8D1;
}

.card-footer p,
.card-footer small {
  margin: 0;
}

/* Text links */
.text-link {
  font-size: 1.1rem;
  font-weight: 500;
  color: #4B0082; /* Lavender gray */
  text-decoration: none;
  transition: color 0.3s ease, transform 0.3s ease;
  cursor: pointer;
  opacity: 0;
  animation: slideIn 0.8s ease forwards;
}

.text-link:hover {
  color: #680064; /* Gold accent */
  transform: scale(1.05);
  text-decoration: underline;
}

.text-link + .text-link {
  margin-left: 20px;
}

/* Title heading */
.library-title {
  color: #4B0082; /* Dusty rose */
}

/* Animations */
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

@keyframes slideIn {
  from {
    opacity: 0;
    transform: translateX(30px);
  }
  to {
    opacity: 1;
    transform: translateX(0);
  }
}

.text-link:nth-child(1) {
  animation-delay: 0.2s;
}

.text-link:nth-child(2) {
  animation-delay: 0.4s;
}


import { Component } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { AuthService } from '../../service/auth/auth.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-login',
  standalone: false,
  templateUrl:'./login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent {
  loginForm!: FormGroup;

  
  constructor(private fb: FormBuilder, private authService: AuthService, private router: Router) {
    this.initializeForm();
  }

  private initializeForm() {
    this.loginForm = this.fb.group({
      email: ['', [Validators.required, Validators.email]],
      password: ['', [Validators.required, Validators.minLength(3)]],
      role: ['member', Validators.required] // Select role
    });
  }

  get email() { return this.loginForm.get('email'); }
  get password() { return this.loginForm.get('password'); }
  get role() { return this.loginForm.get('role'); }

  onLogin() {
    if (this.loginForm.invalid) return;

    const payload = {
      email: this.loginForm.value.email.trim(),
      password: this.loginForm.value.password
    };

    console.log('Sending login request:', payload);

    if (this.loginForm.value.role === 'admin') {
      this.authService.loginAdmin(payload).subscribe(
        response => {
          if (response.token) {
            this.authService.storeToken(response.token);
            this.authService.setCurrentMemberName(response.adminName);
            alert('Admin login successful!');
            this.router.navigate(['/admin-dashboard']);
          } else {
            alert('Invalid admin credentials!');
          }
        },
        error => {
          console.error('Login error:', error);
          alert('Invalid admin credentials!');
        }
      );
    } else {
      this.authService.login(payload).subscribe(
        response => {
          if (response.token) {
            this.authService.storeToken(response.token);
            alert('Member login successful!');
            this.authService.setCurrentMemberName(response.memberName); 
            this.router.navigate(['/member-dashboard']);
          } else {
            alert('Invalid member credentials!');
          }
        },
        error => {
          console.error('Login error:', error);
          alert('Invalid member credentials!');
        }
      );
    }
  }
  switchRole(role: 'member' | 'admin') {
    this.loginForm.patchValue({ role });
  }
  
  
}


<div class="login-page d-flex align-items-center justify-content-center">
  <img src="./login_bg.jpg" class="background-img" alt="Background" />

  
  <div class="container login-content-fade">
    <div class="row justify-content-center">
      <div class="col-md-8 col-lg-6">
        <div class="login-card-wrapper" [class.flipped]="loginForm.value.role === 'admin'">
          <div class="login-card">
            <!-- Front: Member Login -->
             
            <div class="card-face card-front">

              <div class="d-flex justify-content-between align-items-center mb-4">
                <div class="d-flex align-items-center">
                  <img src="./logoo.gif" alt="Logo" class="logo-img mr-2">
                  <h4 class="mb-0 library-title font-weight-bold">Library System</h4>
                </div>
                <div>
                  <a routerLink="/login" class="text-link me-3">Login</a>
                  <a routerLink="/register" class="text-link">Register</a>
                </div>
              </div>
              <h2 class="text-center mb-4">Member Login</h2>
              <form [formGroup]="loginForm">
                <input type="email" formControlName="email" class="form-control mb-2" placeholder="Email" />
                <div *ngIf="loginForm.get('email')?.invalid && loginForm.get('email')?.touched" class="error">
                  Enter a valid email.
                </div>

                <input type="password" formControlName="password" class="form-control mb-2" placeholder="Password" />
                <div *ngIf="loginForm.get('password')?.invalid && loginForm.get('password')?.touched" class="error">
                  Password must be at least 6 characters.
                </div>

                <button type="button" class="svg-btn w-100" [disabled]="loginForm.invalid" (click)="onLogin()">
                  <svg width="277" height="62">
                    <defs>
                      <linearGradient id="skyGrad">
                        <stop offset="0%" stop-color="#7ed6df" />
                        <stop offset="100%" stop-color="#70a1ff" />
                      </linearGradient>
                    </defs>
                    <rect x="5" y="5" rx="25" fill="none" stroke="url(#skyGrad)" width="266" height="50"></rect>
                  </svg>
                  <span>Login</span>
                </button>
              </form>

              <div class="switch-role text-center mt-3">
                <button type="button" class="btn btn-link" (click)="switchRole('admin')">Switch to Admin</button>
              </div>

              <div class="register-link text-center">
                Don't have an account? <a routerLink="/register">Register</a>
              </div>
            </div>

            <!-- Back: Admin Login -->
            <div class="card-face card-back">
              
              <div class="d-flex justify-content-between align-items-center mb-4">
                <div class="d-flex align-items-center">
                  <img src="./logoo.gif" alt="Logo" class="logo-img mr-2">
                  <h4 class="mb-0 library-title font-weight-bold">Library System</h4>
                </div>
                <div>
                  <a routerLink="/login" class="text-link me-3">Login</a>
                  <a routerLink="/register" class="text-link">Register</a>
                </div>
              </div>
              
              <h2 class="text-center mb-4">Admin Login</h2>
              <form [formGroup]="loginForm">
                <input type="email" formControlName="email" class="form-control mb-2" placeholder="Admin Email" />
                <div *ngIf="loginForm.get('email')?.invalid && loginForm.get('email')?.touched" class="error">
                  Enter a valid email.
                </div>

                <input type="password" formControlName="password" class="form-control mb-2" placeholder="Admin Password" />
                <div *ngIf="loginForm.get('password')?.invalid && loginForm.get('password')?.touched" class="error">
                  Password must be at least 6 characters.
                </div>

                <button type="button" class="svg-btn w-100" [disabled]="loginForm.invalid" (click)="onLogin()">
                  <svg width="277" height="62">
                    <defs>
                      <linearGradient id="skyGrad2">
                        <stop offset="0%" stop-color="#7ed6df" />
                        <stop offset="100%" stop-color="#70a1ff" />
                      </linearGradient>
                    </defs>
                    <rect x="5" y="5" rx="25" fill="none" stroke="url(#skyGrad2)" width="266" height="50"></rect>
                  </svg>
                  <span>Login</span>
                </button>
              </form>

              <div class="switch-role text-center mt-3">
                <button type="button" class="btn btn-link" (click)="switchRole('member')">Switch to Member</button>
              </div>

              <div class="register-link text-center">
                Don't have an account? <a routerLink="/register">Register</a>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>


