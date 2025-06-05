<style>
  body {
    background: linear-gradient(to right, #1C1C1E, #4B0082);
    font-family: 'Segoe UI', sans-serif;
    margin: 0;
    padding: 0;
    min-height: 100vh;
  }

  .container {
    background: #ffffff;
    border-radius: 20px;
    padding: 40px;
    margin-top: 40px;
    box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
    animation: fadeInUp 1s ease forwards;
  }

  .back-button-container {
    margin-bottom: 20px;
  }

  .back-button {
    background-color: #4B0082;
    color: #ffffff;
    border: none;
    padding: 10px 20px;
    font-size: 1rem;
    border-radius: 30px;
    cursor: pointer;
    transition: background-color 0.3s ease, transform 0.3s ease;
  }

  .back-button:hover {
    background-color: #6A0DAD;
    transform: scale(1.05);
    box-shadow: 0 0 10px rgba(106, 13, 173, 0.4);
  }

  h2.text-center {
    font-size: 2rem;
    font-weight: bold;
    background: linear-gradient(90deg, #5e005e, #8e008e);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
  }

  .text-right .btn-success {
    border-radius: 30px;
    padding: 10px 20px;
    font-weight: 500;
    transition: background-color 0.3s ease, transform 0.3s ease;
  }

  .text-right .btn-success:hover {
    background-color: #28a745;
    transform: scale(1.05);
  }

  .card {
    border-radius: 20px;
    transition: transform 0.3s ease;
  }

  .card:hover {
    transform: scale(1.02);
    box-shadow: 0 8px 20px rgba(0, 0, 0, 0.15);
  }

  .btn-warning.btn-sm,
  .btn-danger.btn-sm {
    border-radius: 20px;
    padding: 6px 12px;
    font-size: 0.85rem;
    transition: background-color 0.3s ease, transform 0.3s ease;
  }

  .btn-warning.btn-sm:hover {
    background-color: #ffc107;
    transform: scale(1.05);
  }

  .btn-danger.btn-sm:hover {
    background-color: #dc3545;
    color: #fff;
    transform: scale(1.05);
  }

  .btn-purple {
    background-color: #9370DB;
    color: #fff;
    border: none;
    border-radius: 30px;
    padding: 8px 20px;
    font-weight: 500;
    transition: background-color 0.3s ease, transform 0.3s ease;
  }

  .btn-purple:hover {
    background-color: #B57EDC;
    transform: scale(1.05);
  }

  .btn-purple:disabled {
    background-color: #5e2392;
    color: #f5f5f5;
    cursor: not-allowed;
  }

  .modal-content {
    border-radius: 15px;
    box-shadow: 0 10px 25px rgba(0, 0, 0, 0.3);
  }

  .modal-header,
  .modal-footer {
    border-radius: 15px;
  }

  .modal-title {
    font-weight: bold;
  }

  .modal .form-control {
    border-radius: 10px;
    padding: 10px;
    border: 2px solid #ccc;
    transition: border-color 0.3s ease;
  }

  .modal .form-control:focus {
    border-color: #4B0082;
    outline: none;
  }

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

  @media (max-width: 768px) {
    .container {
      padding: 20px;
    }

    .btn {
      width: 100%;
      margin-bottom: 10px;
    }

    .card-body {
      padding: 1rem;
    }
  }
</style>

<!-- Existing HTML remains unchanged -->
<div class="container mt-4">[...]</div>
