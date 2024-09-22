// sender.cpp
#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <unistd.h>

const char *queueName = "/my_message_queue";

int sender() {
    // Open the message queue for sending
    mqd_t mq = mq_open(queueName, O_CREAT | O_WRONLY, 0644, nullptr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        return 1;
    }

    // Message to send
    const char *message = "Hello from the sender process!";
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        mq_close(mq);
        return 1;
    }

    std::cout << "Message sent: " << message << std::endl;

    // Close and unlink the message queue
    mq_close(mq);
    return 0;
}


int receiver() {
    // Open the message queue for receiving
    mqd_t mq = mq_open(queueName, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        return 1;
    }

    // Buffer to receive the message
    char buffer[128];
    ssize_t bytesRead = mq_receive(mq, buffer, sizeof(buffer), nullptr);
    if (bytesRead == -1) {
        perror("mq_receive");
        mq_close(mq);
        return 1;
    }

    buffer[bytesRead] = '\0'; // Null-terminate the received message
    std::cout << "Message received: " << buffer << std::endl;

    // Close and unlink the message queue
    mq_close(mq);
    mq_unlink(queueName);
    return 0;
}

int main() {
    sender();
    receiver();
    return 0;
}