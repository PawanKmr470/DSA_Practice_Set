#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

int data = 0;

void *producer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        data++;
        printf("Producer produced data: %d\n", data);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (data == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Consumer consumed data: %d\n", data);
        data = 0;
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}