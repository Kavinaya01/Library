<div class="main-wrapper d-flex justify-content-center align-items-center">
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

    <!-- Login Form Section -->
    <div class="row justify-content-center">
      <div class="col-md-8">
        <h2 class="text-center mb-4 highlight-text">{{ loginForm.value.role === 'admin' ? 'Admin' : 'Member' }} Login</h2>
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

        <!-- Switch Role Button -->
        <div class="switch-role text-center mt-3">
          <button type="button" class="btn btn-link" (click)="switchRole(loginForm.value.role === 'admin' ? 'member' : 'admin')">
            Switch to {{ loginForm.value.role === 'admin' ? 'Member' : 'Admin' }}
          </button>
        </div>

        <!-- Register Link -->
        <div class="register-link text-center mt-3">
          Don’t have an account? <a routerLink="/register">Register</a>
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


.main-wrapper {
  min-height: 100vh;
  background: linear-gradient(to right, #1C1C1E, #4B0082);
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

.logo-img {
  width: 40px;
  height: 40px;
  object-fit: contain;
}

.highlight-text {
  background: linear-gradient(90deg, #5e005e, #8e008e);
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;
  font-weight: bold;
}

.btn-custom {
  background-color: #4B0082;
  color: #ffffff;
  border: none;
  padding: 0.75rem 1.5rem;
  border-radius: 0.25rem;
  transition: 0.3s ease-in-out;
}

.btn-custom:hover {
  background-color: #6A0DAD;
}

.btn-animated {
  transition: all 0.3s ease;
}

.btn-animated:hover {
  transform: scale(1.05);
  box-shadow: 0 0 10px rgba(75, 0, 130, 0.3);
}

.text-link {
  font-size: 1.1rem;
  font-weight: 500;
  color: #4B0082;
  text-decoration: none;
  transition: color 0.3s ease, transform 0.3s ease;
}

.text-link:hover {
  color: #680064;
  transform: scale(1.05);
  text-decoration: underline;
}

.library-title {
  color: #4B0082;
}

.card-footer {
  background-color: transparent;
  font-size: 0.9rem;
  animation: fadeInUp 1s ease-in-out;
  color: #B8B8D1;
}
