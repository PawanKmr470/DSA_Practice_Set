#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;

//int g_data = 0;
atomic<int> g_data(0);

void thread1() {
    for (int i=0; i < 10000; i++) {
        g_data++;
    }
}

void thread2() {
    for (int i=0; i < 10000; i++) {
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
}
