import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { tap } from 'rxjs';
@Injectable({
  providedIn: 'root'
})
export class AuthService {
  private apiUrl = 'http://localhost:2024/login'; // Adjust according to backend
  private memberName: string | null = null; 

  constructor(private http: HttpClient) {}

  
  login(credentials: { email: string; password: string }): Observable<any> {
    return this.http.post(`${this.apiUrl}/member`, credentials); // For members
  }

 
loginAdmin(credentials: { email: string; password: string }): Observable<any> {
    return this.http.post(`${this.apiUrl}/admin`, credentials).pipe(
      tap((response: any) => {
        this.storeToken(response.token);
      })
    );
  }
  
  register(user: any): Observable<any> {
    return this.http.post(`${this.apiUrl}/register`, user);
  }

  storeToken(token: string): void {
    localStorage.setItem('jwtToken', token);
  }

  getToken(): string | null {
    if (typeof window !== 'undefined') {
      return localStorage.getItem('jwtToken');
    }
    return null;
  }

  removeToken(): void {
    localStorage.removeItem('jwtToken');
  }

  

  clearToken() {
    localStorage.removeItem('authToken');
    }

    setCurrentMemberName(name: string) {
      this.memberName = name;
      localStorage.setItem('memberName', name); // Optional: Persist name in localStorage
    }
  
    getCurrentMemberName(): string {
      const member = JSON.parse(localStorage.getItem('memberName') ||'{}');
      return member ? this.memberName || '' ;
    }

  checkEmailExists(email: string): Observable<boolean> {
    return this.http.get<boolean>(`${this.apiUrl}/check-email/${email}`);
  }
  
  checkPhoneExists(phone: string): Observable<boolean> {
    return this.http.get<boolean>(`${this.apiUrl}/check-phone/${phone}`);
  }

  getUserRole(): string {
    const token = this.getToken();
    if (token) {
      const payload = JSON.parse(atob(token.split('.')[1]));
      return payload.role; // Extract role from JWT token
    }
    return '';
  }

  isAuthenticated(): boolean {
    return typeof window !== 'undefined' && !!this.getToken();
  }
  
}
