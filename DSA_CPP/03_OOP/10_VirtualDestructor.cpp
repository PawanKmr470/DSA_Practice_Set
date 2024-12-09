#include <iostream>
using namespace std;

class Base {
  public:
    Base() {
        cout << "Base ctor" << endl;
    }
    virtual ~Base() {
        cout << "Base dtor" << endl;
    }
};

class Derived : public Base {
  public:
    Derived() {
        cout << "Derived ctor" << endl;
    }
    ~Derived() {
        cout << "Derived dtor" << endl;
    }
};

int main() {
    Derived *d = new Derived();
    Base *b = d;
    delete b;
    return 0;
}

// Base ctor            without virtual ~Base()
// Derived ctor
// Base dtor

// Base ctor            with virtual ~Base()
// Derived ctor
// Derived dtor
// Base dtor

// Deleting a derived class object using a pointer of base class type that
// has a non-virtual destructor results in undefined behavior.