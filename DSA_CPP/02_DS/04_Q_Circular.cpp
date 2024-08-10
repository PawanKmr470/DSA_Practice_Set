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
            // if (front == 0 && rear == MAX_SIZE - 1)
            if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) { 
                    return true;
            }
            else {
                return false;
            }
        }

        bool isEmpty() {
            if (front == -1) {
                return true;
            }
            else {
                return false;
            }
        }

        void enQueue(int value) {
            if (isFull()) {
                cout << "Queue is full" << endl;
            }
            else {
                if (front == -1) { front = 0; }

                // rear++;
                rear = (rear + 1) % MAX_SIZE;   // e.g. r == 4 then r + 1 -> 0
                data[rear] = value;
            }
        }

        int deQueue() {
            int value;
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            else {                              // Need to cover two cases -
                value = data[front];            // 1. deQueueing last element
                if (front == rear) {            // 2. deQueueing non last element
                    front = -1;
                    rear = -1;
                }
                else {
                    // front++;
                    front = (front + 1) % MAX_SIZE;
                }
                return value;
            }
        }

        void displayQueue() {                   // See FOR Loop. It's different
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                int i;
                // for (int i = front; i <= rear; ++i) {
                for (i = front; i != rear; i = (i+1) % MAX_SIZE) {  // i != rear, Note it.
                    cout << data[i] << " ";
                }
                cout << data[i] << endl;    // extra line
                cout << endl;
            }
        }
};


int main() {
    Queue q;
    // q.enQueue(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.displayQueue();
    cout << "deQueue element : " << q.deQueue() << endl;
    q.displayQueue();
}