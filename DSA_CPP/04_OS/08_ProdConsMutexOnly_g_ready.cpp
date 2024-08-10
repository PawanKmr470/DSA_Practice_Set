#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <chrono>
using namespace std;

// Producer Consumer
//      Bounded buffer
//      Using Mutex & Shared Variable

int g_data = 0;
mutex g_mutex;
bool g_ready = false;


int produceData() {
  int data = rand() % 1000;
  cout << "produce data: " << data << "\n";
  return data;
}

void consumeData(int data) {
    cout << "receive data: " << data << "\n";
}


void producer() {
    while (true) {
        unique_lock<mutex> ul(g_mutex);

        g_data = produceData();
        g_ready = true;
        ul.unlock();
        while (g_ready) {           // sleep till g_ready is true
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}

void consumer() {
    while (true) {
        while (!g_ready) {          // sleep till g_ready is false
            this_thread::sleep_for(chrono::seconds(1));
        }
        unique_lock<mutex> ul(g_mutex);
        consumeData(g_data);
        g_ready = false;
    }
}


int main() {
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
}