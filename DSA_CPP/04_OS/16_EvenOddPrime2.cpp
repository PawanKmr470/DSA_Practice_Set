#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mutex;
std::condition_variable cv;
int nextNumber = 2;

void printEvenNumbers() {
    while (nextNumber <= 100) {
        std::unique_lock<std::mutex> lock(mutex);
        while (nextNumber % 2 != 0) {               // While loop is not taking advantage of CV. Causing busy wait.
            cv.wait(lock);
        }

        std::cout << nextNumber << " ";
        nextNumber++;
        cv.notify_all();
    }
}

void printOddNumbers() {
    while (nextNumber <= 100) {
        std::unique_lock<std::mutex> lock(mutex);
        while (nextNumber % 2 == 0) {
            cv.wait(lock);
        }

        std::cout << nextNumber << " ";
        nextNumber++;
        cv.notify_all();
    }
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void printPrimeNumbers() {
    while (nextNumber <= 100) {
        std::unique_lock<std::mutex> lock(mutex);
        while (!isPrime(nextNumber)) {
            cv.wait(lock);
        }

        std::cout << nextNumber << " ";
        nextNumber++;
        cv.notify_all();
    }
}

int main() {
    std::thread thread1(printEvenNumbers);
    std::thread thread2(printOddNumbers);
    std::thread thread3(printPrimeNumbers);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
