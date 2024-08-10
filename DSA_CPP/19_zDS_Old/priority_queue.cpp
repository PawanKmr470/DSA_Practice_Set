#include <iostream>
#include <queue>
using namespace std;

void print(priority_queue<int> &q)
//void print(priority_queue<int, vector<int>, greater<int>> &q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    // Member functions - push, pop, top, size, empty, swap
    priority_queue<int> q1;                                         // MAX HEAP
    //priority_queue<int, vector<int>, greater<int>> q1;            // MIN HEAP
    q1.push(50);
    q1.push(20);
    q1.push(40);
    q1.push(30);
    q1.push(10);
    print(q1);
}