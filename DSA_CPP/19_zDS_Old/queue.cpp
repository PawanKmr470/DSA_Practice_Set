#include <iostream>
#include <queue>
using namespace std;

void print(queue<int> &q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    // unlike stack here instead of top, front back is there (only difference in methods)
    // Member functions - push, pop, front, back, size, empty, swap
    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    int x=q1.front();
    q1.pop();
    cout << "front element : " << x << endl;
    cout << "queue size before : " << q1.size() << endl;
    cout << "front : " << q1.front() << endl;
    print(q1);
    cout << "queue size after  : " << q1.size() << endl;
}