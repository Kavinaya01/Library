<div class="main-wrapper d-flex justify-content-center align-items-center">
  <!-- Fixed Image on Left -->
  <img src="./login_people.png" alt="Library Illustration" class="fixed-side-img d-none d-md-block" />

  <!-- Register Card -->
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
      <div class="flip-card-inner" [class.flipped]="isFlipped">

        <!-- Front: Step 1 -->
        <div class="flip-card-face flip-card-front">
          <h2 class="text-center mb-4 highlight-text">Step 1: Personal Info</h2>
          <form [formGroup]="registerForm">
            <input type="text" formControlName="name" class="form-control mb-3" placeholder="Name" />
            <div *ngIf="name?.invalid && name?.touched" class="error">Name is required.</div>

            <input type="text" formControlName="phone" class="form-control mb-3" placeholder="Phone" />
            <div *ngIf="phone?.invalid && phone?.touched" class="error">Phone must be 10 digits.</div>

            <input type="text" formControlName="address" class="form-control mb-3" placeholder="Address" />
            <div *ngIf="address?.invalid && address?.touched" class="error">Address is required.</div>

            <button type="button" class="btn btn-custom w-100 btn-animated" (click)="flipCard()">
              Next
            </button>
          </form>

          <div class="switch-role text-center mt-3">
            <span>Already have an account? <a routerLink="/login">Login</a></span>
          </div>
        </div>

        <!-- Back: Step 2 -->
        <div class="flip-card-face flip-card-back">
          <h2 class="text-center mb-4 highlight-text">Step 2: Account Info</h2>
          <form [formGroup]="registerForm">
            <input type="email" formControlName="email" class="form-control mb-3" placeholder="Email" />
            <div *ngIf="email?.invalid && email?.touched" class="error">Enter a valid email.</div>

            <input type="password" formControlName="password" class="form-control mb-3" placeholder="Password" />
            <div *ngIf="password?.invalid && password?.touched" class="error">Password must be at least 6 characters.</div>

            <button type="button" class="btn btn-custom w-100 btn-animated" [disabled]="registerForm.invalid" (click)="onRegister()">
              Register
            </button>
          </form>

          <div class="switch-role text-center mt-3">
            <button type="button" class="btn btn-link" (click)="flipCard()">Back to Personal Info</button>
            <div>
              <span>Already have an account? <a routerLink="/login">Login</a></span>
            </div>
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

<style>
.main-wrapper {
  height: 100vh;
  background: linear-gradient(135deg, #0f2027, #203a43, #2c5364);
  color: white;
}
.fixed-side-img {
  height: 80vh;
  position: absolute;
  left: 5%;
  top: 10%;
}
.home-card {
  background-color: #1f1f2e;
  border-radius: 1.5rem;
  width: 100%;
  max-width: 500px;
  position: relative;
  z-index: 1;
}
.highlight-text {
  color: #86ceeb;
  font-weight: 600;
}
.text-link {
  color: #ccc;
  text-decoration: none;
  transition: 0.3s;
}
.text-link:hover {
  color: #fff;
  text-decoration: underline;
}
.btn-custom {
  background: linear-gradient(to right, #7ed6df, #70a1ff);
  color: white;
  border: none;
  border-radius: 25px;
  padding: 0.75rem;
  font-weight: bold;
  transition: all 0.3s ease;
}
.btn-animated:hover {
  transform: scale(1.05);
  background: linear-gradient(to right, #70a1ff, #7ed6df);
}
.flip-card-container {
  perspective: 1000px;
}
.flip-card-inner {
  position: relative;
  width: 100%;
  transform-style: preserve-3d;
  transition: transform 0.6s;
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
  z-index: 1;
}
.error {
  color: #ff6b6b;
  font-size: 0.85rem;
  margin-top: -10px;
  margin-bottom: 10px;
}
</style>
