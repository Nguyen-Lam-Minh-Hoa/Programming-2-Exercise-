#include <iostream>

using namespace std;

class number_class {
private:
    int value; // value will int

public:
    // Constructor
    number_class(int val = 0) : value(val) {}

    // Overloaded + operator 
    number_class operator+(const number_class& other) {
        return number_class(value + other.value);
    }

    // Print function
    void print_value() const {
        cout << value << endl; // the result is here
    }
};

int main() {
    number_class a(30); //set a with 30
    number_class b(60); //set b with 60

    number_class c = a + b; // Calls operator+()

    cout << "a + b = ";
    // print the result
    c.print_value(); 

    return 0;
}
