#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;
int g_data = 0;

void thread1() {
    for (int i=0; i < 10000; i++) {
        lock_guard<mutex> mu_guard(m);
        g_data++;       // what if this section throws exception ???
                        // mutex will be locked forever by a thread
                        // that's why it's not recommended to use mutex's
                        // lock & unlock functions directly
                        // use lock_guard instead.
                        // RAII feature hence unlocking is safe
    }                   // after } mu_guard will release the lock (as per scope)
}                       // it's a wrapper over mutex object
                        // RAII (Resource Acquisition Is Initialization) meaning
                        // object goes out of scope, its destructor is automatically invoked.

void thread2() {
    for (int i=0; i < 10000; i++) {
        lock_guard<mutex> mu_guard(m);
        g_data++;
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


    // // Deadlock
    // mutex m1;
    // mutex m2;

    // // In thread 1
    // lock_guard<mutex> grd1(m1);
    // lock_guard<mutex> grd2(m2); // this thread won't be able to take lock m2
    //                             // as it could be acquired by thread 2 => deadlock

    // // In thread 2
    // lock_guard<mutex> grd2(m2);
    // lock_guard<mutex> grd1(m1);

    // // Solution is : keep the locking order same
    // // In thread 2
    // lock_guard<mutex> grd1(m1);
    // lock_guard<mutex> grd2(m2);

}