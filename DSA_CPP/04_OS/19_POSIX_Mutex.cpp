#include <pthread.h>
#include <iostream>

using namespace std;

// Shared variable
int shared_var = 0;

// Mutex
pthread_mutex_t mutex;

// Thread function
void *thread_func(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Update the shared variable
        shared_var++;

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    return nullptr;
}

int main() {
    // Initialize the mutex
    pthread_mutex_init(&mutex, nullptr);

    // Create threads
    pthread_t thread1, thread2;
    pthread_create(&thread1, nullptr, thread_func, nullptr);
    pthread_create(&thread2, nullptr, thread_func, nullptr);

    // Wait for threads to finish
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);

    // Print the final value of the shared variable
    cout << "Final value of shared_var: " << shared_var << endl;

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
