import { Component, OnInit } from '@angular/core';
import { BorrowService } from '../../../service/borrowBooks/borrow.service';
import { Router } from '@angular/router';
 
@Component({
  selector: 'app-borrow-return',
  standalone: false,
  templateUrl: './borrow-return.component.html',
  styleUrl: './borrow-return.component.css'
})
export class BorrowReturnComponent implements OnInit {
  showSidebar: boolean = false;
  showProfileCard: boolean = false;
  member: any = {};
 
  borrowHistory: any[] = [];
  filteredBorrowHistory: any[] = [];
  currentPage: number = 0;
  totalPages: number = 0;
 
  searchQuery: string = '';
  selectedCategory: string = 'book';
  notFoundMessage: string = '';
 
  constructor(private borrowService: BorrowService, private router: Router) {}
 
  ngOnInit(): void {
    const storedMember = localStorage.getItem('loggedInMember');
    if (storedMember && storedMember !== 'undefined') {
      try {
        this.member = JSON.parse(storedMember);
      } catch (error) {
        console.error('Error parsing member data:', error);
      }
    }
 
    this.fetchBorrowHistory();
  }
 
  toggleSidebar(): void {
    this.showSidebar = !this.showSidebar;
  }
 
  toggleProfileCard(): void {
    this.showProfileCard = !this.showProfileCard;
  }
 
  logout(): void {
    localStorage.removeItem('jwtToken');
    localStorage.removeItem('memberId');
    this.router.navigate(['/login']);
    console.log('User logged out successfully');
  }
 
  fetchBorrowHistory(): void {
    const memberName = this.member?.name;
    if (!memberName) {
      console.warn('❌ No valid member name found in localStorage.');
      return;
    }
 
    this.borrowService.getHistoryByMember(memberName, this.currentPage).subscribe(
      (response) => {
        console.log('🔍 Borrow History API Response:', response);
        this.borrowHistory = response.content || response;
        this.filteredBorrowHistory = [...this.borrowHistory];
        this.totalPages = response.totalPages || 1;
      },
      (error) => {
        console.error('❌ Error fetching borrow history:', error);
      }
    );
  }
 
  returnBook(title: string): void {
    const memberName = this.member?.name;
 
    if (!memberName) {
      alert('❌ No valid member name found! Please log in again.');
      return;
    }
 
    this.borrowService.returnBook(title, memberName).subscribe(
      (response) => {
        console.log('✅ Return API Response:', response);
        alert(`${response.Messages}\nBook: ${response.BookTitle}\nReturned on: ${response.ReturnDate}`);
        this.fetchBorrowHistory();
      },
      (error) => {
        console.error('❌ Return API Error:', error);
        alert('Error returning book: ' + JSON.stringify(error));
      }
    );
  }
 
  searchBorrowHistory(): void {
    const query = this.searchQuery.trim().toLowerCase();
 
    if (!query) {
      this.filteredBorrowHistory = [...this.borrowHistory];
      this.notFoundMessage = '';
      return;
    }
 
    const matchStartsWith = (text: string | null) => {
      if (!text) return false;
      const words = text.toLowerCase().split(' ').filter(word => word);
      return words.some(word => word.startsWith(query));
    };
 
    this.filteredBorrowHistory = this.borrowHistory.filter(record => {
      switch (this.selectedCategory) {
        case 'book':
          return matchStartsWith(record.book?.title);
        case 'borrowDate':
          return record.borrowDate && new Date(record.borrowDate).toLocaleDateString().startsWith(query);
        case 'returnDate':
          return record.returnDate && new Date(record.returnDate).toLocaleDateString().startsWith(query);
        case 'bookReturnOn':
          return record.bookReturnOn && new Date(record.bookReturnOn).toLocaleDateString().startsWith(query);
        case 'status':
          return matchStartsWith(record.status);
        default:
          return false;
      }
    });
 
    this.notFoundMessage = this.filteredBorrowHistory.length === 0 ? 'No matching records found.' : '';
  }
 
  nextPage(): void {
    if (this.currentPage < this.totalPages - 1) {
      this.currentPage++;
      this.fetchBorrowHistory();
    }
  }
 
  previousPage(): void {
    if (this.currentPage > 0) {
      this.currentPage--;
      this.fetchBorrowHistory();
    }
  }
 
  goToUserDashboard(): void {
    this.router.navigate(['/member-dashboard']);
  }
}
 


    @PreAuthorize("hasAuthority('MEMBER')")
    @GetMapping("/{name}/{page}")
    public ResponseEntity<Page<Fine>> getFineHistoryByMemberName(@PathVariable String name, @PathVariable int page) {
        return ResponseEntity.ok(fineService.getFineHistoryByMemberName(name, page));
    }

    @PreAuthorize("hasAuthority('MEMBER')")
    @PostMapping("/pay/{id}")
    public ResponseEntity<Fine> payFine(@PathVariable int id) {
        Fine paidFine = fineService.payFine(id);
        return ResponseEntity.ok(paidFine);
    }

   @PreAuthorize("hasAuthority('MEMBER')")
	@PostMapping("/return/{title}/{name}")
	public ResponseEntity<?> returnBook(@PathVariable String title, @PathVariable String name) {
		BorrowTransaction returnTransaction = borrowService.returnBookByTitleAndName(title, name);
		Map<String, Object> response = new HashMap<String, Object>();
		response.put("Messages", "Book returned successfully!");
		response.put("BorrowId", returnTransaction.getBorrowId());
		response.put("MemberName", returnTransaction.getMember().getName());
		response.put("BookTitle", returnTransaction.getBook().getTitle());
		response.put("BorrowDate", returnTransaction.getBorrowDate());
		response.put("ReturnDate", returnTransaction.getBookReturnOn());

		return new ResponseEntity<>(response, HttpStatus.OK);
	}

  public BorrowTransaction returnBookByTitleAndName(String title, String name) {
    	log.info("Returning book with title '{}' for member '{}'", title, name);
    	
        List<BorrowTransaction> borrowHistory = borrowRepository.findByMemberNameAndBookTitleAndStatus(name, title, "borrowed");
 
        if (borrowHistory.isEmpty()) {
        	log.warn("No books titled {} is borrowed by {}",title,name);
            throw new ResourceNotAvailableException("No active borrow record found");
        }
 
        BorrowTransaction borrowTransaction = borrowHistory.get(0);
        
        borrowTransaction.setStatus("returned");
        borrowTransaction.setReturnDate(borrowTransaction.getReturnDate());;
        borrowTransaction.setBookReturnOn(LocalDate.now());
        borrowRepository.save(borrowTransaction);
 
        Book book = borrowTransaction.getBook();
        book.setStatus("available");
        bookRepository.save(book);
 
        AvailableCopies count = availableCopiesRepository.findByIsbn(book.getIsbn())
        		.orElseThrow(() -> {
                    log.warn("Available copy info not found for ISBN '{}'", book.getIsbn());
                    return new BookNotFoundException("Available copy info not found");
                });   
        
        count.setCount(count.getCount() + 1);
        availableCopiesRepository.save(count);
        log.info("Book '{}' successfully returned by '{}'", title, name);
        return borrowTransaction;
    }

  public List<Fine> getFinesByMember(Member member) {
    	log.info("Fetching fine details by member {}",member);
        return fineRepository.findByMember(member);
    }

    public Fine payFine(int fineId) {
    	log.info("Paying fines by fineId {}",fineId);
        Fine fine = fineRepository.findById(fineId)
                .orElseThrow(() -> new ResourceNotAvailableException("Fine not found with id: " + fineId));

        BorrowTransaction borrowTransaction = fine.getBorrowTransaction();
        if (!"returned".equals(borrowTransaction.getStatus())) {
            throw new IllegalStateException("Please return the book and pay the fine.");
        }

        fine.setStatus("paid");
        fine.setPaymentDate(LocalDate.now());
        return fineRepository.save(fine);
    }
