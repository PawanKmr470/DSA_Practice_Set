#include <iostream>
#include <memory>
using namespace std;

class B;

class A {
    shared_ptr<B> b_ptr;
public:
    A() { cout << "A ctor" << endl; }
    ~A() { cout << "A dtor" << endl; }

    void setB(shared_ptr<B> &b) {
        b_ptr = b;
    }
};

class B {
    shared_ptr<A> a_ptr;        // Make it weak_ptr to break cyclic dependancy
public:
    B() { cout << "B ctor" << endl; }
    ~B() { cout << "B dtor" << endl; }

    void setA(shared_ptr<A> &a) {
        a_ptr = a;
    }
};

int main() {
    shared_ptr<A> aPtr = make_shared<A>();
    shared_ptr<B> bPtr = make_shared<B>();

    aPtr->setB(bPtr);
    bPtr->setA(aPtr);
}