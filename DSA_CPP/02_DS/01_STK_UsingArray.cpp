#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

#define MAX_SIZE 5
// Instead of MAX_SIZE, we can take configurable private data member
// i.e. int capacity and initiailize in ctor.

class Stack {
    private:
        int data[MAX_SIZE];
        int size;

    public:
        Stack() { size = -1; }
        ~Stack() {};

        bool isFull() {
            if (size == MAX_SIZE - 1) {
                return true;
            }
            else {
                return false;
            }
        }

        bool isEmpty() {
            if (size == -1) {
                return true;
            }
            else {
                return false;
            }
        }

        void push(int value) {
            if (isFull()) {
                cout << "Stack is full" << endl;
            }
            else {
                data[++size] = value;   // consider both case when not full
            }                           // when value is first element and
        }                               // when value is 2nd, 3rd or 4th element

        int pop() {
            int value;
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
            for (int i = 0; i <= size; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.displayStack();
    cout << "popped value : " << s.pop() << endl;
    s.displayStack();
}