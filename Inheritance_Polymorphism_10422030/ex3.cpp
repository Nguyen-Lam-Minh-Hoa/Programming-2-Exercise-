#include <iostream>
using namespace std;

//base class
class Shape {
    public:
        virtual void draw() {
            cout << "Drawing a shape" << endl;
        }
};
//derived class Rectangle
class Rectangle: public Shape {
    public:
        void draw() override {
            cout <<"Drawing a rectangle" << endl;
        }
};
//derived class Triangle
class Triangle: public Shape {
    public:
        void draw() override {
            cout <<"Drawing a triangle" << endl;
        }
};
// main function
int main () {
    //creating objects
    Shape* shape1 = new Rectangle();
    Shape* shape2 = new Triangle();

    //call overidden
    shape1->draw();
    shape2->draw();

    //cleaning
    delete shape1;
    delete shape2;

    return 0;
}