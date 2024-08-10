#include <iostream>
#include <unistd.h>     // for sleep call
#include <thread>
using namespace std;

void odd() {
    for(int i=0; i < 10; i++) {
        if (i % 2 != 0) {
            cout << "Thread odd : " << i << endl;
            sleep(0.1);
        }
    }
}

void even() {
    for(int i=0; i < 10; i++) {
        if (i % 2 == 0) {
            cout << "Thread even : " << i << endl;
            sleep(0.1);
        }
    }
}

int main() {

    thread t1(odd);
    thread t2(even);

    t1.join();
    t2.join();

    return 0;
}