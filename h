/* Registration Page Wrapper */
.register-page {
  min-height: 100vh;
  background: linear-gradient(to right, #1C1C1E, #4B0082);
  display: flex;
  align-items: center;
  justify-content: center;
  position: relative;
  overflow: hidden;
  padding: 20px;
}

/* Fixed left side image (optional, responsive) */
.background-img {
  position: absolute;
  left: 0;
  top: 0;
  width: 100%;
  height: 100%;
  object-fit: cover;
  opacity: 0.1;
  z-index: -1;
}

.floating-img {
  position: absolute;
  bottom: 10px;
  right: 10px;
  width: 150px;
  opacity: 0.4;
  animation: float 6s ease-in-out infinite;
}

@keyframes float {
  0%, 100% {
    transform: translateY(0);
  }
  50% {
    transform: translateY(-10px);
  }
}

/* Register Card Container */
.register-card-wrapper {
  perspective: 1200px;
  width: 100%;
  max-width: 600px;
}

.register-card {
  background-color: #ffffff;
  border-radius: 20px;
  padding: 40px;
  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.3);
  position: relative;
  transition: transform 1s;
  transform-style: preserve-3d;
}

.register-card-wrapper.flipped .register-card {
  transform: rotateY(180deg);
}

/* Card Faces */
.card-face {
  position: absolute;
  width: 100%;
  backface-visibility: hidden;
  top: 0;
  left: 0;
  padding: 10px 0;
}

.card-front {
  z-index: 2;
}

.card-back {
  transform: rotateY(180deg);
}

/* Form Styling */
input[type="text"],
input[type="email"],
input[type="password"] {
  width: 100%;
  padding: 12px 15px;
  font-size: 1rem;
  border: 2px solid #ccc;
  border-radius: 10px;
  margin-bottom: 15px;
  transition: border-color 0.3s;
}

input:focus {
  border-color: #4B0082;
  outline: none;
}

/* Error Message */
.error {
  color: #e74c3c;
  font-size: 0.85rem;
  margin-top: -10px;
  margin-bottom: 10px;
}

/* SVG Button */
.svg-btn {
  position: relative;
  background: none;
  border: none;
  padding: 0;
  cursor: pointer;
  display: flex;
  align-items: center;
  justify-content: center;
  margin-top: 10px;
}

.svg-btn svg {
  transition: stroke 0.3s ease;
}

.svg-btn span {
  position: absolute;
  font-weight: 600;
  color: #4B0082;
  font-size: 1rem;
  pointer-events: none;
}

.svg-btn:hover svg rect {
  stroke: url(#hoverGrad);
  filter: drop-shadow(0 0 5px #680064);
}

/* Register link */
.register-link {
  margin-top: 20px;
  font-size: 0.95rem;
  text-align: center;
}

.register-link a {
  color: #4B0082;
  text-decoration: underline;
  transition: color 0.3s ease;
}

.register-link a:hover {
  color: #8e008e;
}

/* Section Headings */
.card-face h2 {
  text-align: center;
  font-size: 1.8rem;
  font-weight: bold;
  background: linear-gradient(90deg, #5e005e, #8e008e);
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;
  margin-bottom: 25px;
  animation: fadeInDown 0.6s ease;
}

@keyframes fadeInDown {
  from {
    opacity: 0;
    transform: translateY(-20px);
  }
  to {
    opacity: 1;
    transform: translateY(0);
  }
}

/* Responsive */
@media (max-width: 768px) {
  .register-card {
    padding: 25px;
  }
  .floating-img {
    display: none;
  }
  .card-face h2 {
    font-size: 1.4rem;
  }
  input[type="text"],
  input[type="email"],
  input[type="password"] {
    font-size: 0.95rem;
    padding: 10px;
  }
}

/* Entrance animation */
.register-card {
  animation: slideUpFade 1s ease forwards;
}

@keyframes slideUpFade {
  from {
    transform: translateY(40px);
    opacity: 0;
  }
  to {
    transform: translateY(0);
    opacity: 1;
  }
}
