#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>

// 1. Create a Named PIPE
// 2. Fork a child process
// 3. Child process will write a message to the FIFO
// 4. Parent process will read the message from the FIFO
// NOTE : As it's a Named PIPE the Process not necessary need to be parent child.
//        unlink() is required to destroy the PIPE likewise Named Semaphore

const char *fifoPath = "/tmp/myfifo";

void createFIFO() {
    // Create the named pipe (FIFO) if it does not exist
    if (mkfifo(fifoPath, 0666) == -1) {
        if (errno != EEXIST) {
            perror("mkfifo");
            exit(1);
        }
    }
}

void writeToFIFO() {
    // Open the FIFO for writing
    int fd = open(fifoPath, O_WRONLY);
    if (fd == -1) {
        perror("open for writing");
        exit(1);
    }

    // Write a message to the FIFO
    const char *message = "Hello from the child process!";
    if (write(fd, message, strlen(message)) == -1) {
        perror("write");
        close(fd);
        exit(1);
    }

    // Close the FIFO
    close(fd);
}

void readFromFIFO() {
    // Open the FIFO for reading
    int fd = open(fifoPath, O_RDONLY);
    if (fd == -1) {
        perror("open for reading");
        exit(1);
    }

    // Read from the FIFO
    char buffer[128];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("read");
        close(fd);
        exit(1);
    }

    // Null-terminate the string and display it
    buffer[bytesRead] = '\0';
    std::cout << "Message read from FIFO: " << buffer << std::endl;

    // Close the FIFO
    close(fd);
}

int main() {
    // Create the named pipe
    createFIFO();

    // Fork the process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        // Write to FIFO
        writeToFIFO();
    } else {
        // Parent process
        // Wait for child to finish
        wait(nullptr);

        // Read from FIFO
        readFromFIFO();

        // Optionally, remove the FIFO
        unlink(fifoPath);
    }

    return 0;
}
