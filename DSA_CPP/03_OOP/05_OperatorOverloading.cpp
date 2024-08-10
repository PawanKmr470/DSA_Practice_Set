#include <iostream>
#include <vector>
using namespace std;

/*
Class Copyable {
public:
    Copyable(const Copyable &rhs);              // copy ctor
    Copyable &operator=(const Copyable &rhs);   // copy assignment operator
}

Class Moveable {
public:
  Moveable (Moveable&& other);               //move ctor
  Moveable &operator=(Moveable&& other);    //move assignment operator
};
*/

class Mystring {
    private:
        char *str;
        // int len; if taken, would help the related operations
    public:
        // default ctor
        Mystring() : str(nullptr) {
            cout << "default ctor" << endl;
            str = new char[1];
            *str = '\0';
        }

        // parameterized ctor
        Mystring(const char *s) : str(nullptr) {
            cout << "parameterized ctor" << endl;
            if (s == nullptr) {     // in case if someone creates obj with nullptr
                str = new char[1];  // like Mystring s(nullptr)
                *str = '\0';
            }
            else {
                str = new char[strlen(s) + 1];
                strcpy(str, s);
            }
        }

        // dtor
        ~Mystring() {
            delete[] str;
        }

        // copy ctor
        Mystring(const Mystring &src) : str(nullptr) {
            cout << "copy ctor" << endl;
            str = new char[strlen(src.str) + 1];
            strcpy(str, src.str);
        }

        // copy assignment operator overloading
        // NOTE - Pass by ref AND Return by ref
        // It depends what we need to return.
        // e.g. obj3 = obj1 + obj2 Here we need to return newly created object obj3
        // so Return by value.
        Mystring &operator=(const Mystring &rhs) {
            cout << "copy assignment operator" << endl;
            if (this == &rhs)
                return *this;

            delete[] str;
            str = new char[strlen(rhs.str) + 1];
            strcpy(str, rhs.str);
            return *this;
        }

        // move ctor. It move ctor takes an r value ref as a parameter.
        Mystring(Mystring &&src) : str(src.str) {
            cout << "move ctor" << endl;
            src.str = nullptr;
        }

        // move assignment operator overloading
        // if this is not implemented then copy assignment is called.
        Mystring &operator=(Mystring &&rhs) {
            cout << "move assignement operator" << endl;
            if (this == &rhs)
                return *this;

            delete[] str;
            str = rhs.str;
            rhs.str = nullptr;
            return *this;   // return current object
        }

        void display() const {
            cout << "string is : " << str << endl;
        }

        // ostream &operator << (ostream &out, const Mystring &s) {
        //     out << s.str << endl;
        //     return out;
        // }
};

int main() {
    Mystring c;                         // default ctor
    Mystring a("hello");                // parameterized ctor
    Mystring b = a;                     // copy ctor
    Mystring d(a);                      // copy ctor
    a.display();
    c = a;                              // copy assignment operator
    c.display();
    
    cout << "****************************" << endl;
    Mystring obj1("Pawan");             // parameterized ctor
    obj1 = Mystring("Kumar");           // parameterized ctor + move assignement operator
    obj1.display();
    obj1 = "Verma";                     // parameterized ctor (temp obj creation)
    obj1.display();

    cout << "****************************" << endl;
    vector<Mystring> vec;
    vec.push_back(Mystring("tempObj"));   // parameterized ctor + move ctor is called.

    Mystring x;
    x = Mystring("xyz");
    // cout << "<< overloaded : " << a << endl;
    return 0;
}