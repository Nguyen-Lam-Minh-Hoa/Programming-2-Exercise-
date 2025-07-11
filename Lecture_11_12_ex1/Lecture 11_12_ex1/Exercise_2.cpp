#include <iostream>
#include <string>

using namespace std;

//Tempalate node class
template <typename T>
class the_node {
public:
    T data; //value in node
    the_node* next_pointer; // pointer to point to next node

    the_node(T value) : data(value), next_pointer(nullptr) {}   // constructor 
};

//template link_list class
template <typename T>
class linked_list {
private:
    the_node<T>* head; //head is pointer to the first node

public: 
    linked_list() : head(nullptr) {} //constructor as empty

    //add node to the end
    void append(T value) {
        the_node<T>* new_node = new the_node<T>(value); //create new node
        if (!head) {
            head = new_node; // if empty, new node is head
        }
        else {
            the_node<T>* temp = head;
            //travel to the last node
            while (temp->next_pointer) {
                temp = temp ->next_pointer;
            }
            temp->next_pointer = new_node; // link last node to new node
        }
    }
    
    // print the nodes
    void display() const {
        the_node<T>* temp = head;
        while (temp) {
            cout << temp->data << "--pointer-->";
            temp = temp->next_pointer;
        }
        cout << "Null" << endl; // end is null for simple linked list
    }

    //Destructor free memory
    ~linked_list() {
        the_node<T>* temp;
        while (head) {
            temp = head; // store current node
            head = head-> next_pointer; // move 
            delete temp; // delete the stored
        }
    }
};

//main function
int main () {
    cout << "Try linked_list with 'int' type:" << endl;
    linked_list<int> int_linked_list;
    // add 20 25 90 as example
    int_linked_list.append(20);
    int_linked_list.append(25);
    int_linked_list.append(90);
    int_linked_list.display(); //print

    cout << "Try linked_list with 'string' type: " << endl;
    linked_list<string> str_linked_list;
    // string example
    str_linked_list.append("Minh");
    str_linked_list.append("Hoa");
    //print
    str_linked_list.display();

    return 0;
}