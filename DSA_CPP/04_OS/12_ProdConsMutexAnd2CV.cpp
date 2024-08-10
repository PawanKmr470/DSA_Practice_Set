#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore>
using namespace std;

// Producer-Consumer & Buffer is bounded
// Two Counting semaphore + 1 Mutex are required

#define LOOP_SIZE 10
#define BUF_SIZE 5
deque<int> buf;

condition_variable cv_empty, cv_full;
mutex m;

void producer() {
    for (int i = 0; i < LOOP_SIZE; ++i) {
        unique_lock<mutex> mylock(m);
        cv_full.wait(mylock, [](){ return buf.size() < BUF_SIZE; });
        
        int item = rand() % 100;
        buf.push_back(item);
        cout << "Produced : " << item << endl;
        
        // mylock.unlock();
        cv_empty.notify_one();
        // this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer() {
    for (int i = LOOP_SIZE - 1; i >= 0; --i) {
        unique_lock<mutex> mylock(m);
        cv_empty.wait(mylock, [](){ return !buf.empty(); });
        
        int item = buf.front();
        buf.pop_front();
        cout << "Consumed : " << item << endl;
        
        // mylock.unlock();
        cv_full.notify_one();
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
// Consumed : 7
// Consumed : 49
// Produced : 73
// Produced : 58
// Produced : 30
// Produced : 72
// Produced : 44
// Consumed : 73
// Consumed : 58
// Consumed : 30
// Consumed : 72
// Consumed : 44
// Produced : 78
// Produced : 23
// Produced : 9
// Consumed : 78
// Consumed : 23
// Consumed : 9