#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
public:
    virtual void display() const = 0;
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;
public:
    Book() {}
    Book(string t, string a, int p) : title(t), author(a), pages(p) {}
    string getTitle() const { return title; }
    int getPages() const { return pages; }
    void display() const override {
        cout << "Book Title: " << title << "\nAuthor: " << author
             << "\nPages: " << pages << endl;
    }
};

class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;
public:
    Newspaper() {}
    Newspaper(string n, string d, string e) : name(n), date(d), edition(e) {}
    string getName() const { return name; }
    string getEdition() const { return edition; }
    void display() const override {
        cout << "Newspaper Name: " << name << "\nDate: " << date
             << "\nEdition: " << edition << endl;
    }
};

class Library {
private:
    Book books[100];
    Newspaper newspapers[100];
    int bcount{0};   // initialize to 0
    int ncount{0};   // initialize to 0
public:
    void addBook(const Book& b) {
        if (bcount < 100) {
            books[bcount++] = b;
        }
    }
    void addNewspaper(const Newspaper& n) {
        if (ncount < 100) {
            newspapers[ncount++] = n;
        }
    }

    void displayCollection() const {
        cout << "\nBooks:\n";
        for (int i = 0; i < bcount; i++) {
            books[i].display();
        }
        cout << "\nNewspapers:\n";
        for (int i = 0; i < ncount; i++) {
            newspapers[i].display();
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bcount; i++) {
            int s = i;
            for (int j = i + 1; j < bcount; j++) {
                if (books[j].getPages() < books[s].getPages()) {
                    s = j;
                }
            }
            if (s != i) {
                Book temp = books[i];
                books[i] = books[s];
                books[s] = temp;
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < ncount; i++) {
            int s = i;
            for (int j = i + 1; j < ncount; j++) {
                if (newspapers[j].getEdition() < newspapers[s].getEdition()) {
                    s = j;
                }
            }
            if (s != i) {
                Newspaper temp = newspapers[i];
                newspapers[i] = newspapers[s];
                newspapers[s] = temp;
            }
        }
    }

    Book* searchBookByTitle(const string& title) {
        int left = 0, right = bcount - 1; // FIXED
        while (left <= right) {
            int mid = (left + right) / 2;
            if (books[mid].getTitle() == title) {
                return &books[mid];
            } else if (books[mid].getTitle() < title) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(const string& name) {
        int left = 0, right = ncount - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (newspapers[mid].getName() == name) {
                return &newspapers[mid];
            } else if (newspapers[mid].getName() < name) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nullptr;
    }

    void sortBooksByTitle() {
        for (int i = 0; i < bcount; i++) {
            int s = i;
            for (int j = i + 1; j < bcount; j++) {
                if (books[j].getTitle() < books[s].getTitle()) {
                    s = j;
                }
            }
            if (s != i) {
                Book temp = books[i];
                books[i] = books[s];
                books[s] = temp;
            }
        }
    }

    void sortNewspapersByName() {
        for (int i = 0; i < ncount; i++) {
            int s = i;
            for (int j = i + 1; j < ncount; j++) {
                if (newspapers[j].getName() < newspapers[s].getName()) {
                    s = j;
                }
            }
            if (s != i) {
                Newspaper temp = newspapers[i];
                newspapers[i] = newspapers[s];
                newspapers[s] = temp;
            }
        }
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    library.sortBooksByTitle();
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    } else {
        cout << "\nBook not found.\n";
    }

    library.sortNewspapersByName();
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    } else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}
