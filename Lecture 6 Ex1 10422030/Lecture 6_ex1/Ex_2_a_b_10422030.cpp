#include <iostream>

//Ex_2_a_b_10422030
using namespace std;

// (question a)
class Rational {
private:
    int num;  //Numerator
    int den;  // denominator

    // find gcd with Euclid (question b)
    int gcd(int a, int b) {
        return (b == 0) ? abs(a) : gcd(b, a % b);
    }
    // simplify the fraction
    void simplify() {
        int gcd_val = gcd(abs(num), abs(den)); // find GCD
        num /= gcd_val;
        den /= gcd_val;

        // make sure the den is positive
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    // default 1/1
    Rational() : num(1), den(1) {}

    // Constructor with den and num
    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("The denominator cannot be zero!");
        }
        num = numerator;
        den = denominator;
        simplify();  //call the simplify()
    }

    // Whole number
    Rational(int whole_number) : num(whole_number), den(1) {}

    // return num
    int numerator() const {
        return num;
    }
    // return den
    int denominator() const {
        return den;
    }
    //show the fraction
    void display() const {
        cout << num << "/" << den << endl;
    }
};

//test question a and b
int main() {
    // create the rational number to test
    Rational r1;              // case default
    Rational r2(4, 8);         // with num and den
    Rational r3(3, -9);        // with num and den, den is negative
    Rational r4(7);            // whole number
    Rational r5(50, 100);      

    // show the result
    cout << "Default Rational (r1): ";
    r1.display();

    cout << "Fraction r2 (4/8) reduced: ";
    r2.display();

    cout << "Fraction r3 (3/-9) reduced: ";
    r3.display();

    cout << "Whole number 7 (r4) represented as fraction: ";
    r4.display();

    cout << "Fraction r5 (50/100) reduced: ";
    r5.display();

    return 0;
}
