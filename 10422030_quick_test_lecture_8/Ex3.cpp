#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;  
    int id;       
    string major; 
    int year;     
    double gpa;   

public:
    // Constructor
    Student(string name, int id, string major, int year, double gpa)
        : name(name), id(id), major(major), year(year), gpa(gpa) {}

    // Method to display student information
    void display_info() {
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << id << endl;
        cout << "Major: " << major << endl;
        cout << "Year: " << year << endl;
        cout << "GPA: " << gpa << endl;
    }
}; // end class

// Main function
int main() {
    /
    Student hoa("Hoa", 10422030, "CSE", 2022, 9.0);

    // Display student information
    hoa.display_info();

    return 0;
}
