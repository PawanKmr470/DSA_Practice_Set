#include <iostream>
#include <thread>       // gives -> this_thread
#include <chrono>       // gives -> chrono::milliseconds(500);
#include <unistd.h>     // gives -> sleep();
using namespace std;


void fun1() {
    for (int i = 0; i < 100; i++) {
        cout << '+';
        this_thread::sleep_for(chrono::milliseconds(5));
    }
    cout << endl;
}

void fun2() {
    for (int i = 0; i < 100; i++) {
        cout << '-';
        this_thread::sleep_for(chrono::milliseconds(5));
    }
    cout << endl;
}

void genfun(char x) {
    for (int i = 0; i < 200; i++) {
        cout << x;
    }
    cout << endl;
}

int main() {

    thread t1(fun1);
    thread t2(fun2);

    t1.join();
    t2.join();

    // thread t3(genfun, '*');
    // thread t4(genfun, '$');

    // t3.join();
    // t4.join();
}