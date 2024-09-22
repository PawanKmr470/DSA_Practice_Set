#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>   // For sleep
using namespace std;

sem_t sem;

void* thread_function(void* arg) {
    cout << "Thread waiting for the semaphore...\n";
    sem_wait(&sem);  // Lock the semaphore

    cout << "Thread inside critical section...\n";
    sleep(2);  // Simulate some work

    cout << "Thread releasing the semaphore...\n";
    sem_post(&sem);  // Release the semaphore
    return nullptr;
}

int main() {
    pthread_t thread;

    // Initialize unnamed semaphore with an initial value of 1
    sem_init(&sem, 0, 1);  // 0 means semaphore is shared between threads, not processes

    // Create a thread
    pthread_create(&thread, nullptr, thread_function, nullptr);

    // Main thread also waits for the semaphore
    cout << "Main waiting for the semaphore...\n";
    sem_wait(&sem);  // Lock the semaphore

    cout << "Main inside critical section...\n";
    sleep(2);  // Simulate some work

    cout << "Main releasing the semaphore...\n";
    sem_post(&sem);  // Release the semaphore

    // Wait for the thread to finish
    pthread_join(thread, nullptr);

    // Destroy the semaphore
    sem_destroy(&sem);

    return 0;
}
