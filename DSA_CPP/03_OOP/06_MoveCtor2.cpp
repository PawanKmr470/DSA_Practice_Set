#include <iostream>
#include <vector>
using namespace std;

/*
Class Moveable {
public:
  Moveable(Moveable&& other);               //move constructor
  Moveable& operator=(Moveable&& other);    //move assignment operator
};
*/

struct Mystring {
    int *ptr;

    // default ctor
    Mystring() {
        cout << "default ctor" << endl;
        ptr = new int;
    }

    Mystring(int val) {
        cout << "parameterized ctor" << endl;
        ptr = new int(val);
    }

    // copy ctor
    Mystring(const Mystring &obj) {
        cout << "copy ctor" << endl;
        this->ptr = new int;
        *this->ptr = *obj.ptr;
    }

    // move ctor
    Mystring(Mystring &&obj) {
        cout << "move ctor" << endl;
        this->ptr = obj.ptr;
        obj.ptr = nullptr;
    }

    // move assignment operator
    Mystring& operator=(Mystring &&obj) {
        cout << "move assignment" << endl;
        this->ptr = obj.ptr;
        obj.ptr = nullptr;
        return *this;
    }

    // dtor
    ~Mystring() {
        cout << "dtor" << endl;
        delete ptr;
    }
};

int main() {
    vector<Mystring> v1;
    v1.push_back(Mystring());

    // default ctor
    // copy ctor
    // dtor         -> this is of temp obj
    // dtor         -> this is of v1 object when main is ending
    //              This (copying object) is an performace overhead - copy ctor

    //              when move ctor is implemented
    // default ctor
    // move ctor
    // dtor
    // dtor

    // default ctor has "new int". copy ctor has "new int"
    // move ctor doesn't has it. so no copy only transfer.
    // So with move ctor, we avoided one extra copying.

    cout << "******************" << endl;
    Mystring s;
    vector<Mystring> v2;
    v2.push_back(s);
    // default ctor
    // copy ctor
    // dtor         -> this is of temp obj
    // dtor         -> this is of v2 object when main is ending
    // dtor         -> this is of v1 object when main is ending

    // v2.push_back(move(s));   // This will enforce move operation

    cout << "******************" << endl;
    Mystring str1;
    Mystring str2 = move(str1);
    Mystring str3;
    str3 = move(str2);
}

// int main() {
//     Mystring s2 = Mystring(100);    // compiler is doing copy elision   << IMPORTANT >>
// }