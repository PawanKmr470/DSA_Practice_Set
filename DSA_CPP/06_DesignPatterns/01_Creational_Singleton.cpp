#include <iostream>
#include <mutex>
using namespace std;

mutex mtx;

class Singleton {
    private:
        static Singleton* pObj;
        Singleton() {};     // Making the ctor private
                            // We can also make copy ctor & = operator private here
                            // instead of deleting them, same thing.
    public:

        // Singletons should not be cloneable (delete copy ctor).
        Singleton(const Singleton &) = delete;

        // Singletons should not be assignable (delete assignment operator).
        const Singleton& operator=(const Singleton &) = delete;

        // This definition should be outside of the class as per c++ guidelines
        static Singleton* getInstance() {
            lock_guard<mutex> myLock(mtx);  // just thread safe

            if (pObj == nullptr) {
                cout << "New instance" << endl;
                pObj = new Singleton;
                return pObj;
            }
            else {
                cout << "Previous instance" << endl;
                return pObj;
            }
        }

        void otherFunc() {
            cout << "Other operations" << endl;
        }
};

Singleton* Singleton::pObj = nullptr;


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

    Singleton* instance = Singleton::getInstance();
    cout << "Addr of instance 1 : " << instance << endl;
    Singleton* instance2 = Singleton::getInstance();
    cout << "Addr of instance 2 : " << instance2 << endl;
    instance2->otherFunc();
    cout << "*******************" << endl;

    Singleton2 &s1 = Singleton2::getInstance();
    Singleton2 &s2 = Singleton2::getInstance();
    cout << "Addr of s1 : " << &s1 << endl;
    cout << "Addr of s2 : " << &s2 << endl;

    return 0;
}