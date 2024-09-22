#include <iostream>
#include <fcntl.h>    // For O_CREAT, O_EXCL
#include <semaphore.h>
#include <unistd.h>   // For sleep
#include <sys/stat.h> // For mode constants

using namespace std;

int main() {
    // Create a named semaphore
    sem_t *sem = sem_open("/my_named_semaphore", O_CREAT, 0644, 1);  // Initial value = 1

    if (sem == SEM_FAILED) {
        cerr << "Failed to open named semaphore\n";
        return 1;
    }

    cout << "Waiting for the semaphore...\n";
    sem_wait(sem);  // Lock the semaphore

    cout << "Critical section. Holding the semaphore...\n";
    sleep(2);  // Simulate some work

    cout << "Releasing the semaphore...\n";
    sem_post(sem);  // Release the semaphore

    // Close and unlink the semaphore
    sem_close(sem);
    sem_unlink("/my_named_semaphore");  // Exists untill explicitly unlinked.

    return 0;
}
