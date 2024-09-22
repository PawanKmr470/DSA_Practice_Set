#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> counter(0);

void increment_counter() {
    counter.fetch_add(1, std::memory_order_relaxed);
    counter.
}

int main() {
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);
    std::thread t3(increment_counter);
    std::thread t4(increment_counter);
    std::thread t5(increment_counter);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();


    // counter should be equal to 5
    int expected = 5;
    int got = counter.load(std::memory_order_relaxed);
    if (got != expected) {
        std::cout << "Value not correct! We were expecting: " << expected << " but got: " << got << '\n';
    }

    std::cout << "Value we were expecting is correct: " << got << '\n';
}

