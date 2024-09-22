#include <iostream>
#include <semaphore>
#include <thread>
using namespace std;

// Producer-Consumer (Bounded Buffer Problem)
// Two binary semaphore are required becuase we want consumer thread to run after producer thread
// is done. If there would be single binary semaphore then producer thread can run again and
// override the previous buffer data.
// If producer is running then consumer is waiting and vice versa.

// NOTE : Here two binary semaphores have been used. But the way they are solving the producer consumer problem
//        is slightly different i.e. producer keeps filling data in buffer : 0 to n-1 element in one go.
//        And similarly consumer is reading all the data 0 to n-1 in one go.
//  Where we use 2 Counting Semaphore + 1 Mutex to solve Producer Consumer Problem there 
//  counting semaphore's size is buffer size. That means as soon as data is available in the buffer
//  consumer can consume it and as soon as buffer gets empty producer can fill it
//  which was not the case with 2 binary semaphores solution.

#define BUF_SIZE 5
int buf[BUF_SIZE];

// binary_semaphore bsem_prod{1}, bsem_cons{0};     // {} Syntax is also fine
binary_semaphore bsem_prod(1), bsem_cons(0);

void producer() {
    while(1) {
        bsem_prod.acquire();

        cout << "Produced : ";
        for (int i=0; i<BUF_SIZE; ++i) {
            buf[i] = i*i;                   // producer task
            cout << buf[i] << " " << flush;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << endl;

        bsem_cons.release();
    }
}

void consumer() {
    while(1) {
        bsem_cons.acquire();

        cout << "Consumed : ";
        for (int i= BUF_SIZE - 1; i >= 0; --i) {
            cout << buf[i] << " " << flush;
            buf[i] = 0;                    // consumer task
            this_thread::sleep_for(chrono::microseconds(500));
        }
        cout << endl;
        cout << endl;

        bsem_prod.release();
    }
}

int main() {
    thread prod_thread(producer);
    thread cons_thread(consumer);

    cout << "Threads started..." << endl;

    prod_thread.join();
    cons_thread.join();

    return 0;
}