import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable, tap } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class AuthService {
  private apiUrl = 'http://localhost:2024/login';
  private memberName: string | null = null;

  constructor(private http: HttpClient) {}

  login(credentials: { email: string; password: string }): Observable<any> {
    return this.http.post(`${this.apiUrl}/member`, credentials).pipe(
      tap((response: any) => {
        this.storeToken(response.token);
        this.setCurrentMemberName(response.memberName); // ✅ Store member name
      })
    );
  }

  loginAdmin(credentials: { email: string; password: string }): Observable<any> {
    return this.http.post(`${this.apiUrl}/admin`, credentials).pipe(
      tap((response: any) => {
        this.storeToken(response.token);
        this.setCurrentMemberName(response.memberName); // ✅ Store admin name if needed
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

  clearToken(): void {
    localStorage.removeItem('jwtToken');
    localStorage.removeItem('memberName'); // ✅ Clear member name too
  }

  // ✅ FIX: Store and persist member name correctly
  setCurrentMemberName(name: string): void {
    this.memberName = name;
    localStorage.setItem('memberName', name);
  }

  // ✅ FIX: Retrieve member name directly from localStorage
  getCurrentMemberName(): string {
    return localStorage.getItem('memberName') || '';
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
      return payload.role;
    }
    return '';
  }

  isAuthenticated(): boolean {
    return typeof window !== 'undefined' && !!this.getToken();
  }
}
