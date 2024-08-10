#include <iostream>
#include <deque>
using namespace std;

void print(const deque<int> &tmplist)
{
    for (auto &i : tmplist)
        cout << i << " ";
    cout << endl;

    /* list<auto>::iterator it;
    for (it = tmplist.begin(); it != tmplist.end(), it++)
        cout << *it << " ";
    cout << endl; */
}

int main()
{
    // Initialization
    // Capacity - size, max_size, resize, empty, shrink_to_fit
    // Element access - [], at, front, back
    // Iterators - begin, end, rbegin, rend, cbegin, cend, crbegin, crend
    // Modifiers - assign, push_front, pop_front, push_back, pop_back, insert, erase, swap, clear, emplace, emplace_front, empalce_back

    deque<int> d1;
    d1.push_front(10);
    d1.push_front(20);
    d1.push_front(30);
    d1.push_back(5);
    d1.push_back(2);
    print(d1);
    d1.pop_front();
    print(d1);
    d1.pop_back();
    print(d1);
}