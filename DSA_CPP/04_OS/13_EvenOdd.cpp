#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore>
using namespace std;

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
