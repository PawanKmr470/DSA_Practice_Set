#include <iostream>
#include <deque>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

// Producer Consumer
//      Unbounded buffer
//      Using Mutex & Condition Variable

// cv.wait(lock, [] () { return condition; });
// condition returns false : thread is blocked.
// condition returns true : thread resumes bypassing cv.wait()
//      In short, thread is blocked until lambda function returns true.

deque<int> q;
mutex m;
condition_variable cv;

void prod() {
    int count = 10;
    while (count > 0) {
        unique_lock<mutex> uLock(m);    // lock
        cout << "pushing data : " << count << endl;
        q.push_front(count);            // pushing data in queue
        uLock.unlock();                 // unlock
        cv.notify_one();                // wake up consumer thread 
                                        // to wake up all other threads cv.notify_all();
        this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
    // cv.notify_one(); // without cv predicate this was required but why ??
}

void cons() {
    int data = 0;
    while (data != 1) {
        unique_lock<mutex> uLock(m);
        // cv.wait(uLock);
        cv.wait(uLock, [](){ return !q.empty(); });
                                    // it will put thread into sleep (SUSPENDED state precisely)
                                    // unless doesn't get notification (from cv.notify())
                                    // it will sleep but won't take lock. That's good
                                    // but it can wake up in between (spurious wake)
                                    // and we want to make it sleep again.
                                    // For it, it takes an arg -> predicate (it's a condition)
                                    // here it's lambda function (it could be other methods)
                                    // Now with predicate cv is perfect.
                                    // CV is like notification tone in WhatsApp

        data = q.back();            // take data and
        q.pop_back();               // popping data from queue
        uLock.unlock();             // unlock
        cout << "consumer got value : " << data << endl;
    }
}

int main() {

    thread t1(prod);
    thread t2(cons);

    t1.join();
    t2.join();

}