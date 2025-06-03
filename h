<div class="main-wrapper d-flex justify-content-center align-items-center">
  <div class="login-card-container">
    <div class="flipper" [class.flipped]="isFlipped">

      <!-- FRONT: MEMBER LOGIN -->
      <div class="card-face front d-flex flex-column flex-md-row">
        <div class="image-side d-none d-md-block">
          <img src="./assets/member-login.png" alt="Member Illustration" />
        </div>
        <div class="form-side">
          <div class="card-header">
            <img src="./assets/logoo.gif" class="logo-img" alt="Logo" />
            <h4 class="library-title">Library System</h4>
          </div>
          <h2>Member Login</h2>
          <form [formGroup]="loginForm">
            <input type="email" formControlName="email" placeholder="Email" />
            <input type="password" formControlName="password" placeholder="Password" />
            <button type="button" class="btn-custom" [disabled]="loginForm.invalid" (click)="onLogin()">Login</button>
          </form>
          <button class="btn-link mt-2" (click)="flipToAdmin()">Switch to Admin</button>
        </div>
      </div>

      <!-- BACK: ADMIN LOGIN -->
      <div class="card-face back d-flex flex-column flex-md-row">
        <div class="image-side d-none d-md-block">
          <img src="./assets/admin-login.png" alt="Admin Illustration" />
        </div>
        <div class="form-side">
          <div class="card-header">
            <img src="./assets/logoo.gif" class="logo-img" alt="Logo" />
            <h4 class="library-title">Library System</h4>
          </div>
          <h2>Admin Login</h2>
          <form [formGroup]="loginForm">
            <input type="email" formControlName="email" placeholder="Admin Email" />
            <input type="password" formControlName="password" placeholder="Admin Password" />
            <button type="button" class="btn-custom" [disabled]="loginForm.invalid" (click)="onLogin()">Login</button>
          </form>
          <button class="btn-link mt-2" (click)="flipToMember()">Switch to Member</button>
        </div>
      </div>

    </div>
  </div>
</div>


isFlipped = false;

flipToAdmin() {
  this.isFlipped = true;
}

flipToMember() {
  this.isFlipped = false;
}


.main-wrapper {
  min-height: 100vh;
  background: linear-gradient(to right, #1C1C1E, #4B0082);
  padding: 40px 20px;
}

.login-card-container {
  perspective: 1500px;
  width: 100%;
  max-width: 900px;
}

.flipper {
  position: relative;
  width: 100%;
  transform-style: preserve-3d;
  transition: transform 0.8s ease-in-out;
}

.flipper.flipped {
  transform: rotateY(180deg);
}

.card-face {
  position: absolute;
  width: 100%;
  min-height: 500px;
  background: white;
  border-radius: 20px;
  box-shadow: 0 12px 30px rgba(0, 0, 0, 0.15);
  display: flex;
  flex-direction: column;
  backface-visibility: hidden;
  overflow: hidden;
}

.card-face.back {
  transform: rotateY(180deg);
}

.image-side {
  flex: 1;
  background: #f7f7f7;
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 20px;

  img {
    max-width: 100%;
    height: auto;
  }
}

.form-side {
  flex: 1;
  padding: 30px;
  display: flex;
  flex-direction: column;
  justify-content: center;

  h2 {
    margin-bottom: 20px;
    color: #4B0082;
  }

  form {
    display: flex;
    flex-direction: column;

    input {
      margin-bottom: 12px;
      padding: 12px;
      border: 1px solid #ccc;
      border-radius: 8px;
    }

    .btn-custom {
      background-color: #4B0082;
      color: white;
      border: none;
      padding: 12px;
      border-radius: 8px;
      margin-top: 10px;
      transition: background 0.3s;
    }

    .btn-custom:hover {
      background-color: #6A0DAD;
    }
  }

  .btn-link {
    background: none;
    border: none;
    color: #4B0082;
    text-decoration: underline;
    cursor: pointer;
  }
}

.card-header {
  display: flex;
  align-items: center;
  gap: 10px;
  margin-bottom: 20px;

  .logo-img {
    width: 40px;
    height: 40px;
  }

  .library-title {
    font-size: 1.2rem;
    font-weight: bold;
    color: #4B0082;
  }
}

@media (max-width: 768px) {
  .card-face {
    flex-direction: column;
  }

  .image-side {
    display: none !important;
  }

  .form-side {
    padding: 20px;
  }
}
