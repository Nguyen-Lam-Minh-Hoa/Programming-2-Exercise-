#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Structure to represent a complex number
struct Complex_number {
    double real; // Real part
    double imag; // Imaginary part
    double magnitude; // Magnitude of the complex number
};

// Function prototypes
double calculate_magnitude(double real, double imag);
void read_complex_numbers(Complex_number* numbers, int n, const string &filename);
void sort_complex_numbers(Complex_number* numbers, int n);
void print_top_5(Complex_number* numbers, int n);

int main() {
    ifstream input_file("In.txt");
    if (!input_file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    int n;
    input_file >> n; // Read the number of complex numbers
    input_file.close();
    
    Complex_number* numbers = new Complex_number[n]; // Dynamically allocate array
    // Read complex numbers from file
    read_complex_numbers(numbers, n, "In.txt"); 
    // Sort numbers by magnitude in descending order
    sort_complex_numbers(numbers, n); 
    // Print the top 5 largest magnitude complex numbers
    print_top_5(numbers, n); 
    
    delete[] numbers; // Free allocated memory

    
    return 0; 
}

// Function to calculate the magnitude of a complex number
double calculate_magnitude(double real, double imag) {
    return sqrt(real * real + imag * imag); //using the Pythagorean theorem
}

// Function to read complex numbers from a file
void read_complex_numbers(Complex_number* numbers, int n, const string &filename) {
    // Open the input file
    ifstream input_file(filename); 
    
    // Check if the file is opened successfully
    if (!input_file) { 
        cerr << "Error opening file!" << endl;
        exit(1); // Exit the program if file opening fails
    }
    
    // Skip the first line (number of complex numbers)
    int temp_n; 
    input_file >> temp_n; 

    for (int i = 0; i < n; ++i) {
        // Read real and imaginary parts
        input_file >> numbers[i].real >> numbers[i].imag; 
        // Compute magnitude
        numbers[i].magnitude = calculate_magnitude(numbers[i].real, numbers[i].imag); 
    }
    
    // Close the input file
    input_file.close();
}

// Function to sort the complex numbers based on magnitude in descending order
void sort_complex_numbers(Complex_number* numbers, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (numbers[i].magnitude < numbers[j].magnitude) { // Swap if needed
                swap(numbers[i], numbers[j]);
            }
        }
    }
}

// Function to print the top 5 complex numbers with the largest magnitude
void print_top_5(Complex_number* numbers, int n) {
    cout << "The 5 largest magnitude complex numbers are:" << endl;
    // Ensure we do not exceed the available numbers
    int count = min(5, n); 
    
    // Print the complex number
    for (int i = 0; i < count; ++i) {
        cout << numbers[i].real << " " << numbers[i].imag << endl; 
    }
}
