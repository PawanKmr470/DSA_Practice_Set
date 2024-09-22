#include <iostream>
#include <cstring>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <sys/wait.h>

const char *shmName = "/my_shared_memory"; // Name of the shared memory object
const size_t shmSize = 128;                // Size of the shared memory segment

int main() {
    // Create shared memory object
    int shmFd = shm_open(shmName, O_CREAT | O_RDWR, 0666);
    if (shmFd == -1) {
        perror("shm_open");
        return 1;
    }

    // Configure the size of the shared memory object
    if (ftruncate(shmFd, shmSize) == -1) {
        perror("ftruncate");
        close(shmFd);
        shm_unlink(shmName); // Clean up before exiting
        return 1;
    }

    // Fork the process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        close(shmFd);
        shm_unlink(shmName); // Clean up before exiting
        return 1;
    }

    if (pid == 0) {
        // Child process
        // Map the shared memory object into address space
        void *shmPtr = mmap(nullptr, shmSize, PROT_READ | PROT_WRITE, MAP_SHARED, shmFd, 0);
        if (shmPtr == MAP_FAILED) {
            perror("mmap");
            close(shmFd);
            shm_unlink(shmName); // Clean up before exiting
            return 1;
        }

        // Write a message to shared memory
        const char *message = "Hello from the child process!";
        std::memcpy(shmPtr, message, strlen(message) + 1);

        // Unmap and close shared memory object
        munmap(shmPtr, shmSize);
        close(shmFd);
        return 0;
    } else {
        // Parent process
        // Wait for child process to complete
        wait(nullptr);

        // Map the shared memory object into address space
        void *shmPtr = mmap(nullptr, shmSize, PROT_READ, MAP_SHARED, shmFd, 0);
        if (shmPtr == MAP_FAILED) {
            perror("mmap");
            close(shmFd);
            shm_unlink(shmName); // Clean up before exiting
            return 1;
        }

        // Read and print the message from shared memory
        std::cout << "Message read from shared memory: " << static_cast<char*>(shmPtr) << std::endl;

        // Unmap and close shared memory object
        munmap(shmPtr, shmSize);
        close(shmFd);

        // Unlink the shared memory object
        shm_unlink(shmName);
    }

    return 0;
}
