#include <iostream>
#include <semaphore>
#include <thread>
using namespace std;

// Producer-Consumer & Buffer is bounded
// Two binary semaphore are required becuase we want consumer thread to run after producer thread
// is done. If there would be single binary semaphore then producer thread can run again and
// override the previous buffer data.
// Two Binary Semaphores because the way it's implemented 2 binary semaphores works.
// If producer is running then consumer is waiting and vice versa.
// See same problem using 2 counting semaphore + 1 binary/Mutex

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