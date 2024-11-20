#include <iostream>
using namespace std;

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
        return front == nullptr;
    }

    void enQueue(int val) {
        Node<T> *temp = new Node<T> (val);

        if (rear)
            rear->next = temp;      // Add element at the rear
        rear = temp;                // Update the rear
        if (!front)
            front = rear;           // If the queue was empty, front should also point to the new node

        cout << "enQueued : " << val << endl;
    }

    void deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        T val = front->data;
        
        Node<T> *temp = front;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
        
        cout << "deQueued : " << val << endl;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node<T> *cur = front;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.display();
    q.deQueue();
    q.deQueue();
    q.display();
    q.enQueue(60);
    q.enQueue(70);
    q.enQueue(80);
    q.display();
}