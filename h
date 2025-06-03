/* Main wrapper: full viewport height, dark plum gradient background */
.main-wrapper {
  min-height: 100vh;
  background: linear-gradient(to right, #1C1C1E, #4B0082); /* Dark to deep plum */
  padding: 40px 20px;
  display: flex;
  justify-content: center;
  align-items: center;
  position: relative;
  overflow-x: hidden;
}

/* Fixed image on left side */
.fixed-side-img {
  position: fixed;
  left: 0;
  top: 0;
  bottom: 0;
  width: 50%;
  object-fit: cover;
  z-index: -1;
}

/* The card container */
.home-card {
  background-color: #ffffff;
  border-radius: 20px;
  width: 100%;
  max-width: 600px;
  padding: 40px;
  box-shadow: 0 10px 30px rgba(0,0,0,0.3);
  z-index: 2;
  display: flex;
  flex-direction: column;
  justify-content: center;
}

/* Logo inside header */
.logo-img {
  width: 40px;
  height: 40px;
  object-fit: contain;
  margin-right: 10px;
}

/* Library title */
.library-title {
  color: #4B0082; /* Deep plum */
  font-weight: 700;
  font-size: 1.5rem;
}

/* Text links (Login/Register) */
.text-link {
  font-size: 1.1rem;
  font-weight: 500;
  color: #4B0082;
  text-decoration: none;
  cursor: pointer;
  margin-left: 15px;
  transition: color 0.3s ease, transform 0.3s ease;
}

.text-link:hover {
  color: #680064;
  transform: scale(1.05);
  text-decoration: underline;
}

/* Highlighted heading */
.highlight-text {
  background: linear-gradient(90deg, #5e005e, #8e008e);
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;
  font-weight: bold;
  font-size: 2rem;
  margin-bottom: 30px;
}

/* Form inputs */
.form-control {
  width: 100%;
  padding: 10px 15px;
  font-size: 1rem;
  border: 2px solid #ccc;
  border-radius: 8px;
  margin-bottom: 15px;
  transition: border-color 0.3s ease;
}

.form-control:focus {
  border-color: #4B0082;
  outline: none;
}

/* Error messages */
.error {
  color: #e74c3c;
  font-size: 0.85rem;
  margin-top: -10px;
  margin-bottom: 10px;
}

/* Custom button */
.btn-custom {
  background-color: #4B0082;
  color: #ffffff;
  border: none;
  padding: 12px 20px;
  font-size: 1.1rem;
  border-radius: 30px;
  cursor: pointer;
  transition: background-color 0.3s ease, transform 0.3s ease;
  display: inline-block;
  width: 100%;
}

.btn-custom:disabled {
  background-color: #9b7ddb;
  cursor: not-allowed;
}

.btn-custom:hover:not(:disabled) {
  background-color: #6A0DAD;
  transform: scale(1.05);
  box-shadow: 0 0 10px rgba(106, 13, 173, 0.6);
}

/* Button link (switch role) */
.btn-link {
  background: none;
  border: none;
  color: #4B0082;
  cursor: pointer;
  font-size: 1rem;
  text-decoration: underline;
  padding: 0;
  transition: color 0.3s ease, transform 0.3s ease;
}

.btn-link:hover {
  color: #680064;
  transform: scale(1.05);
}

.register-new-user-btn {
  display: inline-block;
  width: 100%;
  padding: 12px 0;
  background: linear-gradient(90deg, #5e005e, #8e008e);
  color: #fff;
  font-weight: 600;
  font-size: 1rem;
  border: none;
  border-radius: 30px;
  cursor: pointer;
  text-align: center;
  text-decoration: none;
  box-shadow: 0 4px 12px rgba(142, 0, 142, 0.6);
  transition: background 0.3s ease, box-shadow 0.3s ease, transform 0.2s ease;
}

.register-new-user-btn:hover,
.register-new-user-btn:focus {
  background: linear-gradient(90deg, #8e008e, #b100b1);
  box-shadow: 0 6px 20px rgba(177, 0, 177, 0.8);
  transform: scale(1.05);
  outline: none;
}

/* Footer */
.card-footer {
  background-color: transparent;
  font-size: 0.9rem;
  color: #B8B8D1;
  margin-top: 50px;
  border-top: 1px solid #eee;
  padding-top: 20px;
  text-align: center;
}

/* Flip card container for 3D effect */
.flip-card-container {
  perspective: 1000px;
  min-height: 420px;
  position: relative;
}

/* Inner container that flips */
.flip-card-inner {
  position: relative;
  width: 100%;
  transition: transform 0.8s ease;
  transform-style: preserve-3d;
}

/* Add this class to flip the card */
.flip-card-inner.flipped {
  transform: rotateY(180deg);
}

/* Front and back faces */
.flip-card-face {
  position: absolute;
  width: 100%;
  backface-visibility: hidden;
  top: 0;
  left: 0;
  padding: 10px 0;
}

/* Front face (admin login) */
.flip-card-front {
  z-index: 2;
}

/* Back face (member login), flipped */
.flip-card-back {
  transform: rotateY(180deg);
}

/* Responsive: Hide fixed image on small devices */
@media (max-width: 767px) {
  .fixed-side-img {
    display: none;
  }
  .home-card {
    max-width: 100%;
    padding: 20px;
    margin: 0 10px;
  }
}

/* Smooth fadeInUp animation */
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



<div class="main-wrapper d-flex justify-content-center align-items-center">
  <!-- Fixed Image on Left -->
  <img src="./login_people.png" alt="Library Illustration" class="fixed-side-img d-none d-md-block" />

  <!-- Login Card -->
  <div class="home-card shadow-lg p-4 fadeInUp">

    <!-- Header -->
    <div class="d-flex justify-content-between align-items-center mb-4">
      <div class="d-flex align-items-center">
        <img src="./logoo.gif" alt="Logo" class="logo-img mr-2">
        <h4 class="mb-0 library-title font-weight-bold">Library System</h4>
      </div>
      <div>
        <a routerLink="/home" class="text-link me-3">Home</a>
        <a routerLink="/login" class="text-link me-3">Login</a>
        <a routerLink="/register" class="text-link">Register</a>
      </div>
    </div>

    <!-- Flip Card Wrapper -->
    <div class="flip-card-container">
      <div class="flip-card-inner" [class.flipped]="loginForm.value.role === 'member'">

        <!-- Front: Admin Login -->
        <div class="flip-card-face flip-card-front">
          <h2 class="text-center mb-4 highlight-text">Admin Login</h2>
          <form [formGroup]="loginForm">
            <input type="email" formControlName="email" class="form-control mb-3" placeholder="Admin Email" />
            <div *ngIf="loginForm.get('email')?.invalid && loginForm.get('email')?.touched" class="error">
              Enter a valid email.
            </div>

            <input type="password" formControlName="password" class="form-control mb-3" placeholder="Admin Password" />
            <div *ngIf="loginForm.get('password')?.invalid && loginForm.get('password')?.touched" class="error">
              Password must be at least 6 characters.
            </div>

            <button type="button" class="btn btn-custom w-100 btn-animated" [disabled]="loginForm.invalid" (click)="onLogin()">
              Login
            </button>
          </form>

          <div class="switch-role text-center mt-3">
            <button type="button" class="btn btn-link" (click)="switchRole('member')">
              Switch to Member
            </button>
          </div>
        </div>

        <!-- Back: Member Login -->
        <div class="flip-card-face flip-card-back">
          <h2 class="text-center mb-4 highlight-text">Member Login</h2>
          <form [formGroup]="loginForm">
            <input type="email" formControlName="email" class="form-control mb-3" placeholder="Email" />
            <div *ngIf="loginForm.get('email')?.invalid && loginForm.get('email')?.touched" class="error">
              Enter a valid email.
            </div>

            <input type="password" formControlName="password" class="form-control mb-3" placeholder="Password" />
            <div *ngIf="loginForm.get('password')?.invalid && loginForm.get('password')?.touched" class="error">
              Password must be at least 6 characters.
            </div>

            <button type="button" class="btn btn-custom w-100 btn-animated" [disabled]="loginForm.invalid" (click)="onLogin()">
              Login
            </button>
          </form>

          <div class="switch-role text-center mt-3">
            <button type="button" class="btn btn-link" (click)="switchRole('admin')">
              Switch to Admin
            </button>
          </div>
          <div>
            <button class="register-new-user-btn" routerLink="/register">New User? Register Here</button>
          </div>
        </div>

      </div>
    </div>

    <!-- Footer -->
    <footer class="card-footer text-center mt-5 pt-4 border-top">
      <p class="mb-1 text-muted">© 2025 Library System. All rights reserved.</p>
      <small class="text-muted">Designed with ❤️ for book lovers.</small>
    </footer>

  </div>
</div>


<div class="register-page">
  <img src="loginbg.png" class="background-img" alt="Background" />
  <img src="homee.png" class="floating-img" alt="Floating Image" />

  <div class="register-card-wrapper" [class.flipped]="isFlipped">
    <div class="register-card">
      <!-- Front Side -->
      <div class="card-face card-front">
        <h2>Step 1: Personal Info</h2>
        <form [formGroup]="registerForm">
          <input type="text" formControlName="name" placeholder="Name" />
          <div *ngIf="name?.invalid && name?.touched" class="error">Name is required.</div>

          <input type="text" formControlName="phone" placeholder="Phone" />
          <div *ngIf="phone?.invalid && phone?.touched" class="error">Phone must be 10 digits.</div>

          <input type="text" formControlName="address" placeholder="Address" />
          <div *ngIf="address?.invalid && address?.touched" class="error">Address is required.</div>

          <button type="button" class="svg-btn" (click)="flipCard()">
            <svg width="277" height="62">
              <defs>
                <linearGradient id="nextGrad">
                  <stop offset="0%" stop-color="#87ceeb" /> <!-- Sky Blue -->
                  <stop offset="100%" stop-color="#86ceeb" /> <!-- Navy Blue -->
                </linearGradient>
                <linearGradient id="hoverGrad">
                  <stop offset="0%" stop-color="#87ceeb" />
                  <stop offset="100%" stop-color="#000080" />
                </linearGradient>
              </defs>
              <rect x="5" y="5" rx="25" fill="none" stroke="url(#nextGrad)" width="266" height="50"></rect>
            </svg>
            
            <span>Next</span>
          </button>
          <div class="register-link">
            Already have an account? <a routerLink="/login">login</a>
          </div>
          
        </form>
      </div>

      <!-- Back Side -->
      <div class="card-face card-back">
        <h2>Step 2: Account Info</h2>
        <form [formGroup]="registerForm">
          <input type="email" formControlName="email" placeholder="Email" />
          <div *ngIf="email?.invalid && email?.touched" class="error">Enter a valid email.</div>

          <input type="password" formControlName="password" placeholder="Password" />
          <div *ngIf="password?.invalid && password?.touched" class="error">Password must be at least 6 characters.</div>

          <button type="button" class="svg-btn" [disabled]="registerForm.invalid" (click)="onRegister()">
            <svg width="277" height="62">
              <defs>
                <linearGradient id="regGrad">
                  <stop offset="0%" stop-color="#7ed6df" />
                  <stop offset="100%" stop-color="#70a1ff" />
                </linearGradient>
              </defs>
              <rect x="5" y="5" rx="25" fill="none" stroke="url(#regGrad)" width="266" height="50"></rect>
            </svg>
            <span>Register</span>
          </button>
          <div class="register-link">
            Already have an account? <a routerLink="/login">login</a>
          </div>
        </form>
      </div>
    </div>
  </div>
</div>

