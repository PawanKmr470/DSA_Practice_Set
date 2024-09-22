#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstring>
#include <cerrno>

// Unnamed PIPE temporary and only exist only while the processes are running. They exist in memory.
// 1. Create an unnamed PIPE using pipe()
// 2. Fork a child
// 3. The child process will write to the PIPE
// 4. The parent process will read from the PIPE

int main() {
    int pipefd[2]; // pipefd[0] is read end, pipefd[1] is write end

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork the process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        close(pipefd[0]); // Close unused read end

        const char *message = "Hello from the child process!";
        if (write(pipefd[1], message, strlen(message)) == -1) {
            perror("write");
            close(pipefd[1]);
            return 1;
        }

        close(pipefd[1]); // Close the write end after writing
    } else {
        // Parent process
        close(pipefd[1]); // Close unused write end

        char buffer[128];
        ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if (bytesRead == -1) {
            perror("read");
            close(pipefd[0]);
            return 1;
        }

        buffer[bytesRead] = '\0'; // Null-terminate the string
        std::cout << "Message read from pipe: " << buffer << std::endl;

        close(pipefd[0]); // Close the read end after reading

        // Optionally, wait for the child process to complete
        wait(nullptr);
    }

    return 0;
}
