#include <iostream>
#include <thread>
#include <semaphore>
using namespace std;

// FIX IT
// All 3 thread will run sequentially and print the number if it is valid output.

int count = 0;
binary_semaphore bsem_even(1), bsem_odd(0), bsem_prime(0);

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= (n/2); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

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
        
        bsem_prime.release();
    }
    return;
}

void prime_fun() {
    extern int count;
    while (count < 20) {
        bsem_prime.acquire();
        
        if (isPrime(count)) {
            cout << "From prime thread  : " << count << endl;
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
    thread prime_thread(prime_fun);

    even_thread.join();
    odd_thread.join();
    prime_thread.join();

    return 0;
}