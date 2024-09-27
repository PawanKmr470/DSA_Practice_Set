#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore>
using namespace std;

// Threads order is not maintained. They are executing in any order i.e. NOT alternatively.
// It's just that they are printing as per the condition given.
// We need better solution
// Better : 14_EvenOddAlternate.cpp
// Best : 15_EvenOddAlternate2.cpp

mutex m;
int count = 0;

void even_fun() {
    extern int count;
    while (count < 20) {
        lock_guard<mutex> mylock(m);
        if (count % 2 == 0) {
            cout << "From even thread : " << count << endl;
        }
        count++;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return;
}

void odd_fun() {
    extern int count;
    while (count < 20) {
        lock_guard<mutex> mylock(m);
        if (count % 2 == 1) {
            cout << "From odd thread  : " << count << endl;
        }
        count++;
        this_thread::sleep_for(chrono::milliseconds(100));
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


// Outputs 1:

// Threads started...
// From even thread : 0
// From even thread : 2
// From even thread : 4
// From even thread : 6
// From even thread : 8
// From even thread : 10
// From even thread : 12
// From even thread : 14
// From even thread : 16
// From even thread : 18

// Outputs 2:

// Threads started...
// From even thread : 0
// From odd thread  : 1
// From odd thread  : 3
// From odd thread  : 5
// From odd thread  : 7
// From odd thread  : 9
// From odd thread  : 11
// From odd thread  : 13
// From odd thread  : 15
// From odd thread  : 17
// From odd thread  : 19
// From even thread : 20