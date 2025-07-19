// oop_example_full.cpp
// Mẫu OOP C++ với chú thích chi tiết các khái niệm, giải thích con trỏ (pointer) và Derived Class

#include <iostream>
#include <string>
using namespace std;

// 1) ADT & Encapsulation: Định nghĩa kiểu dữ liệu Account
class Account {
private:
    double balance;  // private: ẩn thông tin nội bộ
public:
    // Constructor: thiết lập giá trị ban đầu
    Account(double b = 0.0) : balance(b) {}

    // deposit: public interface để thay đổi balance
    void deposit(double amt) { balance += amt; }

    // withdraw: public interface, trả về success/fail
    bool withdraw(double amt) {
        if (amt <= balance) { balance -= amt; return true; }
        return false;
    }

    // getter: const function, chỉ đọc balance
    double getBalance() const { return balance; }
};

// 2) Abstract Base Class & Polymorphism: Shape → Rectangle / Circle
class Shape {
public:
    // Pure virtual function => Shape là abstract class (ADT hình học chung)
    virtual double area() const = 0;

    // Virtual function có định nghĩa sẵn, có thể override
    virtual void display() const {
        cout << "Shape area: " << area() << endl;  // gọi area() qua bảng ảo (vtable)
    }

    // Virtual destructor: đảm bảo giải phóng đúng lớp con khi xóa qua pointer
    virtual ~Shape() {}
};

// 2.1) Derived Class: Rectangle inherits from Shape
// 'public Shape' means Rectangle is a subtype of Shape and gains its interface
class Rectangle : public Shape {
private:
    double width, height;
public:
    // Constructor với initializer list
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override pure virtual method: bắt buộc định nghĩa area()
    double area() const override {
        return width * height;  // rectangle area
    }
};

// 2.2) Derived Class: Circle inherits from Shape
//   public inheritance: Circle "is-a" Shape and must implement pure virtual area()
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    // Override pure virtual method
    double area() const override {
        return 3.14159 * radius * radius;  // circle area
    }
};

// 3) Function Overloading & Operator Overloading: Point
class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload #1: move theo dx, dy
    void move(int dx, int dy) { x += dx; y += dy; }

    // Overload #2: move theo Point khác
    void move(const Point& p) { x += p.x; y += p.y; }

    // Operator overloading: cộng hai điểm
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    // Overload << để in Point dễ dàng
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

// 4) Coercion: ép kiểu ngầm
int combine(int a, int b) { return a + b; }

// 5) Template: hàm generic getMax
template<typename T>
T getMax(const T& a, const T& b) {
    return (a > b) ? a : b;  // hoạt động với mọi kiểu hỗ trợ '>'
}

// 6) Linked List: ADT danh sách liên kết đơn (dynamic memory + pointers)
struct Node {
    int data;
    Node* next;  // Node* là con trỏ, lưu địa chỉ của Node kế tiếp (hoặc nullptr nếu hết)
    Node(int v, Node* n = nullptr) : data(v), next(n) {}
};

class LinkedList {
private:
    Node* head;  // head là con trỏ trỏ tới node đầu của list (nullptr nếu list rỗng)
public:
    LinkedList() : head(nullptr) {}  // nullptr: danh sách khởi tạo rỗng

    // Thêm phần tử vào đầu list
    void addFront(int v) {
        // new Node(v, head): cấp phát động 1 Node mới, next trỏ tới head hiện tại
        head = new Node(v, head);
    }

    // Hiển thị danh sách
    void display() const {
        cout << "List: ";
        // cur: con trỏ di chuyển qua từng node trong list
        for (Node* cur = head; cur; cur = cur->next) {
            cout << cur->data << " -> ";
        }
        cout << "NULL" << endl;
    }

    // Destructor: giải phóng bộ nhớ
    ~LinkedList() {
        while (head) {
            Node* t = head;     // t giữ con trỏ tới node hiện tại
            head = head->next;  // di chuyển head sang node kế tiếp
            delete t;           // giải phóng node cũ
        }
    }
};

int main() {
    // 1) Account: encapsulation và ADT (không dùng pointer)
    Account acc(100.0);
    acc.deposit(50);
    cout << "Balance after deposit: " << acc.getBalance() << endl;
    acc.withdraw(30);
    cout << "Balance after withdraw: " << acc.getBalance() << endl;

    // 2) Polymorphism: abstract class & virtual functions + pointers
    // Shape* là pointer trỏ tới đối tượng Shape hoặc lớp con của Shape
    Shape* shapes[2] = { new Rectangle(3,4), new Circle(2.5) };
    for (Shape* s : shapes) {
        // s->display(): dùng ký hiệu '->' để gọi hàm qua con trỏ
        // C++ sẽ dùng vtable để gọi đúng phương thức override trong lớp con
        s->display();
    }
    for (Shape* s : shapes) {
        // delete s: giải phóng bộ nhớ cấp phát động, gọi destructor ảo đúng lớp con
        delete s;
    }

    // 3) Point: overload & operator (không dùng pointer)
    Point p1(1,2), p2(3,4);
    Point p3 = p1 + p2;  // operator+
    p3.move(5,5);        // overload move(dx,dy)
    cout << "Point p3: " << p3 << endl;

    // 4) Coercion: ép kiểu tự động char->int, bool->int
    char c = 'A';  // 'A' mã ASCII 65
    bool f = true; // bool ép thành 1
    cout << "combine('A', true) = " << combine(c,f) << endl;

    // 5) Templates: generic function (không dùng pointer)
    cout << "Max int: " << getMax(5,10) << endl;
    cout << "Max double: " << getMax(3.14, 2.71) << endl;

    // 6) LinkedList: ADT và dynamic memory + pointers
    LinkedList list;
    list.addFront(10);
    list.addFront(20);
    list.addFront(30);
    list.display();

    return 0;
}
