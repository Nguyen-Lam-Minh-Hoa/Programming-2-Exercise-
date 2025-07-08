#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    //Default constructor
    Complex() : real(0), imag(0) {}

    //Parameterized constructor 
    Complex(double real, double imag) : real(real), imag(imag) {}

    //compute the modulus of the complex number
    double modulus() const {
        return sqrt(real * real + imag * imag); // sqrt (a^2 + b^2)
    }

    //overloading >operator to compare modulus
    bool operator>(const Complex& other) const{
        return this->modulus() > other.modulus();
    }

    //overloaded assignment operator
    Complex& operator=(const Complex& other) {
        if (this != &other) { //check for self assignment
            real = other.real; // copy the real part from other object
            imag = other.imag; // copy the imag part from other object
        }
        return *this; //return the current object to allow assignment chain a =b =c
    }

    //display function
    void display() const {
        cout << real;
        if (imag >= 0) {
            cout << " + " << imag << "i";
        }
        else {
            cout << " - " << -imag << "i";
        }
        cout << " -> The Modulus is: " << modulus() << endl;
    }

    //swap function using sorting
    void swap(Complex& other) {
        Complex temp = *this;
        *this = other;
        other = temp;
    }
};

//main function 
int main() {
    int n;
    cout << "Enter number of complex numbers: ";
    cin >> n;

    vector<Complex> list;

    // Input complex numbers
    for (int i = 0; i < n; ++i) {
        double real, imag;
        cout << "Enter real and imaginary part of complex number " << (i + 1) << ": ";
        cin >> real >> imag;
        list.push_back(Complex(real, imag));
    }

    // Manual bubble sort in decreasing order of modulus
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!(list[j] > list[j + 1])) {
                list[j].swap(list[j + 1]);
            }
        }
    }

    // Output sorted complex numbers
    cout << "\nSorted complex numbers by decreasing order:\n";
    for (const Complex& c : list) {
        c.display();
    }
    return 0;
}