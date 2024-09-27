#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <shared_mutex>
using namespace std;

// shared_mutex provided in C++ solve the reader writer synchronization problem.

shared_mutex shared_data_mutex;
int shared_data = 0;

void reader_thread() {
    while (true) {
        shared_lock<shared_mutex> reader_lock(shared_data_mutex);
        cout << "Reader thread: Shared data is " << shared_data << endl;
        // Do something with the shared data
        reader_lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void writer_thread() {
    while (true) {
        unique_lock<shared_mutex> writer_lock(shared_data_mutex);
        shared_data++;
        cout << "Writer thread: Updated shared data to " << shared_data << endl;
        writer_lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    thread reader1(reader_thread);
    thread reader2(reader_thread);
    thread writer(writer_thread);

    reader1.join();
    reader2.join();
    writer.join();

    return 0;
}
