#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <chrono>
using namespace std;

// Producer Consumer
//      Bounded buffer
//      Using Mutex, Shared Variable & Condition variable

int g_data = 0;
mutex g_mutex;
bool g_ready = false;       // Now it will be used by the condition variable.
condition_variable cv;

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
        unique_lock<std::mutex> ul(g_mutex);

        g_data = produceData();
        g_ready = true;

        ul.unlock();
        cv.notify_one();    // not needed to be in critical section
        ul.lock();
        cv.wait(ul, [](){ return g_ready == false; });  // wailt until g_ready becomes false
    }
}

void consumer() {
    while (true) {
        unique_lock<mutex> ul(g_mutex);
        cv.wait(ul, [](){ return g_ready; });   // wait until g_ready becomes true
        consumeData(g_data);                    // as g_ready becomes true wait is over
        g_ready = false;
        ul.unlock();
        cv.notify_one();
        ul.lock();
    }
}


int main() {
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
}