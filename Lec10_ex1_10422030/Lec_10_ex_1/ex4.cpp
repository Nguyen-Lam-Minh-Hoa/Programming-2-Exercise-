#include <iostream>

using namespace std;

class number_class {
private:
    int value;

public:
    // Constructor
    number_class(int val = 0) : value(val) {}

    // Ex 2 Overload +
    number_class operator+(const number_class& other) const {
        return number_class(value + other.value);
    }

    // Ex3 Overload -
    number_class operator-(const number_class& other) const {
        return number_class(value - other.value);
    }

    // Ex4 Prefix ++ 
    number_class operator++() const {
        return number_class(value + 1);
    }

    // Postfix ++
    number_class operator++(int) const {
        return number_class(value); // return original that no increase
    }

    // Prefix --
    number_class operator--() const {
        return number_class(value - 1);
    }

    // Postfix --
    number_class operator--(int) const {
        return number_class(value); // return original that no decrease
    }

    // Print the value
    void print_value() const {
        cout << value << endl;
    }
};

int main() {
    number_class a(30); // a = 30
    number_class b(60); // b = 60
    number_class c(8);  // c = 8

    // Basic test
    number_class result = a + b - c; 
    cout << "a + b - c = ";
    result.print_value();

    // Apply prefix ++ to the result of a + b - c
    number_class pre_inc = ++(a + b - c);
    cout << "++(a + b - c) = ";
    pre_inc.print_value(); 

    // Apply postfix ++ to the result of a + b - c
    number_class post_inc = (a + b - c)++;
    cout << "(a + b - c)++ = ";
    post_inc.print_value(); 

    // Apply prefix --
    number_class pre_dec = --(a + b - c);
    cout << "--(a + b - c) = ";
    pre_dec.print_value(); 

    // Apply postfix --
    number_class post_dec = (a + b - c)--;
    cout << "(a + b - c)-- = ";
    post_dec.print_value();

    return 0;
}

