#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cerrno>
#include <sys/wait.h>

// 1. Create a Unix domain socket (UNIX Socket).
// 2. Fork a child process.
// 3. The child process will connect to the socket and send a message.
// 4. The parent process will accept the connection and receive the message.

const char *socketPath = "/tmp/my_socket"; // Path to the Unix domain socket

int main() {
    int serverSock, clientSock;
    struct sockaddr_un serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    char buffer[128];

    // Create a Unix domain socket
    serverSock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (serverSock == -1) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sun_family = AF_UNIX;
    strncpy(serverAddr.sun_path, socketPath, sizeof(serverAddr.sun_path) - 1);

    // Bind the socket to the address
    if (bind(serverSock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("bind");
        close(serverSock);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSock, 1) == -1) {
        perror("listen");
        close(serverSock);
        return 1;
    }

    // Fork the process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        close(serverSock);
        return 1;
    }

    if (pid == 0) {
        // Child process
        // Create a client socket
        clientSock = socket(AF_UNIX, SOCK_STREAM, 0);
        if (clientSock == -1) {
            perror("socket");
            return 1;
        }

        // Set up the client address
        memset(&clientAddr, 0, sizeof(clientAddr));
        clientAddr.sun_family = AF_UNIX;
        strncpy(clientAddr.sun_path, socketPath, sizeof(clientAddr.sun_path) - 1);

        // Connect to the server socket
        if (connect(clientSock, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) == -1) {
            perror("connect");
            close(clientSock);
            return 1;
        }

        // Send a message to the server
        const char *message = "Hello from the child process!";
        if (send(clientSock, message, strlen(message), 0) == -1) {
            perror("send");
            close(clientSock);
            return 1;
        }

        close(clientSock);
        return 0;
    } else {
        // Parent process
        // Accept a connection from the client
        int acceptedSock = accept(serverSock, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (acceptedSock == -1) {
            perror("accept");
            close(serverSock);
            return 1;
        }

        // Receive a message from the client
        ssize_t bytesRead = recv(acceptedSock, buffer, sizeof(buffer) - 1, 0);
        if (bytesRead == -1) {
            perror("recv");
            close(acceptedSock);
            close(serverSock);
            return 1;
        }

        buffer[bytesRead] = '\0'; // Null-terminate the received message
        std::cout << "Message received: " << buffer << std::endl;

        close(acceptedSock);
        close(serverSock);
        unlink(socketPath); // Remove the socket file
        wait(nullptr); // Wait for the child process to finish
    }

    return 0;
}
