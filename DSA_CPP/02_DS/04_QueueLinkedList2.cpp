#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

mutex mtx;
condition_variable cv;

template <typename T>
struct Node {
    T data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T> *front;      // front
    Node<T> *rear;      // rear

public:
    Queue() : front(nullptr), rear(nullptr) {}
    ~Queue() {
        while (!isEmpty()) {
            deQueue();
        }
    }

    bool isEmpty() {
        lock_guard<mutex> lock(mtx);
        return front == nullptr;
    }

    void enQueue(int val) {
        Node<T> *temp = new Node<T> (val);

        unique_lock<mutex> lock(mtx);
        if (rear)
            rear->next = temp;      // Add element at the rear
        rear = temp;                // Update the rear
        if (!front)
            front = rear;           // If the queue was empty, front should also point to the new node

        cout << "enQueued : " << val << endl;

        lock.unlock();
        cv.notify_one();
    }

    void deQueue() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return front != nullptr; });

        // if (isEmpty()) {
        //     cout << "Queue is empty." << endl;
        //     return;
        // }

        T val = front->data;
        
        Node<T> *temp = front;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
        cout << "deQueued : " << val << endl;

        lock.unlock();
        cv.notify_one();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        unique_lock<mutex> lock(mtx);
        Node<T> *cur = front;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;

        lock.unlock();
        cv.notify_one();
    }
};

void producer(Queue<int> &q, int start, int count) {
    for (int i = 0; i < count; i++) {
        q.enQueue(i + start);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer(Queue<int> &q, int count) {
    for (int i = 0; i < count; i++) {
        q.deQueue();
        this_thread::sleep_for(chrono::microseconds(100));
    }
}

int main() {
    Queue<int> q;
    thread p1(producer, ref(q), 100, 10);
    thread p2(producer, ref(q), 1000, 10);
    thread c1(consumer, ref(q), 10);
    thread c2(consumer, ref(q), 10);

    p1.join();
    p2.join();
    c1.join();
    c2.join();

    q.display();

    return 0;
}