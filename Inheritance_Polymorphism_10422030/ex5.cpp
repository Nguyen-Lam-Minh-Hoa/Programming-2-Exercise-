#include <iostream>
using namespace std;

//base class
class Shape {
    //virtual function
    public: virtual void draw() {
        cout<<"Drawing a shape."<<endl;
    }
};
// derived class circle
class Circle : public Shape {
    public:
        //override base method
        void draw() override {
            cout<<"Drawing a circle."<<endl;
        }
};
// derived class square
class Square : public Shape {
    public:
        //override base method
        void draw() override {
            cout<<"Drawing a square."<<endl;
        }
};
// derived class triangle
class Triangle : public Shape {
    public:
        //override base method
        void draw() override {
            cout<<"Drawing a triangle."<<endl;
        }
};

//main function
int main() {
    // array of shape pointers
    Shape* shapes[3];

    // assign derived class to base class pointer
    shapes[0] = new Circle();
    shapes[1] = new Square();
    shapes[2] = new Triangle();

    //call draw()
    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
    }

    //cleaning
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}