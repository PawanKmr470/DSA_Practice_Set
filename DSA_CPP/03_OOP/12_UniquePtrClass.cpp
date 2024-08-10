#include <iostream>
#include <memory>       // Header file for smart pointers
using namespace std;

// We can make this thread-safe by using mutex.

template <typename T>
class UniquePtr {
    private:
        T* res;
    public:
        // default and parameterised ctor
        UniquePtr(T* ptr = nullptr) : res(ptr) {};

        // delete copy ctor
        UniquePtr(const UniquePtr<T>& ptr) = delete;

        // delete copy assignment operator
        UniquePtr<T>& operator=(const UniquePtr<T>& ptr) = delete;

        // move ctor
        UniquePtr(UniquePtr<T>&& ptr) {
            res = ptr.res;
            ptr.res = nullptr;
        }

        // move assignment operator
        UniquePtr<T>& operator=(UniquePtr<T>&& ptr) {
            if (this != &ptr) {
                if (res) {
                    delete res;
                }
                res = ptr.res;
                ptr.res = nullptr;
            }
            return *this;
        }

        // -> operator overloading
        T* operator->() {
            return res;
        }

        // * operator overloading
        T& operator*() {
            return *res;
        }

        // get() method overloading
        T* get() {
            return res;
        }

        // reset() method overloading
        void reset(T* ptr = nullptr) {
            if (res) {
                delete res;
            }
            res = ptr;
        }

        // dtor
        ~UniquePtr() {
            if (res) {
                delete res;
                res = nullptr;
            }
        }

};

int main() {
    UniquePtr<int> ptr1(new int(2));
    // UniquePtr<int> ptr2(ptr1);          // should give compilation error
    // UniquePtr<int> ptr3 = ptr1;         // should give compilation error
    UniquePtr<int> ptr4(new int(500));
    // ptr4 = ptr3;                        // should give compilation error
    UniquePtr<int> ptr5 = std::move(ptr1);

    // instead of <int> if there is some user-defined datatype then this will invoke the funtion
    // ptr1->fun()

    cout << *ptr5 << endl;
    cout << ptr5.get() << endl;
    ptr5.reset(new int(30));
    cout << *ptr5 << endl;

    return 0;
}

