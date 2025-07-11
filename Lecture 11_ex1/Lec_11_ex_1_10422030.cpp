// Nguyen Lam Minh Hoa - 10422030
//Implement a function to multiply two matrices of the same data type.
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

// Template class Matrix: works with any data type T (int, float, double, long, etc.)
template<typename T>
class Matrix {
private:
    vector<vector<T>> data;  // 2D vector to store matrix data
    size_t rows, cols;       // number of rows and columns

public:
    // Constructor: initialize matrix with given size, filled with zeros
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r, vector<T>(c, 0)) {}

    // Access element at (r, c) with bounds checking
    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols) throw out_of_range("Index out of range");
        return data[r][c];
    }

    // Const version for read-only access
    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols) throw out_of_range("Index out of range");
        return data[r][c];
    }

    // Input matrix elements from user
    void input() {
        cout << "Enter matrix elements (" << rows << "x" << cols << "):" << endl;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }

    // Print the matrix to the console
    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Matrix multiplication (A * B)
    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows)
            throw invalid_argument("Incompatible matrix sizes for multiplication");

        Matrix<T> result(rows, other.cols);

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                T sum = 0;
                for (size_t k = 0; k < cols; ++k) {
                    sum += data[i][k] * other.at(k, j);
                }
                result.at(i, j) = sum;
            }
        }

        return result;
    }
};

// Template function to handle matrix multiplication for any type
template<typename T>
void run_matrix_multiplication(size_t r1, size_t c1, size_t r2, size_t c2) {
    Matrix<T> A(r1, c1);
    Matrix<T> B(r2, c2);

    cout << "Input for Matrix A:" << endl;
    A.input();

    cout << "Input for Matrix B:" << endl;
    B.input();

    cout << "Matrix A:" << endl;
    A.print();

    cout << "Matrix B:" << endl;
    B.print();

    Matrix<T> C = A * B;

    cout << "Matrix C = A * B:" << endl;
    C.print();
}

int main() {
    size_t r1, c1, r2, c2;

    // Get matrix sizes from user
    cout << "Enter number of rows and columns for Matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter number of rows and columns for Matrix B: ";
    cin >> r2 >> c2;

    // Check multiplication rule: A.cols == B.rows
    if (c1 != r2) {
        cout << "Error: Matrix A's columns must match Matrix B's rows for multiplication." << endl;
        return 1;
    }

    // Let user choose the data type
    cout << "Choose data type:" << endl;
    cout << "1 = int" << endl;
    cout << "2 = float" << endl;
    cout << "3 = double" << endl;
    cout << "4 = long" << endl;
    int typeChoice;
    cin >> typeChoice;

    // Dispatch to the correct template type
    switch (typeChoice) {
        case 1:
            run_matrix_multiplication<int>(r1, c1, r2, c2);
            break;
        case 2:
            run_matrix_multiplication<float>(r1, c1, r2, c2);
            break;
        case 3:
            run_matrix_multiplication<double>(r1, c1, r2, c2);
            break;
        case 4:
            run_matrix_multiplication<long>(r1, c1, r2, c2);
            break;
        default:
            cout << "Invalid type choice." << endl;
            return 1;
    }

    return 0;
}
