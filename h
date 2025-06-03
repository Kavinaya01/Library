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
