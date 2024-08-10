#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> &s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    // Member functions - push, pop, top, size, empty, swap
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    cout << "stack size before : " << s1.size() << endl;
    print(s1);
    cout << "stack size after  : " << s1.size() << endl;
}