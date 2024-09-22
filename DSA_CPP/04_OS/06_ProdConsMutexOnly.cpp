#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <chrono>
#include <cstdlib>      // For rand() function
using namespace std;

// Producer Consumer
//      Unbounded buffer
//      Using Mutex only

deque<int> q;
mutex m;

void prod() {
    int count = 10;
    while (count > 0) {
        unique_lock<mutex> uLock(m);    // lock
        cout << "pushing data : " << count << endl;
        q.push_front(count);            // pushing data in queue
        uLock.unlock();                 // unlock
        this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
}

void cons() {
    int data = 0;
    while (data != 1) {
        unique_lock<mutex> uLock(m, defer_lock);
        if (!q.empty()) {
            uLock.lock();               // lock
            data = q.back();            // take data and
            q.pop_back();               // popping data from queue
            uLock.unlock();             // unlock
            cout << "consumer got value : " << data << endl;
        }
        else {
            cout << "consumer waiting for data..." << endl; // Mutex puts thead to sleep if it can't acquire lock. [[IMPORTANT]]
                                                            // and when mutex is released by the other thread
                                                            // OS wakes this thread up to try for acquiring lock.
        }                                                   // But this thread will surely take lock, not necessary.
        this_thread::sleep_for(chrono::seconds(2));         // Other thread can retake the lock once it has released it.
    }                                                       // Condition Variable sovlves this problem.
}

int main() {

    thread t1(prod);
    thread t2(cons);

    t1.join();
    t2.join();

    // IMPORTANT Points -
    // how to decide these sleep times ??

    // If producer is SLOW and consumer is FAST
    // Queue will underflow & underflow is ok not destructive issue because
    // consumer will keep waiting for data but why to waste CPU cycles.

    // If producer is FAST and consumer is SLOW
    // Queue will overflow after sometime which will cause memory exhaustion.

    // FAST means no waiting. SLOW means it can wait.
    // Producer will never wait in case of unbounded buffer.
    // It will keep pushing the data into queue -> buffer overflow -> memory exhaustion

    // NOTE : Here buffer is unbounded. Count has been given as 10 so that program 
    //          doesn't go into memory exhaustion state. So if this count is not there 
    //          (which may happen in actual problem), then memory exhaustion may occur.
    //          This implementation uses MUTEX only.

    // Solution is - some mechanism which could tell consumer thread that
    // data is available and you can process it otherwise it will make
    // consumer thread sleep
    // This is nothing but Condition Variable

    // Here unbounded buffer is used.
    // For bounded buffer, synchronization approach would be bit different.
    // If buffer is bounded then we will have to consider following pints -
    //      If buffer is filled then producer should not try to write the data. Goto sleep.
    //      If buffer is empty then consumer should not try to read the data. Goto sleep.

}

// Below program may lead to memory exhaustion.
int generate_data() {
    return rand() % 10;
}

void prod1() {
    while (true) {
        unique_lock<mutex> uLock(m);                    // lock
        int data = generate_data();
        cout << "prod1 : pushing data : " << data << endl;
        q.push_front(data);                  // pushing data in queue
        uLock.unlock();                                 // unlock
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void cons1() {
    int data;
    while (true) {
        unique_lock<mutex> uLock(m, defer_lock);
        if (!q.empty()) {
            uLock.lock();               // lock
            data = q.back();            // take data and
            q.pop_back();               // popping data from queue
            uLock.unlock();             // unlock
            cout << "cons1 : consumer got value : " << data << endl;
        }
        else {
            cout << "cons1 : consumer waiting for data..." << endl;
        }
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int main2() {
    srand(time(0));     // Sets the seed for the rand function.
                        // Generated random numbers are different each time the program is run.
    thread t1(prod);
    thread t2(cons);

    t1.join();
    t2.join();
}