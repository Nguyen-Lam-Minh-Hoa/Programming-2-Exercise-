#include <iostream>
using namespace std;

class mother{
    public:
    void display () {
    cout<<"A message for mother.\n";
    }
};
class daughter: public mother { // inherited daughter class
public: 
    void display() {
        cout<<"A message for daughter.\n";
    }
};

// main function
int main() {
    daughter m;
    m.display();
    return 0;
}