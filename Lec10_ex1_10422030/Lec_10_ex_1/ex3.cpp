#include <iostream>

using namespace std;

class number_class {
private:
    int value;

public:
    // Constructor
    number_class(int val = 0) : value(val) {}

    // ex2
    // Overload operator+ just for a + b
    number_class operator+(const number_class& other) {
        return number_class(value + other.value);
    }

    //Ex3 add here
    // Overload operator-, then add "-", a + b - c
    number_class operator-(const number_class& other) {
        return number_class(value - other.value);
    }

    // Print value
    void print_value() const {
        cout << value << endl; //the result after compute a + b - c
    }
};

int main() {
    number_class a(30); // let a is 30
    number_class b(60); // let b is 60
    number_class c(8); // let c is 8

    number_class result = a + b - c; // call the operator

    // print the result
    cout << "a + b - c = ";

    result.print_value();

    return 0;
}
