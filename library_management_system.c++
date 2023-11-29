#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // Include the algorithm header for std::find

using namespace std;

class Book {
public:
    string bookId;
    string title;
    string author;
    bool available;

    Book(string id, string bookTitle, string bookAuthor)
        : bookId(id), title(bookTitle), author(bookAuthor), available(true) {}

    void displayBook() const {
        cout << "Book ID: " << bookId << ", Title: " << title << ", Author: " << author
             << ", Status: " << (available ? "Available" : "Not Available") << endl;
    }
};

class Patron {
public:
    string patronId;
    string name;
    vector<string> borrowedBooks;

    Patron(string id, string patronName)
        : patronId(id), name(patronName) {}

    void displayPatron() const {
        cout << "Patron ID: " << patronId << ", Name: " << name << endl;
        if (!borrowedBooks.empty()) {
            cout << "Borrowed Books:" << endl;
            for (const auto& book : borrowedBooks) {
                cout << "  " << book << endl;
            }
        } else {
            cout << "No books currently borrowed." << endl;
        }
    }
};

class Library {
public:
    vector<Book> books;
    vector<Patron> patrons;

    void addBook(string bookId, string title, string author) {
        Book newBook(bookId, title, author);
        books.push_back(newBook);
        cout << "Book added successfully." << endl;
    }

    void addPatron(string patronId, string name) {
        Patron newPatron(patronId, name);
        patrons.push_back(newPatron);
        cout << "Patron added successfully." << endl;
    }

    void displayAllBooks() const {
        cout << "All Books:" << endl;
        for (const auto& book : books) {
            book.displayBook();
        }
    }

    void displayAllPatrons() const {
        cout << "All Patrons:" << endl;
        for (const auto& patron : patrons) {
            patron.displayPatron();
        }
    }

    Book* findBook(string bookId) {
        for (auto& book : books) {
            if (book.bookId == bookId) {
                return &book;
            }
        }
        return nullptr;
    }

    Patron* findPatron(string patronId) {
        for (auto& patron : patrons) {
            if (patron.patronId == patronId) {
                return &patron;
            }
        }
        return nullptr;
    }

    void borrowBook(string bookId, string patronId) {
        Book* book = findBook(bookId);
        Patron* patron = findPatron(patronId);

        if (book != nullptr && patron != nullptr && book->available) {
            book->available = false;
            patron->borrowedBooks.push_back(book->title);
            cout << "Book borrowed successfully." << endl;
        } else {
            cout << "Book not available or patron not found." << endl;
        }
    }

    void returnBook(string bookId, string patronId) {
        Book* book = findBook(bookId);
        Patron* patron = findPatron(patronId);

        if (book != nullptr && patron != nullptr && !book->available) {
            book->available = true;
            auto it = std::find(patron->borrowedBooks.begin(), patron->borrowedBooks.end(), book->title);
            if (it != patron->borrowedBooks.end()) {
                patron->borrowedBooks.erase(it);
                cout << "Book returned successfully." << endl;
            }
        } else {
            cout << "Book not borrowed by the patron or not found." << endl;
        }
    }
};

int main() {
    Library library;

    // Adding sample books
    library.addBook("B001", "The Catcher in the Rye", "J.D. Salinger");
    library.addBook("B002", "To Kill a Mockingbird", "Harper Lee");

    // Adding sample patrons
    library.addPatron("P001", "John Doe");
    library.addPatron("P002", "Jane Smith");

    // Displaying all books and patrons
    library.displayAllBooks();
    library.displayAllPatrons();

    // Borrowing and returning books
    library.borrowBook("B001", "P001");
    library.returnBook("B001", "P001");

    // Displaying updated information
    library.displayAllBooks();
    library.displayAllPatrons();

    return 0;
}
