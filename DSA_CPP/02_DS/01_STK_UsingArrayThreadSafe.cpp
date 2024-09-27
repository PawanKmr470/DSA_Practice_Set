#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

#define MAX_SIZE 5
// Instead of MAX_SIZE, we can take configurable private data member
// i.e. int capacity and initiailize in ctor.

template <typename T>
class Stack {
    private:
        T data[MAX_SIZE];
        unsigned int size;
        recursive_mutex mtx;

    public:
        Stack() { size = -1; }
        ~Stack() {};

        bool isFull() {
            lock_guard<recursive_mutex> mylock(mtx);
            if (size == MAX_SIZE - 1) {
                return true;
            }
            else {
                return false;
            }
        }

        bool isEmpty() {
            lock_guard<recursive_mutex> mylock(mtx);
            if (size == -1) {
                return true;
            }
            else {
                return false;
            }
        }

        void push(T value) {
            lock_guard<recursive_mutex> mylock(mtx);
            if (isFull()) {
                cout << "Stack is full" << endl;
            }
            else {
                data[++size] = value;   // consider both case when not full
            }                           // when value is first element and
        }                               // when value is 2nd, 3rd or 4th element

        T pop() {
            T value;
            lock_guard<recursive_mutex> mylock(mtx);
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            else {
                value = data[size--];   // it will automatically set -1 for
                return value;           // last element
            }
        }

        void displayStack() {
            lock_guard<recursive_mutex> mylock(mtx);
            for (int i = 0; i <= size; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
};

int main() {

    Stack<int> s;

    thread t1([&](){
        for(int i = 0; i < MAX_SIZE; i++) {
            s.push(i);
        }
    });

    thread t2([&](){
        while (!s.isEmpty()) {
            int value = s.pop();
            cout << value << " ";
        }
        cout << endl;
    });
    
    t1.join();
    t2.join();
    
    return 0;

}
