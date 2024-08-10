#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;

void genfun(char x) {
    lock_guard<mutex> m_grd(m);         // comment line and then also see
    for (int i = 0; i < 500; i++) {
        cout << x;
    }
    cout << endl;
}

int main() {

    thread t3(genfun, '+');
    thread t4(genfun, '-');

    t3.join();
    t4.join();
}