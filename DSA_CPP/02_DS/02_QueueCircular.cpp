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
            front = -1;                               // If default is 0 then after first push, front will point to 0 and rear to 1
            rear = -1;                                // which is wrong. They both should point to 0. Hence -1 initialization is correct.
        }
        ~Queue() {};
        
        bool isEmpty() {
            return (front == -1 && rear == -1);       // && rear == -1 is not must
        }

        bool isFull() {
            return ((rear + 1) % MAX_SIZE == front);
        }

        void enQueue(int value) {
            if (isFull()) {
                cout << "Queue is full" << endl;
                return;
            }

            if (isEmpty()) {                        // Initial case
                front = 0;
                rear = 0;
            }
            else {
                rear = (rear + 1) % MAX_SIZE;       // e.g. r == 4 then (4 + 1) % 5 -> 0
            }

            data[rear] = value;
            cout << "enQueue : " << value << endl;
            return;
        }

        void deQueue() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }

            cout << "deQueue : " << data[front] << endl;
            if (front == rear) {                    // 1. deQueueing last element
                front = -1;
                rear = -1;
            }
            else {                                  // 2. deQueueing non last element
                front = (front + 1) % MAX_SIZE;
            }
            return;
        }

        void displayQueue() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                int i;
                for (i = front; i != rear; i = (i+1) % MAX_SIZE) {  // i != rear, Note it. This For loop is different
                    cout << data[i] << " ";
                }
                cout << data[i] << endl;                            // extra line
                cout << endl;
            }
            return;
        }
};


int main() {
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.displayQueue();
    q.deQueue();
    q.deQueue();
    q.enQueue(60);
    q.enQueue(70);
    q.displayQueue();
    q.displayQueue();
}