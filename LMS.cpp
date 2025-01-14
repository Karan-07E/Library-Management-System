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

    

    return 0;
}
