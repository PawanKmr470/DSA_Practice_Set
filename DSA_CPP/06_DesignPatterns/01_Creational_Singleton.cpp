#include <iostream>
#include <mutex>
using namespace std;

mutex mtx;

class Singleton {
    private:
        static Singleton* ptr;                             // Declaration inside the class
        Singleton() { cout << "ctor called" << endl; };     // Making the ctor private
                                                            // We can also make copy ctor & = operator private here
                                                            // instead of deleting them, same thing.
        ~Singleton() { cout << "dtor called" << endl; };
    public:

        // Singletons should not be cloneable (delete copy ctor).
        Singleton(const Singleton &) = delete;

        // Singletons should not be assignable (delete assignment operator).
        const Singleton& operator=(const Singleton &) = delete;

        // This definition should be outside of the class as per c++ guidelines
        // Why static becuase of two reasons -
        // 1. We need to modify static data member which only static method can do.
        // 2. We want to call this method without creating the object. Static methods can be called with Classname only.
        static Singleton* getInstance() {
            lock_guard<mutex> myLock(mtx);  // just thread safe

            if (ptr == nullptr) {
                cout << "New instance" << endl;
                ptr = new Singleton();
            }
            else {
                cout << "Previous instance" << endl;
            }
            return ptr;

        }

        void otherFunc() {
            cout << "Other operations" << endl;
        }
};

// Definition outside the class
// Initialization happens once:
// The static data member is initialized once (as it's a class variable) at the beginning of the program,
// or the first time it is used in the code.
// To avoid multiple definitions, we define them outside the class, usually in a source file.
// Static data members are initialized before any object of the class is created.
// Initializing them outside the class ensures that they are initialized correctly and in the right order.
// If you define the static data member as const, constexpr, or with some other initialization in its declaration,
// the initialization might also occur at compile-time or when the class is instantiated.
Singleton* Singleton::ptr = nullptr;


// without dynamic allocation
class Singleton2 {
    private:
        Singleton2() { cout << "Ctor" << endl; }
        ~Singleton2() { cout << "Dtor" << endl; }
        Singleton2(const Singleton2&);
        const Singleton2& operator=(const Singleton2&);

    public:
        static Singleton2& getInstance() {
            static Singleton2 instance;
            return instance;
        }
};

int main() {

    Singleton* ptr1 = Singleton::getInstance();
    cout << "Addr of ptr1 : " << ptr1 << endl;

    Singleton* ptr2 = Singleton::getInstance();
    cout << "Addr of ptr2 : " << ptr2 << endl;
    ptr2->otherFunc();

    cout << "*******************" << endl;

    Singleton2 &s1 = Singleton2::getInstance();
    Singleton2 &s2 = Singleton2::getInstance();
    cout << "Addr of s1 : " << &s1 << endl;
    cout << "Addr of s2 : " << &s2 << endl;

    return 0;
}