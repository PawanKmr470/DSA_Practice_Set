#include <iostream>
using namespace std;

template <typename T>
class SharedPtr {
    private:
        T* res;
        int* counter;   // static int count can't be used as it will be per class basis (common for all object)
                         // we want per object basis so it should be a pointer which will point to a counter in heap.

        void IncCounter() {
            if (counter) {
                (*counter)++;
            }
        }

        void DecCounter() {
            if (counter) {
                (*counter)--;
                if (*counter == 0) {
                    if (res) {
                        delete res;
                        delete counter;
                        res = nullptr;
                        counter = nullptr;
                    }
                }
            }
        }

    public:

        // This is combined i.e. default ctor + param ctor
        // SharedPtr(T* ptr = nullptr) : res(ptr), counter(new int(0)) {
        //     cout << "ctor called" << endl;
        // }

        // Default ctor
        SharedPtr() : res(nullptr), counter(new int(0)) {
            cout << "Default ctor" << endl;
        }

        // Param ctor
        SharedPtr(T* ptr) : res(ptr), counter(new int(0)) {
            cout << "Param ctor" << endl;
        }

        // Copy ctor
        SharedPtr(const SharedPtr<T> &ptr) {
            cout << "Copy ctor" << endl;

            res = ptr.res;
            counter = ptr.counter;
            IncCounter();
        }

        // Copy assignment operator
        SharedPtr<T> &operator=(const SharedPtr<T> &ptr) {
            cout << "Copy assignment operator" << endl;

            if (this == &ptr) {
                DecCounter();               // Decrementing counter for LHS pointer
                res = ptr.res;
                counter = ptr.counter;
                IncCounter();               // Incrementing counter for RHS pointer
            }

            return *this;
        }

        // Move ctor
        SharedPtr(SharedPtr<T> &&ptr) {
            cout << "Move ctor" << endl;

            res = ptr.res;                  // Increment & Decrement counter by +1 and -1 will cancel out
            counter = ptr.counter;
            ptr.res = nullptr;
            ptr.counter = nullptr;
        }

        // Move assignment operator
        SharedPtr<T> &operator=(SharedPtr<T> &&ptr) {
            cout << "Move assignment operator" << endl;

            if (this == &ptr) {
                DecCounter();               // Decrementing counter for LHS pointer
                res = ptr.res;
                counter = ptr.counter;
                ptr.res = nullptr;
                ptr.counter = nullptr;
            }

            return *this;
        }

        void reset(T* ptr = nullptr) {
            DecCounter();
            if (ptr) {
                res = ptr;
                counter = new int(1);
            }
            else {
                res = nullptr;
                counter = nullptr;
            }
            
        }

        int get_count() {
            if (counter) {
                return (*counter);
            }
            return -1;          // Or throw the error
        }

        T* get() {
            return res;
        }

        T* operator->() {
            return res;
        }

        T& operator*() {
            return (*res);      // It may give exception and it should
        }

        ~SharedPtr() {
            DecCounter();
        }
};


int main() {
    SharedPtr<int> ptr1;
    SharedPtr<int> ptr2(new int(10));
    SharedPtr<int> ptr3(ptr2);
    ptr3 = ptr2;
    SharedPtr<int> ptr4(std::move(ptr1));    // SharedPtr<int> ptr4 = move(ptr1); ??
    ptr2 = std::move(ptr3);
    ptr1.reset();
    ptr1.reset(new int(5));
    cout << (*ptr1) << endl;
    // ptr1->func();
    cout << ptr1.get() << endl;
    cout << ptr1.get_count() << endl;


    return 0;
}
