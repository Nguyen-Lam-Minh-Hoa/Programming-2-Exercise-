#include <iostream>

using namespace std;

class counter_class {
private:
    int value;

public:
    // Constructor
    counter_class(int val = 0) : value(val) {}

    // Prefix ++ overload
    counter_class& operator++() {
        ++value;
        return *this;
    }

    // Postfix ++ overload 
    counter_class operator++(int) {
        counter_class temp = *this; // save current state
        ++value;                   // increment current
        return temp;                // return saved
    }

    // For printing
    void print_value() const {
        cout << value << endl;
    }
};

int main() {
    counter_class counter(7); // set initial value to 7

    cout << "The initial value is: ";
    counter.print_value();

    // Prefix increment
    ++counter;
    cout << "After prefix ++counter: ";
    counter.print_value();

    // Postfix increment
    counter++;
    cout << "After postfix counter++: ";
    counter.print_value();

    return 0;
}
