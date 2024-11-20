#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

#define MAX_SIZE 5
mutex mtx;
condition_variable cv;

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
        
        bool isEmpty() {
            return (front == -1 && rear == -1);
        }

        bool isFull() {
            return ((rear + 1) % MAX_SIZE == front);
        }

        void enQueue(int value) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] () { return (!isFull()); });

            // if (isFull()) {
            //     cout << "Queue is full" << endl;
            //     return;
            // }

            if (isEmpty()) {
                front = 0;
                rear = 0;
            }
            else {
                rear = (rear + 1) % MAX_SIZE;
            }

            data[rear] = value;
            cout << "enQueue : " << value << endl;

            lock.unlock();
            cv.notify_all();
            return;
        }

        void deQueue() {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] () { return (!isEmpty()); });

            // if (isEmpty()) {
            //     cout << "Queue is empty" << endl;
            //     return;
            // }

            cout << "deQueue : " << data[front] << endl;
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front = (front + 1) % MAX_SIZE;
            }

            lock.unlock();
            cv.notify_all();
            return;
        }

        void displayQueue() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                int i;
                for (i = front; i != rear; i = (i+1) % MAX_SIZE) {
                    cout << data[i] << " ";
                }
                cout << data[i] << endl;
                cout << endl;
            }
            return;
        }
};

void Producer(Queue &q, int id) {
    for (int i = 0; i < 5; i++) {
        q.enQueue(i + id*10);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void Consumer(Queue &q, int id) {
    for (int i = 0; i < 5; i++) {
        q.deQueue();
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}


int main() {
    Queue q;
    thread p1(Producer, ref(q), 1);
    thread p2(Producer, ref(q), 2);
    thread c1(Consumer, ref(q), 1);
    thread c2(Consumer, ref(q), 2);

    p1.join();
    p2.join();
    c1.join();
    c2.join();

    q.displayQueue();
    return 0;
}