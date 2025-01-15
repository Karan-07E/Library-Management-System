#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

// Class for a Book
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor)
        : id(bookId), title(bookTitle), author(bookAuthor), isIssued(false) {}
};

// Class for a Member
class Member {
public:
    int id; 
    string name;
    vector<int> issuedBooks;

    Member(int memberId, string memberName)
        : id(memberId), name(memberName) {}
};

// Library Management System Class
class Library {
private:
    unordered_map<int, Book> books;       // Book ID -> Book Object
    unordered_map<int, Member> members;  // Member ID -> Member Object

public:
    // Add a new book to the library
    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);

        if (books.find(id) != books.end()) {
            cout << "Book with ID " << id << " already exists!" << endl;
            return;
        }
        books[id] = Book(id, title, author);
        cout << "Book added successfully: " << title << endl;
    }

    // Add a new member
    void addMember() {
        int id;
        string name;
        cout << "Enter Member ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Member Name: ";
        getline(cin, name);

        if (members.find(id) != members.end()) {
            cout << "Member with ID " << id << " already exists!" << endl;
            return;
        }
        members[id] = Member(id, name);
        cout << "Member added successfully: " << name << endl;
    }

void issueBook() {
        int bookId, memberId;
        cout << "Enter Book ID to issue: ";
        cin >> bookId;
        cout << "Enter Member ID: ";
        cin >> memberId;

        if (books.find(bookId) == books.end()) {
            cout << "Book with ID " << bookId << " does not exist!" << endl;
            return;
        }
        if (members.find(memberId) == members.end()) {
            cout << "Member with ID " << memberId << " does not exist!" << endl;
            return;
        }
        if (books[bookId].isIssued) {
            cout << "Book is already issued to another member!" << endl;
            return;
        }

        books[bookId].isIssued = true;
        members[memberId].issuedBooks.push_back(bookId);
        cout << "Book " << books[bookId].title << " issued to " << members[memberId].name << endl;
    }

    // Return a book
    void returnBook() {
        int bookId, memberId;
        cout << "Enter Book ID to return: ";
        cin >> bookId;
        cout << "Enter Member ID: ";
        cin >> memberId;

        if (books.find(bookId) == books.end() || members.find(memberId) == members.end()) {
            cout << "Invalid book or member ID!" << endl;
            return;
        }

        auto &issuedBooks = members[memberId].issuedBooks;
        auto it = find(issuedBooks.begin(), issuedBooks.end(), bookId);
        if (it == issuedBooks.end()) {
            cout << "Book was not issued to this member!" << endl;
            return;
        }

        books[bookId].isIssued = false;
        issuedBooks.erase(it);
        cout << "Book " << books[bookId].title << " returned by " << members[memberId].name << endl;
    }

    // Display all books
    void displayBooks() {
        cout << setw(5) << "ID" << setw(20) << "Title" << setw(20) << "Author" << setw(10) << "Issued" << endl;
        for (const auto &pair : books) {
            const auto &book = pair.second;
            cout << setw(5) << book.id << setw(20) << book.title << setw(20) << book.author
                 << setw(10) << (book.isIssued ? "Yes" : "No") << endl;
        }
    }

    // Display all members
    void displayMembers() {
        cout << setw(5) << "ID" << setw(20) << "Name" << setw(20) << "Issued Books" << endl;
        for (const auto &pair : members) {
            const auto &member = pair.second;
            cout << setw(5) << member.id << setw(20) << member.name << setw(20) << member.issuedBooks.size() << endl;
        }
    }
};

// Main function with a menu-driven interface
int main() {
    Library library;
    int choice;
    do {
        cout << "\n_____ Library Management System _____\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Display All Members\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

    switch (choice) {
        case 1:
            library.addBook();
            break;
        case 2:
            library.addMember();
            break;
        case 3:
            library.issueBook();
            break;
        case 4:
            library.returnBook();
            break;
        case 5:
            library.displayBooks();
            break;
        case 6:
            library.displayMembers();
            break;
        case 7:
            cout << "Exiting the Library Management System. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
//done 
