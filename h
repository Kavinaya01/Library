<div class="main-wrapper d-flex justify-content-center align-items-center">
  <div class="flip-container">
    <div class="login-card-wrapper" [class.flipped]="loginForm.value.role === 'admin'">
      <div class="login-card">

        <!-- Shared Image Side -->
        <div class="card-side card-image">
          <img src="./bg.png" alt="Library" class="img-fluid hero-image" />
        </div>

        <!-- Front: Member Login -->
        <div class="card-side card-front">
          <div class="p-4">
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

            <h2 class="text-center mb-4 highlight-text">Member Login</h2>

            <form [formGroup]="loginForm">
              <input type="email" formControlName="email" class="form-control mb-2" placeholder="Email" />
              <div *ngIf="loginForm.get('email')?.invalid && loginForm.get('email')?.touched" class="error">
                Enter a valid email.
              </div>

              <input type="password" formControlName="password" class="form-control mb-2" placeholder="Password" />
              <div *ngIf="loginForm.get('password')?.invalid && loginForm.get('password')?.touched" class="error">
                Password must be at least 6 characters.
              </div>

              <button type="button" class="btn btn-custom w-100 btn-animated" [disabled]="loginForm.invalid" (click)="onLogin()">
                Login
              </button>
            </form>

            <div class="text-center mt-3">
              <button class="btn btn-link" (click)="switchRole('admin')">Switch to Admin</button>
            </div>
          </div>
        </div>

        <!-- Back: Admin Login -->
        <div class="card-side card-back">
          <div class="p-4">
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

            <h2 class="text-center mb-4 highlight-text">Admin Login</h2>

            <form [formGroup]="loginForm">
              <input type="email" formControlName="email" class="form-control mb-2" placeholder="Admin Email" />
              <div *ngIf="loginForm.get('email')?.invalid && loginForm.get('email')?.touched" class="error">
                Enter a valid email.
              </div>

              <input type="password" formControlName="password" class="form-control mb-2" placeholder="Admin Password" />
              <div *ngIf="loginForm.get('password')?.invalid && loginForm.get('password')?.touched" class="error">
                Password must be at least 6 characters.
              </div>

              <button type="button" class="btn btn-custom w-100 btn-animated" [disabled]="loginForm.invalid" (click)="onLogin()">
                Login
              </button>
            </form>

            <div class="text-center mt-3">
              <button class="btn btn-link" (click)="switchRole('member')">Switch to Member</button>
            </div>
          </div>
        </div>

      </div>
    </div>
  </div>
</div>


.main-wrapper {
  min-height: 100vh;
  background: linear-gradient(to right, #1C1C1E, #4B0082);
  padding: 40px 20px;
}

.flip-container {
  perspective: 1200px;
}

.login-card-wrapper {
  width: 900px;
  height: 500px;
  position: relative;
  transform-style: preserve-3d;
  transition: transform 0.8s ease-in-out;
}

.login-card-wrapper.flipped {
  transform: rotateY(180deg);
}

.login-card {
  width: 100%;
  height: 100%;
  position: relative;
  display: flex;
  border-radius: 20px;
  box-shadow: 0 0 30px rgba(0, 0, 0, 0.15);
  background: white;
}

.card-side {
  width: 50%;
  backface-visibility: hidden;
  overflow-y: auto;
}

.card-front,
.card-back {
  position: absolute;
  right: 0;
  width: 50%;
  height: 100%;
  background: #ffffff;
  padding: 30px;
  border-radius: 0 20px 20px 0;
}

.card-back {
  transform: rotateY(180deg);
}

.card-image {
  background-color: #f9f9ff;
  display: flex;
  justify-content: center;
  align-items: center;
  border-radius: 20px 0 0 20px;
}

.card-image img {
  width: 90%;
  height: auto;
  object-fit: contain;
}

/* Reuse existing styles */
.logo-img {
  width: 40px;
  height: 40px;
  object-fit: contain;
}

.library-title {
  color: #4B0082;
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

.btn-animated:hover {
  transform: scale(1.05);
  box-shadow: 0 0 10px rgba(75, 0, 130, 0.3);
}

.text-link {
  font-size: 1.1rem;
  font-weight: 500;
  color: #4B0082;
  text-decoration: none;
  transition: 0.3s ease;
}

.text-link:hover {
  color: #680064;
  text-decoration: underline;
}
