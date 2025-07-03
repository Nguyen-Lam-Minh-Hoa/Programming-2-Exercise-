#include <iostream>
#include <cstring>

using namespace std;

class Animal { // Base class
protected:
    int age;
    char name[30];  
public:
    //set data 
    void set_data(int a, const char* b) {
        age = a;
        strcpy(name, b);  
    }
};

// Inherited class
class Zebra : public Animal {
public:
    void zebra_m() {
        cout << "Zebra name is: " << name << endl;
        cout << "Zebra age is: " << age << endl;
        cout << "Zebra comes from Binh Duong, Viet Nam." << endl;
    }
};

class Dolphin : public Animal {
public:
    void dolphin_m() {
        cout << "Dolphin name is: " << name << endl;
        cout << "Dolphin age is: " << age << endl;
        cout << "Dolphin comes from Nha Trang, Viet Nam." << endl;
    }
};

int main() {
    Zebra ze;
    Dolphin dol;
    
    // Properly sized character arrays
    const char* n1 = "Zer Black";
    const char* n2 = "Dol Blue";

    //argument passing
    ze.set_data(10, n1);
    dol.set_data(5, n2);

    // Display animal 
    ze.zebra_m();
    dol.dolphin_m();

    return 0;
}
