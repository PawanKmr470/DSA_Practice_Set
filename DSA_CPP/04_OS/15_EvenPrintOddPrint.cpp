#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore>
using namespace std;

// even thread -> print thread -> odd thred -> print thread -> even thread and so on...
// We have number of resources = 1, so counting semaphore won't be a suitable choice
// either binary semaphore or using mutex + condition variable can solve this problem
// using binary semaphore already solve in : 15_EvenOddAlternate2.cpp
// This solution is using mutex + CV

mutex m;
condition_variable cv;
int count = 0;
bool data_ready = 1;    // For print thread

void even_fun() {
    extern int count;
    while (count < 20) {
        unique_lock<mutex> mylock(m);
        cv.wait(mylock, [](){ return (count % 2 == 0 && data_ready == 0); });
        
        count++;
        data_ready = 1;
        
        mylock.unlock();
        cv.notify_all();
    }
    return;
}

void odd_fun() {
    extern int count;
    while (count < 20) {
        unique_lock<mutex> mylock(m);
        cv.wait(mylock, [](){ return (count % 2 == 1 && data_ready == 0); });
        
        count++;
        data_ready = 1;
        
        mylock.unlock();
        cv.notify_all();
    }
    return;
}

void print_fun() {
    extern int count;
    while (count < 20) {
        unique_lock<mutex> mylock(m);
        cv.wait(mylock, [](){ return (data_ready == 1); });
        
        cout << count << endl;
        data_ready = 0;
        
        mylock.unlock();
        cv.notify_all();
    }
}

int main() {
    cout << "Threads started..." << endl;

    thread even_thread(even_fun);
    thread odd_thread(odd_fun);
    thread print_thread(print_fun);

    even_thread.join();
    odd_thread.join();
    print_thread.join();

    return 0;
}
