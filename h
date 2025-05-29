<!-- dashboard.component.html -->
<div class="d-flex" id="wrapper">
  <!-- Sidebar -->
  <div class="bg-dark border-right" id="sidebar-wrapper">
    <div class="sidebar-heading text-white">Library System</div>
    <div class="list-group list-group-flush">
      <a href="#" class="list-group-item list-group-item-action bg-dark text-white">Dashboard</a>
      <a href="#" class="list-group-item list-group-item-action bg-dark text-white">Books</a>
      <a href="#" class="list-group-item list-group-item-action bg-dark text-white">Members</a>
      <a href="#" class="list-group-item list-group-item-action bg-dark text-white">Borrow/Return</a>
      <a href="#" class="list-group-item list-group-item-action bg-dark text-white">Reports</a>
      <a href="#" class="list-group-item list-group-item-action bg-dark text-white">Settings</a>
    </div>
  </div>

  <!-- Page Content -->
  <div id="page-content-wrapper">
    <nav class="navbar navbar-expand-lg navbar-light bg-light border-bottom">
      <button class="btn btn-primary" id="menu-toggle">Toggle Menu</button>
      <div class="ml-auto d-flex">
        <span class="navbar-text mr-3">Welcome, Admin</span>
        <button class="btn btn-outline-danger">Logout</button>
      </div>
    </nav>

    <div class="container-fluid mt-4">
      <h1 class="mt-4 dashboard-title">Dashboard</h1>
      <div class="row mt-4">
        <div class="col-md-3">
          <div class="card text-white bg-primary mb-3 card-box">
            <div class="card-body">
              <h5 class="card-title">Total Books</h5>
              <p class="card-text display-4">1240</p>
            </div>
          </div>
        </div>
        <div class="col-md-3">
          <div class="card text-white bg-success mb-3 card-box">
            <div class="card-body">
              <h5 class="card-title">Members</h5>
              <p class="card-text display-4">320</p>
            </div>
          </div>
        </div>
        <div class="col-md-3">
          <div class="card text-white bg-warning mb-3 card-box">
            <div class="card-body">
              <h5 class="card-title">Issued Books</h5>
              <p class="card-text display-4">450</p>
            </div>
          </div>
        </div>
        <div class="col-md-3">
          <div class="card text-white bg-danger mb-3 card-box">
            <div class="card-body">
              <h5 class="card-title">Overdue</h5>
              <p class="card-text display-4">15</p>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>

<!-- dashboard.component.css -->
<style>
#wrapper {
  display: flex;
}

#sidebar-wrapper {
  min-width: 250px;
  max-width: 250px;
  background-color: #343a40;
  color: white;
}

#page-content-wrapper {
  flex: 1;
  padding: 20px;
}

#wrapper.toggled #sidebar-wrapper {
  margin-left: -250px;
}

.card-box {
  cursor: pointer;
  transition: transform 0.3s ease;
}

.card-box:hover {
  transform: scale(1.05);
}

.dashboard-title {
  font-weight: bold;
  font-size: 2rem;
  opacity: 0;
}
</style>

<!-- dashboard.component.ts -->
import { Component, AfterViewInit } from '@angular/core';
import gsap from 'gsap';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.css']
})
export class DashboardComponent implements AfterViewInit {
  ngAfterViewInit() {
    gsap.from(".dashboard-title", { duration: 1, y: -50, opacity: 0, ease: "bounce" });
    gsap.from(".card-box", {
      duration: 1,
      opacity: 0,
      stagger: 0.2,
      y: 30,
      ease: "power3.out"
    });
  }
}

<!-- angular.json snippet -->
"styles": [
  "node_modules/bootstrap/dist/css/bootstrap.min.css",
  "src/styles.css"
],
"scripts": [
  "node_modules/bootstrap/dist/js/bootstrap.bundle.min.js"
]

<!-- Install GSAP via npm -->
// Run this command in your terminal:
npm install gsap