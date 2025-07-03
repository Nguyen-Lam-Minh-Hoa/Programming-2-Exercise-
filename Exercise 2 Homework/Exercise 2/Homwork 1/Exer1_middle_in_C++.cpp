// program to find sum using function
#include <iostream>
using namespace std;

// Function declaration
int add(int a, int b);

int main() {
    int num_1, num_2;

    // Input two integers
    cout << "Enter two integers: ";
    cin >> num_1 >> num_2;

    // Function call and output result
    cout << "Sum: " << add(num_1, num_2) << endl;

    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}
