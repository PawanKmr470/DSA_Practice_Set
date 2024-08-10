#include <iostream>
#include <semaphore>
#include <mutex>
#include <thread>
#include <deque>
using namespace std;

// Producer-Consumer & Buffer is bounded
// Two Counting semaphore + 1 Mutex are required

#define LOOP_SIZE 10
#define BUF_SIZE 5
deque<int> buf;

counting_semaphore<10> sem_full{0},     // Initially full -> 0
                        sem_empty{5};   // Initially empty -> 5
mutex m;

void producer() {
    for (int i = 0; i < LOOP_SIZE; ++i) {
        sem_empty.acquire();
        m.lock();
        
        int item = rand() % 100;
        buf.push_back(item);
        cout << "Produced : " << item << endl;
        
        m.unlock();
        sem_full.release();
        // this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer() {
    for (int i = LOOP_SIZE - 1; i >= 0; --i) {
        sem_full.acquire();
        m.lock();
        
        int item = buf.front();
        buf.pop_front();
        cout << "Consumed : " << item << endl;
        
        m.unlock();
        sem_empty.release();
        // this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    thread prod_thread(producer);
    thread cons_thread(consumer);

    cout << "Threads started..." << endl;

    prod_thread.join();
    cons_thread.join();

    return 0;
}

// Threads started...
// Produced : 7
// Produced : 49
// Produced : 73
// Produced : 58
// Produced : 30
// Consumed : 7
// Consumed : 49
// Consumed : 73
// Consumed : 58
// Consumed : 30
// Produced : 72
// Consumed : 72
// Produced : 44
// Produced : 78
// Produced : 23
// Produced : 9
// Consumed : 44
// Consumed : 78
// Consumed : 23
// Consumed : 9