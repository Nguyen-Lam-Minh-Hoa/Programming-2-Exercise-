#include <iostream>
#include <string>
// Ex_1_10422030
using namespace std;

class Book {
private:
    string author;
    string title;
    string format;
    double price;
    int year;
    string publisher;

public:
    // Constructor
    Book(string auth, string t, string f, double p, int y, string pub) {
        author = auth;
        title = t;
        format = f;
        price = p;
        year = y;
        publisher = pub;
    }

    // display the information for the book
    void display_info() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Format: " << format << endl;
        cout << "Price: $" << price << endl;
        cout << "Year of Publication: " << year << endl;
        cout << "Publisher: " << publisher << endl;
    }
};

int main() {
    // create a book 1 
    Book book_1("Ernest Hemingway", "The old Man and the Sea", "Hardcover", 10.99, 1952, "Scribner");
    // create a book 2
    Book book_2("Albert Camus, Matthew Ward", "The Stranger", "Paperback", 15.99, 1942, "Vintage International");

    // show the book's information
    cout << "\n--Book 1--\n";
    book_1.display_info(); //for book 1
    cout << "\n"; //new line

    cout << "\n--Book 2--\n";
    book_2.display_info(); //for book 2
    cout << "\n"; //new line

    return 0;
}

