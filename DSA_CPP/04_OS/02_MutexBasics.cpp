#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;
int g_data = 0;

void thread1() {
    for (int i=0; i < 10000; i++) {
        m.lock();                       // It's a BLOCKING call though
        g_data++;                       // m.try_lock() is NON-BLOCKING & returns false
        m.unlock();                     // if unable to lock.
    }                                   // could be other methods also like -
}                                       // try_lock_for OR try_lock_until etc

void thread2() {
    for (int i=0; i < 10000; i++) {
        m.lock();
        g_data++;
        m.unlock();
    }
}

int main() {

    // thread1();
    // thread2();
    // cout << "g_data value : " << g_data << endl; // gives 20000

    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    cout << "g_data value : " << g_data << endl;    // gives any random ans <= 20000

}