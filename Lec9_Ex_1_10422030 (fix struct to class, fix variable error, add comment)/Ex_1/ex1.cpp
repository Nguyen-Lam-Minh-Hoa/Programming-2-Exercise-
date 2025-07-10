#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Point {
public:
    int x, y;

    // Constructor to initialize a point with default or given values
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Shape {
protected:
    char type; // Shape type: 't' for triangle, 'r' for rectangle, 's' for square
    vector<Point> vertices; // Stores shape vertices

public:
    Shape(char t) : type(t) {}

    // Pure virtual function to read shape details from a file
    virtual void read_from_file(ifstream& infile) = 0;

    // Pure virtual function to display shape details
    virtual void display() const = 0;

    // Function to get the type of shape
    char get_type() const { return type; }
};

class Triangle : public Shape {
public:
    Triangle() : Shape('t') {}

    // Reads the triangle's three vertices from a file
    void read_from_file(ifstream& infile) override {
        for (int i = 0; i < 3; ++i) {
            int x, y;
            infile >> x >> y;
            vertices.push_back(Point(x, y));
        }
    }

    // Displays triangle vertices
    void display() const override {
        cout << "Triangle: ";
        for (const auto& v : vertices) {
            cout << "(" << v.x << "," << v.y << ") ";
        }
        cout << endl;
    }
};

class Rectangle : public Shape {
public:
    Rectangle() : Shape('r') {}

    // Reads two opposite corners of a rectangle from a file
    void read_from_file(ifstream& infile) override {
        for (int i = 0; i < 2; ++i) {
            int x, y;
            infile >> x >> y;
            vertices.push_back(Point(x, y));
        }
    }

    // Displays rectangle vertices
    void display() const override {
        cout << "Rectangle: ";
        for (const auto& v : vertices) {
            cout << "(" << v.x << "," << v.y << ") ";
        }
        cout << endl;
    }
};

class Square : public Shape {
public:
    Square() : Shape('s') {}

    // Reads two opposite corners of a square from a file
    void read_from_file(ifstream& infile) override {
        for (int i = 0; i < 2; ++i) {
            int x, y;
            infile >> x >> y;
            vertices.push_back(Point(x, y));
        }
    }

    // Displays square vertices
    void display() const override {
        cout << "Square: ";
        for (const auto& v : vertices) {
            cout << "(" << v.x << "," << v.y << ") ";
        }
        cout << endl;
    }
};

class Shape_Manager {
    vector<Shape*> shapes; // Stores all shapes

public:
    // Reads shape data from a file and creates corresponding shape objects
    void read_shapes(const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            cout << "Error opening file.\n";
            return;
        }

        int num_shapes;
        infile >> num_shapes;

        for (int i = 0; i < num_shapes; ++i) {
            char type;
            infile >> type;

            Shape* shape = nullptr;
            if (type == 't') {
                shape = new Triangle();
            } else if (type == 'r') {
                shape = new Rectangle();
            } else if (type == 's') {
                shape = new Square();
            } else {
                cout << "Unknown shape type: " << type << endl;
                continue;
            }

            shape->read_from_file(infile);
            shapes.push_back(shape);
        }

        infile.close();
    }

    // Displays details of all stored shapes
    void display_shapes() const {
        cout << "Read " << shapes.size() << " shapes:\n";
        for (const auto& shape : shapes) {
            shape->display();
        }
    }

    // Destructor to free allocated memory
    ~Shape_Manager() {
        for (auto shape : shapes) {
            delete shape;
        }
    }
};

//main function
int main() {
    Shape_Manager manager;

    // Read shapes from the input file
    manager.read_shapes("input.txt");

    // Display shape information
    manager.display_shapes();

    return 0;
}
