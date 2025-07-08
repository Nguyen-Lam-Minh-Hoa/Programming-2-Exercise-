#include <iostream>
using namespace std;

class number_class {
private:
    int value;

public:
    number_class(int val = 0) : value(val) {}

    // + operator
    number_class operator+(const number_class& other) const {
        return number_class(value + other.value);
    }

    // - operator
    number_class operator-(const number_class& other) const {
        return number_class(value - other.value);
    }

    // Prefix ++ returns non-const reference
    number_class& operator++() {
        ++value;
        return *this;
    }

    // Postfix ++ returns const object
    const number_class operator++(int) {
        number_class temp = *this;
        ++value;
        return temp;
    }

    // Prefix -- returns non-const reference
    number_class& operator--() {
        --value;
        return *this;
    }

    // Postfix -- returns const object
    const number_class operator--(int) {
        number_class temp = *this;
        --value;
        return temp;
    }

    void print_value() const {
        cout << value << endl;
    }
};

int main() {
    number_class a(30);
    number_class b(60);
    number_class c(8);

    number_class result = a + b - c;
    cout << "a + b - c = ";
    result.print_value(); 

    // Prefix ++ 
    number_class pre_inc = ++(a + b - c); 
    cout << "++(a + b - c) = ";
    pre_inc.print_value();

    // Postfix ++ 
    number_class post_inc = (a + b - c)++; 
    cout << "(a + b - c)++ = ";
    post_inc.print_value();

    // Prefix --
    number_class pre_dec = --(a + b - c); 
    cout << "--(a + b - c) = ";
    pre_dec.print_value();

    // Postfix --
    number_class post_dec = (a + b - c)--; 
    cout << "(a + b - c)-- = ";
    post_dec.print_value();

    return 0;
}
