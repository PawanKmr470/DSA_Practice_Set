#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

#define MAX 10 // Define the maximum size of the queue

class ThreadSafeQueue {
private:
    int arr[MAX];           // Array to hold queue elements
    int front;              // Index of the front element
    int rear;               // Index of the rear element
    int count;              // Current number of elements in the queue
    mutex mtx;             // Mutex for synchronization
    condition_variable cond; // Condition variable for blocking

public:
    ThreadSafeQueue() : front(0), rear(0), count(0) {}

    // Enqueue an element into the queue
    void enqueue(int value) {
        unique_lock<mutex> lock(mtx); // Lock the mutex
        
        // Wait until there is space in the queue
        cond.wait(lock, [this] { return count < MAX; });

        arr[rear] = value; // Add the new element
        rear = (rear + 1) % MAX; // Circular increment
        count++; // Increment count

        cout << "Enqueued: " << value << endl;

        lock.unlock(); // Unlock the mutex
        cond.notify_all(); // Notify one waiting thread
    }

    // Dequeue an element from the queue
    int dequeue() {
        unique_lock<mutex> lock(mtx); // Lock the mutex
        
        // Wait until there is at least one element in the queue
        cond.wait(lock, [this] { return count > 0; });

        int value = arr[front]; // Get the front element
        front = (front + 1) % MAX; // Circular increment
        count--; // Decrement count

        cout << "Dequeued: " << value << endl;

        lock.unlock(); // Unlock the mutex
        cond.notify_all(); // Notify one waiting thread
        return value;
    }

    // Display the elements in the queue
    void display() {
        unique_lock<mutex> lock(mtx); // Lock the mutex
        if (count == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;

        lock.unlock(); // Unlock the mutex
    }
};

// Producer function to add items to the queue
void producer(ThreadSafeQueue &q, int id) {
    for (int i = 0; i < 5; ++i) {
//        std::cout << "Prod " << id;
        q.enqueue(i + id * 10); // Produce some values
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
}

// Consumer function to remove items from the queue
void consumer(ThreadSafeQueue &q, int id) {
    for (int i = 0; i < 5; ++i) {
//        std::cout << "Cons " << id;
        q.dequeue(); // Consume values
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Simulate work
    }
}

int main() {
    ThreadSafeQueue q;

    // Create producer and consumer threads
    std::thread producer1(producer, std::ref(q), 1);
    std::thread producer2(producer, std::ref(q), 2);
    std::thread consumer1(consumer, std::ref(q), 1);
    std::thread consumer2(consumer, std::ref(q), 2);

    // Wait for threads to finish
    producer1.join();
    producer2.join();
    consumer1.join();
    consumer2.join();

    // Final display of the queue
    q.display();

    return 0;
}
