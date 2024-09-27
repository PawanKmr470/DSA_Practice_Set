#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore>
using namespace std;

// This is correct way of synchronize even odd threads
// which makes sure other is surely run once first one completes

mutex m;
condition_variable cv;
int count = 0;

void even_fun() {
    extern int count;
    while (count < 20) {
        unique_lock<mutex> mylock(m);
        cv.wait(mylock, [](){ return count % 2 == 0; });
        
        cout << "From even thread : " << count << endl;
        count++;
        
        mylock.unlock();
        cv.notify_one();
    }
    return;
}

void odd_fun() {
    extern int count;
    while (count < 20) {
        unique_lock<mutex> mylock(m);
        cv.wait(mylock, [](){ return count % 2 == 1; });
        
        cout << "From odd thread  : " << count << endl;
        count++;
        
        mylock.unlock();
        cv.notify_one();
    }
    return;
}

int main() {
    cout << "Threads started..." << endl;

    thread even_thread(even_fun);
    thread odd_thread(odd_fun);

    even_thread.join();
    odd_thread.join();

    return 0;
}
