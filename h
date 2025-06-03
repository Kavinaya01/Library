<div class="main-wrapper d-flex justify-content-center align-items-center">
  <!-- Fixed Image on Left -->
  <img src="./bg.png" alt="Library Illustration" class="fixed-side-img d-none d-md-block" />

  <!-- Login Card -->
  <div class="home-card shadow-lg p-4 fadeInUp">

    <!-- Header -->
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


.fixed-side-img {
  position: fixed;
  left: 0;
  top: 0;
  bottom: 0;
  width: 50%;
  object-fit: cover;
  z-index: -1;
}

.home-card {
  background-color: #ffffff;
  border-radius: 20px;
  width: 100%;
  max-width: 600px;
  z-index: 2;
}

/* Flip Card Styles */
.flip-card-container {
  perspective: 1000px;
  min-height: 400px;
  position: relative;
}

.flip-card-inner {
  transition: transform 0.8s;
  transform-style: preserve-3d;
  position: relative;
}

.flip-card-inner.flipped {
  transform: rotateY(180deg);
}

.flip-card-face {
  backface-visibility: hidden;
  position: absolute;
  width: 100%;
  top: 0;
  left: 0;
}

.flip-card-front {
  z-index: 2;
}

.flip-card-back {
  transform: rotateY(180deg);
}
