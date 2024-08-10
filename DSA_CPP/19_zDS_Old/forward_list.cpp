#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

void print(const forward_list<int> &tmplist)
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
    // Capacity - max_size, empty
    // Element access - front
    // Iterators - before_begin, begin, end, cbefore_begin, cbegin, cend
    // Modifiers - assign, push_front, pop_front, insert_after, erase_after, swap, resize, clear, emplace_front, emplace_after
    // Operations - splice_after, remove, remove_if, unique, merge, sort, reverse

    // Initialization
    forward_list<int> f1{1,2,3,4,5};
    print(f1);

    forward_list<int> f2;
    f2.assign({1,2,3,4,5});
    print(f2);

    forward_list<int> f3(5, 10);
    print(f3);

    forward_list<int> f4;
    f4.push_front(10);
    f4.push_front(20);
    f4.push_front(30);
    f4.push_front(40);
    f4.push_front(50);
    f4.push_front(60);
    cout << "after all push : ";
    print(f4);
    cout << "after one pop : ";
    f4.pop_front();
    print(f4);

    // Modifiers
    // syntax1 : insert_after(pos_itr, value)
    // syntax2 : insert_after(pos_itr, repition, value)
    // syntax3 : insert_after(pos_itr, sublist_itr1, sublist_itr2)
    // syntax4 : insert_after(pos_itr, list) // list can be array or list

    list<int> l1 {11,22,33};
    list<int>::iterator it2 = l1.begin();
    list<int>::iterator it3 = l1.end();

    forward_list<int>::iterator it = f4.begin();
    cout << "syntax 1 : ";
    f4.insert_after(it, 45);
    print(f4);
    cout << "syntax 2 : ";
    f4.insert_after(++it, 2, 44);
    print(f4);
    cout << "syntax 3 : ";
    f4.insert_after(it, it2, it3);
    print(f4);
    cout << "syntax 4 : ";
    f4.insert_after(it, {9,8});
    print(f4);

    // erase_after(itr_at)
    // erase_after(start_itr, end_itr) // element at last itr is not included means ) not ] i.e. range is [)
    forward_list<int>::iterator itr = f4.begin();
    advance(itr,4);
    f4.erase_after(it, itr);
    cout << "after erase : ";
    print(f4);
}