#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Represents a Point with x and y coordinates
class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

// Base class for all shapes
class Shape {
protected:
    char type;           // Shape type identifier ('t', 'r', 's', 'p')
    vector<Point> vertices;  // Stores shape vertices
    double area;         // Computed area of shape

public:
    Shape(char t) : type(t), area(0) {}

    // Getter for vertices
    const vector<Point>& get_vertices() const { return vertices; }

    // Abstract function to compute area
    virtual void compute_area() = 0;

    // Abstract function to read shape details from file
    virtual void read_from_file(ifstream& infile) = 0;

    // Abstract function to display shape information
    virtual void display() const = 0;

    // Getter for shape type and area
    char get_type() const { return type; }
    double get_area() const { return area; }
};

// Triangle class
class Triangle : public Shape {
public:
    Triangle() : Shape('t') {}

    void read_from_file(ifstream& infile) override {
        for (int i = 0; i < 3; ++i) {
            int x, y;
            infile >> x >> y;
            vertices.push_back(Point(x, y));
        }
        compute_area();
    }

    void compute_area() override {
        if (vertices.size() == 3) {
            area = fabs(0.5 * (vertices[0].x * (vertices[1].y - vertices[2].y) +
                               vertices[1].x * (vertices[2].y - vertices[0].y) +
                               vertices[2].x * (vertices[0].y - vertices[1].y)));
        }
    }

    void display() const override {
        cout << "Triangle: ";
        for (const auto& v : vertices) {
            cout << "(" << v.x << "," << v.y << ") ";
        }
        cout << "-> Area: " << area << endl;
    }
};

// Rectangle class
class Rectangle : public Shape {
public:
    Rectangle() : Shape('r') {}

    void read_from_file(ifstream& infile) override {
        for (int i = 0; i < 2; ++i) {
            int x, y;
            infile >> x >> y;
            vertices.push_back(Point(x, y));
        }
        compute_area();
    }

    void compute_area() override {
        if (vertices.size() == 2) {
            area = fabs((vertices[1].x - vertices[0].x) * (vertices[1].y - vertices[0].y));
        }
    }

    void display() const override {
        cout << "Rectangle: ";
        for (const auto& v : vertices) {
            cout << "(" << v.x << "," << v.y << ") ";
        }
        cout << "-> Area: " << area << endl;
    }
};

// Square class inherits from Rectangle
class Square : public Rectangle {
public:
    Square() { type = 's'; }
};

// **Parallelogram class**
class Parallelogram : public Shape {
public:
    Parallelogram() : Shape('p') {}

    void read_from_file(ifstream& infile) override {
        for (int i = 0; i < 4; ++i) {  
            int x, y;
            infile >> x >> y;
            vertices.push_back(Point(x, y));
        }
        compute_area();
    }

    void compute_area() override {
        if (vertices.size() == 4) {
            double base = sqrt(pow(vertices[2].x - vertices[1].x, 2) + pow(vertices[2].y - vertices[1].y, 2));
            double height = fabs(vertices[1].y - vertices[0].y);
            area = base * height;
        }
    }

    void display() const override {
        cout << "Parallelogram: ";
        for (const auto& v : vertices) {
            cout << "(" << v.x << "," << v.y << ") ";
        }
        cout << "-> Area: " << area << endl;
    }
};

// Shape_Manager class handles multiple shapes
class Shape_Manager {
    vector<Shape*> shapes; 

public:
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
            if (type == 't') shape = new Triangle();
            else if (type == 'r') shape = new Rectangle();
            else if (type == 's') shape = new Square();
            else if (type == 'p') shape = new Parallelogram();
            else {
                cout << "Unknown shape type: " << type << endl;
                continue;
            }

            shape->read_from_file(infile);
            shapes.push_back(shape);
        }

        infile.close();
        sort_shapes_by_area();
    }

    void sort_shapes_by_area() {
        sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
            return a->get_area() > b->get_area();
        });
    }

    void write_to_file(const string& filename) const {
        ofstream outfile(filename);
        if (!outfile) {
            cout << "Error opening output file.\n";
            return;
        }

        outfile << shapes.size() << endl;
        for (const auto& shape : shapes) {
            outfile << shape->get_type() << " ";
            for (const auto& v : shape->get_vertices()) {
                outfile << v.x << " " << v.y << " ";
            }
            outfile << "-> " << shape->get_area() << endl;
        }
        outfile.close();
    }

    void display_shapes() const {
        cout << "Read " << shapes.size() << " shapes:\n";
        for (const auto& shape : shapes) {
            shape->display();
        }
    }

    ~Shape_Manager() {
        for (auto shape : shapes) {
            delete shape;
        }
    }
};

int main() {
    Shape_Manager manager;

    manager.read_shapes("input.txt");
    manager.display_shapes();
    manager.write_to_file("output.txt");

    cout << "Compute completed.\n";
    return 0;
}

