#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

#define MAX_SIZE 5

// In enQueue operation it took lock and calling isFull method
// which will again take lock. It's a deadlock.
// One solution could be Recursive Lock (Recursive Mutex)

// Condition variable would be required when one thread is pushing
// into Queue and another is popping data from Queue. Prod Cons Problem
// Here CV's condition is Queue is empty and Queue is full.
// CV will be both ways prod will notify cons and cons will notify prod

// mutex m;
recursive_mutex m;

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
            lock_guard<recursive_mutex> locker(m);
            if (front == 0 && rear == MAX_SIZE - 1) {
                return true;
            }
            else {
                return false;
            }
        }

        bool isEmpty() {
            lock_guard<recursive_mutex> locker(m);
            if (front == -1 || front > rear) {  // front > rear is optional here
                return true;
            }
            else {
                return false;
            }
        }

        void enQueue(int value) {
            lock_guard<recursive_mutex> locker(m);
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
            lock_guard<recursive_mutex> locker(m);
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            else {
                value = data[front];
                if (front == rear) {    // need to check two cases
                    front = -1;         // 1. if deQueue element is the last one
                    rear = -1;
                }
                else {                  // 2. it's not the last one
                    front++;
                }
                return value;
            }
        }

        void displayQueue() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                for (int i = front; i <= rear; i++) {
                    cout << data[i] << " ";
                }
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