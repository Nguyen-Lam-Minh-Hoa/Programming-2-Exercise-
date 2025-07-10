#include <iostream>
#include <vector>

using namespace std;

//Class to represent a reduced fraction
class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int n, int d) : numerator(n), denominator(d) {}

    // Check if this fraction is less than another
    bool is_less_than(const Fraction& other) const {
        return numerator * other.denominator < denominator * other.numerator;
    }

    // Check if this fraction is equal to another
    bool is_equal(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    // Print the fraction in the form a/b
    void print() const {
        cout << numerator << "/" << denominator << " ";
    }
};

// Compute greatest common divisor
int compute_gcd(int a, int b) {
    return b == 0 ? a : compute_gcd(b, a % b);
}

// Simple bubble sort for fractions
void sort_fractions(vector<Fraction>& seq) {
    int n = seq.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!seq[j].is_less_than(seq[j + 1])) {
                Fraction temp = seq[j];
                seq[j] = seq[j + 1];
                seq[j + 1] = temp;
            }
        }
    }
}

// Remove duplicate fractions from the sequence
void remove_duplicates(vector<Fraction>& seq) {
    vector<Fraction> unique_seq;
    for (size_t i = 0; i < seq.size(); ++i) {
        if (unique_seq.empty() || !seq[i].is_equal(unique_seq.back())) {
            unique_seq.push_back(seq[i]);
        }
    }
    seq = unique_seq;
}

//function declaration
void Farey(int n);

int main() {
    int n;
    cout << "Please enter max degree N: ";
    cin >> n;

    Farey(n);  // Call the Farey function

    return 0;
}




// Generate and print Farey sequences up to degree n
void Farey(int n) {
    // Initial sequence F1 = (0/1, 1/1)
    vector<Fraction> sequence;
    sequence.emplace_back(0, 1);
    sequence.emplace_back(1, 1);

    // Print F1
    cout << "F1 = ( ";
    for (const auto& frac : sequence) frac.print();
    cout << ")\n";

    // Generate F2 to Fn
    for (int current_n = 2; current_n <= n; ++current_n) {
        vector<Fraction> new_sequence;

        for (size_t i = 0; i < sequence.size() - 1; ++i) {
            Fraction left = sequence[i];
            Fraction right = sequence[i + 1];

            new_sequence.push_back(left);

            // Insert new fraction if denominators add up to current_n
            int new_num = left.numerator + right.numerator;
            int new_den = left.denominator + right.denominator;

            if (new_den == current_n) {
                int g = compute_gcd(new_num, new_den);
                new_sequence.emplace_back(new_num / g, new_den / g);
            }
        }

        new_sequence.push_back(sequence.back());

        sort_fractions(new_sequence);
        remove_duplicates(new_sequence);
        sequence = new_sequence;

        // Print current sequence
        cout << "F" << current_n << " = ( ";
        for (const auto& frac : sequence) frac.print();
        cout << ")\n";
    }
}
