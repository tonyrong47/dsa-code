// #include <bits/stdc++.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    int id;
    string title, author;
    bool issued;

    Book(int i = 0, string t = "", string a = "", bool iss = false) {
        id = i;
        title = t;
        author = a;
        issued = iss;
    }
};

class Library {
    vector<Book> books;

public:
    void loadFromFile() {
        books.clear();
        ifstream fin("library.txt");
        if (!fin) return;

        int id, iss;
        string title, author;
        while (fin >> id) {
            fin.ignore();
            getline(fin, title);
            getline(fin, author);
            fin >> iss;
            fin.ignore();
            books.push_back(Book(id, title, author, iss));
        }
        fin.close();
    }

    void saveToFile() {
        ofstream fout("library.txt");
        for (auto &b : books) {
            fout << b.id << "\n" << b.title << "\n" << b.author << "\n" << b.issued << "\n";
        }
        fout.close();
    }

    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id; cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        books.push_back(Book(id, title, author, false));
        cout << "Book added successfully!\n";
        saveToFile();
    }

    void viewBooks() {
        cout << "\n--- Library Books ---\n";
        for (auto &b : books) {
            cout << "ID: " << b.id << ", Title: " << b.title 
                 << ", Author: " << b.author 
                 << ", Issued: " << (b.issued ? "Yes" : "No") << endl;
        }
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;
        for (auto &b : books) {
            if (b.id == id) {
                if (!b.issued) {
                    b.issued = true;
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "Book already issued!\n";
                }
                saveToFile();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void returnBook() {
        int id, days;
        cout << "Enter Book ID to return: ";
        cin >> id;
        cout << "Enter number of days kept: ";
        cin >> days;
        for (auto &b : books) {
            if (b.id == id) {
                if (b.issued) {
                    b.issued = false;
                    int fine = (days > 7) ? (days - 7) * 5 : 0;
                    cout << "Book returned successfully!\n";
                    if (fine > 0) cout << "Fine to be paid: Rs. " << fine << endl;
                } else {
                    cout << "Book was not issued!\n";
                }
                saveToFile();
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

int main() {
    Library lib;
    lib.loadFromFile();
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n2. View Books\n3. Issue Book\n4. Return Book\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.viewBooks(); break;
            case 3: lib.issueBook(); break;
            case 4: lib.returnBook(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
