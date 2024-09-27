#include <iostream>
#include <deque>
#include <thread>
#include <semaphore>
using namespace std;

binary_semaphore bsem_even(1), bsem_odd(0);
int count = 0;

// This is also a correct way of synchronize even odd threads
// which makes sure other is surely run once first one completes

void even_fun() {
    extern int count;
    while (count < 20) {
        bsem_even.acquire();

        if (count % 2 == 0) {
            cout << "From even thread : " << count << endl;
        }
        count++;

        bsem_odd.release();
    }
    return;
}

void odd_fun() {
    extern int count;
    while (count < 20) {
        bsem_odd.acquire();
        
        if (count % 2 == 1) {
            cout << "From odd thread  : " << count << endl;
        }
        count++;
        
        bsem_even.release();
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
