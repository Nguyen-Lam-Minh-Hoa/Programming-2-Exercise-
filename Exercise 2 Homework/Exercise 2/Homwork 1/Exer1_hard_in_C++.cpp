// swap a and b with function and pointer
#include <iostream>
using namespace std;

void swap(int *a, int *b);

int main() {
    int a, b;

    // Input two integers
    cout << "Enter two integers: ";
    cin >> a >> b;

    // Print before swapping
    cout << "Before swap: a = " << a << ", b = " << b << endl;

    // Call swap function
    swap(&a, &b);

    // Print after swapping
    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0;
}

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
