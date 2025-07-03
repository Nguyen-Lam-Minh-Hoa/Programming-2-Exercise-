#include <iostream>
#include <string>

using namespace std;

// Base class Person
class Person {
protected:
    int age;
public:
    void set_age(int n) {
        age = n;
    }
    void hello() {
        cout << "Hello." << endl; // person say hello
    }
};

// Derived class Student
class Student : public Person {
public:
    void go_to_classes() {
        cout << "I'm going to class." << endl; //say go to class
    }
    void show_age() {
        cout << "My age is: " << age << " years old." << endl; // display age
    }
};

// Derived class Teacher
class Teacher : public Person {
private:
    string subject;
public:
    void set_subject(string sub) {
        subject = sub;
    }
    void explain() {
        cout << "The teacher will explain." << endl; // explain
    }
};

// Test class
class student_and_teacher_test {
public:
    static void Run_test() {
        // Creating a Person
        Person person;
        person.hello();

        // Creating a Student and testing methods
        Student student;
        student.set_age(21);
        student.hello();
        student.show_age();
        student.go_to_classes();

        // Creating a Teacher and testing methods
        Teacher teacher;
        teacher.set_age(30);
        teacher.hello();
        teacher.explain();
    }
};

// Main function
int main() {
    student_and_teacher_test::Run_test();
    return 0;
}

