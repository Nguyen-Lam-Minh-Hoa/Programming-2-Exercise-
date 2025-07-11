#include <iostream>
#include <vector> // for container class
#include <cmath> // sqrt, fabs

using namespace std;

//Template class for int, float, ....
template<typename T>
class Matrix {
private:
    vector<vector<T>> data; // 2d array to store elements for Matrix
    size_t n; //size of the Matrix

public:
    //constructor initializes the matrix nxn
    Matrix(size_t size) : n(size) {
        data.resize(n, vector<T>(n));
    }

    //function to input matrix elements
    void input() {
        cout << "Please enter the elements (" << n << "x" << n <<"):" << endl;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // Frobenius norm
    T frobrnius_norm() const {
        T sum = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                sum += data[i][j] * data[i][j]; // square the element of the array nxn
            }
        }
        return sqrt(sum); //sqrt (sum)
    }
    
    // Row sum norm 
    T row_sum_norm() const {
        T max_row_sum = 0;
        for (size_t i = 0; i < n; ++i) {
            T row_sum = 0;
            for (size_t j = 0; j < n; ++j) {
                row_sum += fabs(data[i][j]); // add abs value each elements
            }
            // on first row, new max is found, max_row_sum change
            if (i == 0 || row_sum > max_row_sum) {
                max_row_sum = row_sum;
            }
        }
        return max_row_sum;
    }

    // Total norm: n * max abs in matrix
    T total_norm() const {
        T max_value = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                T abs_value = fabs(data[i][j]);
                // if new max is found or on first element => max_value change
                if (i == 0 && j == 0 || abs_value > max_value) {
                    max_value = abs_value;
                }
            }
        }
        return n * max_value; // max * n
    }
};

// main function
int main () {
    size_t  size; 
    cout << "Please enter the matrix size nxn: ";
    cin >> size;

    Matrix<double> mat(size); // create a matrix of type double
    mat.input(); //Input matrix values

    // display three norms
    cout << "Frobenius norm: " << mat.frobrnius_norm() << endl;
    cout << "Row sum norm: " << mat.row_sum_norm() << endl;
    cout << "Total norm: " << mat.total_norm() << endl;

    return 0;
}
