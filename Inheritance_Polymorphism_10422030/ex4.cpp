#include <iostream>
using namespace std;

//base class A1
class A1 {
    public:
        A1() {
            cout << "A1 constructor"<<endl;
        }
};
//base class A2
class A2 {
    public:
        A2() {
            cout << "A2 constructor"<<endl;
        }
};
//base class B1
class B1 {
    public:
        B1() {
            cout << "B1 constructor"<<endl;
        }
};
//base class B2
class B2 {
    public:
        B2() {
            cout << "B2 constructor"<<endl;
        }
};

//derived class
class C1 : public A1, public A2 {
    public:
        C1() {
            cout << "C1 constructor" << endl;
        }
};

class C2 : public B1, public B2 {
    public:
        C2() {
            cout << "C2 constructor" << endl;
        }
};
class D : public C1, public C2 {
    public:
        D() {
            cout << "D constructor" << endl;
        }
};

//main function
int main () {
    // create an object
    D obj_D;

    return 0;
}
// explain
// base class constructors are executed first A1 and A2 for C1 and B1 and B2 for C2
// intermediate calss follow C1, C2
// then the derived class constructor D