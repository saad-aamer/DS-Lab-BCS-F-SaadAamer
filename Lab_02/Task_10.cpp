#include <iostream>
using namespace std;

class book {
    int id;
public:
    book() : id(0) {}
    book(int i) : id(i) {}
    int getId() const { return id; }
    void display() const {
        cout << "Book ID: " << id << endl;
    }
};

class category {
    string category_name;
    int no_of_books;
    book* b;  
public:
    category() : category_name(""), no_of_books(0), b(nullptr) {}

    category(string n, int n_books, book* books)
        : category_name(n), no_of_books(n_books) {
        b = new book[no_of_books];
        for (int i = 0; i < no_of_books; ++i) {
            b[i] = books[i];
        }
    }

    category(const category& other) {
        category_name = other.category_name;
        no_of_books = other.no_of_books;
        if (no_of_books > 0) {
            b = new book[no_of_books];
            for (int i = 0; i < no_of_books; ++i) {
                b[i] = other.b[i];
            }
        } else {
            b = nullptr;
        }
    }

    category& operator=(const category& other) {
        if (this == &other) return *this; 
        category_name = other.category_name;
        no_of_books = other.no_of_books;
        delete[] b;  
        if (no_of_books > 0) {
            b = new book[no_of_books];
            for (int i = 0; i < no_of_books; ++i) {
                b[i] = other.b[i];
            }
        } else {
            b = nullptr;
        }
        return *this;
    }

    void display() {
        cout << "Category: " << category_name << endl;
        cout << "Number of books: " << no_of_books << endl;
        for (int i = 0; i < no_of_books; ++i) {
            b[i].display();
        }
    }

    bool searchBook(int search_id) {
        for (int i = 0; i < no_of_books; i++) {
            if (b[i].getId() == search_id) {
                cout << "Book with ID " << search_id << " is available in category: " << category_name << endl;
                return true;
            }
        }
        return false;
    }

    ~category() {
        delete[] b;
    }
};

int main() {
    
    book* fiction_books = new book[2];
    fiction_books[0] = book(101);
    fiction_books[1] = book(102);

    
    book* science_books = new book[3];
    science_books[0] = book(201);
    science_books[1] = book(202);
    science_books[2] = book(203);

    
    category* categories = new category[2];
    categories[0] = category("Fiction", 2, fiction_books);
    categories[1] = category("Science", 3, science_books);

    
    categories[0].display();
    categories[1].display();

    
    int search_id;
    cout << "Enter Book ID to search: ";
    cin >> search_id;

    bool found = false;
    for (int i = 0; i < 2; i++) {
        if (categories[i].searchBook(search_id)) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book with ID " << search_id << " is not available in library." << endl;
    }

  
    delete[] fiction_books;
    delete[] science_books;
    delete[] categories;

    return 0;
}
