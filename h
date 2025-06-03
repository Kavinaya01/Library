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



