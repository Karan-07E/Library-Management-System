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