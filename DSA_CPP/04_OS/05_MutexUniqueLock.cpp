#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;

void genfun(char x) {
    // unique_lock<mutex> uLock1(m);            // just like lock_guard

    unique_lock<mutex> uLock1(m, defer_lock);   // one feature of unique_lock
    // do something here...
    uLock1.lock();

    for (int i = 0; i < 500; i++) {
        cout << x;
    }
    cout << endl;

    uLock1.unlock();    // unlocks it. Though it's not necessary it will do it
}                       // automatically

int main() {

    thread t3(genfun, '+');
    thread t4(genfun, '-');

    t3.join();
    t4.join();

    // another feature of unique_lock i.e. Transfer ownership
    unique_lock<mutex> unq_lock1(m);
    unique_lock<mutex> unq_lock2 = move(unq_lock1);

    // But this features are heavy weighted. don't use unique_lock
    // unless these features are required, use lock_guard instead.
}