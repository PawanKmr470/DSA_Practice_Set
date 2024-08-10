#include <iostream>
using namespace std;

class Base {
public:
    virtual void display()=0;
};

class Derived1 : public Base {
    int d1;
public:
    Derived1(){
        d1 = 100;
    }
    void display() {
        cout << d1 << endl;
    }
    
    void add(int val) {         // Added in only Derived1 class
        d1 += val;
    }
};

class Derived2 : public Base {
    int d2;
public:
    Derived2(){
        d2 = 200;
    }
    void display() {
        cout << d2 << endl;
    }
    
};

// Factory method
Base* instance(int option) {
    Base* ptr;
    if (option == 1) {
        ptr = new Derived1();
        return ptr;
    }
    if (option == 2) {
        ptr = new Derived2();
        return ptr;
    }
    return ptr;
}

int main() {
    int i = 1;
    Base* ptr = instance(i);
    ptr->display();
    
    Derived1* dptrx = dynamic_cast<Derived1*> (ptr);    // Gives non-null ptr
    if (dptrx == nullptr)
        cout << "null pointer" << endl;
    else
        cout << "non-null pointer" << endl;
    
    Derived2* dptry = dynamic_cast<Derived2*> (ptr);    // Gives null ptr
    if (dptry == nullptr)
        cout << "null pointer" << endl;
    else
        cout << "non-null pointer" << endl;
    return 0;
}
