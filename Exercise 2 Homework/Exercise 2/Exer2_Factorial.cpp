#include <iostream>  
using namespace std; 

// Function prototype (declaration)
long long factorial(int n); 

int main() {
    // Variable to store user input
    int num; 

    // Prompt user for input
    cout << "Please enter a non-negative integer: "; 
    // Read input from user
    cin >> num; 
    
    // Check if input is negative
    if (num < 0) {  
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        // Compute and display factorial
        cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    }

    return 0; 
}

// Recursive function to compute factorial
long long factorial(int n) {
    if (n == 0 || n == 1)  // Base case: factorial of 0 or 1 is 1
        return 1;
    return n * factorial(n - 1);  // Recursive case: n! = n * (n-1)!
}