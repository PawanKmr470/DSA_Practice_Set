#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue {
    private:
        int data[MAX_SIZE];
        int front;
        int rear;
        
    public:
        Queue() {
            front = -1;
            rear = -1;
        }
        ~Queue() {};

        bool isFull() {
            if (front == 0 && rear == MAX_SIZE - 1) {
                return true;
            }
            else {
                return false;
            }
        }

        bool isEmpty() {        // Other conditions
            if (front == -1) {  // if front == rear then 1 element is there
                return true;    // if front > rear OR front == rear + 1
            }                   // then Queue is empty
            else {              // front > rear will faile if Q is circular
                return false;   // but front == rear + 1 will still work
            }
        }

        void enQueue(int value) {
            if (isFull()) {
                cout << "Queue is full" << endl;
            }
            else {
                if (front == -1) { front = 0; }
                rear++;
                data[rear] = value;
            }
        }

        int deQueue() {
            int value;
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return -1;
            }
            else {
                value = data[front];
                if (front == rear) {    // == is sufficient. >= is not required.
                    front = -1;         // and don't put unnecessary > condition
                    rear = -1;          // it's useful in circular queue.
                }
                else {
                    front++;
                }
                cout << "deleted : " << value << endl;
                return value;
            }
        }

        void displayQueue() {
            if(isEmpty()) {
                cout << "Queue is empty." << endl;
            }
            else {
                cout << "Queue elements : ";
                for (int i = front; i <= rear; i++) {   // rear can ony to upto MAX_SIZE - 1
                    cout << data[i] << " ";             // hence i <= rear
                }
                cout << endl;
            }
        }
};

int main() {
    Queue myq;
    myq.enQueue(10);
    myq.enQueue(20);
    myq.enQueue(30);
    myq.enQueue(40);
    myq.enQueue(50);
    myq.displayQueue();
    myq.deQueue();
    myq.displayQueue();
    myq.deQueue();
    myq.deQueue();
    myq.deQueue();
    // myq.deQueue();
    myq.displayQueue();
}