#include <iostream>
#include <list>
#include <string>
using namespace std;

void print(const list<int> &tmplist)
{
    for (auto &i : tmplist)
        cout << i << " ";
    cout << endl;

    /* list<int>::iterator it;
    for (it = tmplist.begin(); it != tmplist.end(), it++)
        cout << *it << " ";
    cout << endl; */
}

// return boolean or true/false
bool odd(const int& val) { return (val % 2) == 1; }

int main()
{
    // Initializing ways

    list<int> list1;
    list<int> list2(4, 10); // same as below
    // list<int> list2;
    // list2.assign(4,10);
    print(list2);
    list<int> list3 {4,5,6,7};
    print(list3);
    list<int> list4 ({4,5,6,7});
    print(list4);
    list<int> list5 = {4,5,6,7};
    print(list5);

    list<char> list6 ({'a', 'b', 'c'});
    for (char c : list6)
        cout << c << " ";
    cout << endl;

    list<string> list7 = {"this", "is", "init"};
    for (string s : list7)
        cout << s << " ";
    cout << endl;

    // Capacity - size, max_size, empty
    // Element access - front, back
    // Iterators - begin, end, rbegin, rend, cbegin, cend, crbegin, crend

    // Modifiers - assign, push_back, pop_back, push_front, pop_front,
    //             insert, erase, swap, resize, clear, emplace, emplace_front, emplace_back
    // It's doubly linked list - hence push front/back + pop front/back and also emplace front/back
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);
    list1.push_back(40);
    list1.push_front(9);
    list1.push_front(8);
    list1.push_front(7);
    list1.push_front(6);
    cout << "push_front" << endl;
    print(list1);

    list1.pop_back();
    list1.pop_front();
    cout << "pop_back_front" << endl;
    print(list1);

    // In short : insert(itr, value)
    //            insert(itr, repitition, value)
    //            insert(itr, itr2 +1, itr2 + 3)
    list<int>::iterator it = list1.begin();
    advance(it, 2);                             // To position itr
    list1.insert(it, 800);
    print(list1);
    list1.insert(++it, 900);
    print(list1);
    //list1.insert(it + 2, 1100); // + is giving error
    //print(list1);

    list1.swap(list2);
    cout << "list1 is now : ";
    print(list1);
    cout << "list2 is now : ";
    print(list2);

    // Operations - splice, remove, remove_if, unique, merge, sort, reverse

    // list.remove(value to be removed) NOTE - list.erase(itr position or range by itrs)
    // list.remove_if() - example
    // list.unique()    - removes duplicates NOTE - list should be already sorted.
    // list.unique(BinaryPredicate name) -              BinaryPredicate name => Comparator
    //                      https://www.cplusplus.com/reference/list/list/unique/
    //                      https://www.geeksforgeeks.org/list-unique-in-c-stl/
    // list1.merge(list2) NOTE - lists should already be sorted.
    // list1.merge(list2, BinaryPredicate name) -
    //                      https://www.cplusplus.com/reference/list/list/merge/
    //                      https://www.geeksforgeeks.org/list-merge-function-in-c-stl/
    // list.sort()      - exmaple
    // list.sort(BinaryPredicate name) -
    //                      https://www.cplusplus.com/reference/list/list/sort/
    // list.reverse()   - example
    // splice In short  - main_list.splice(main_list_itr, sub_list)
    //     single ele   - main_list.splice(main_list_itr, sub_list, sub_list_itr_pos)
    //     range elents - main_list.splice(main_list_itr, sub_list, sub_list_itr1, sub_list_itr2)
    cout << "slice operation."<< endl;

    list<int> l1 = list1;
    list<int> l2 = list2;
    list<int> l3(list3);

    cout << "*************** case 1 ***************" << endl;
    print(list1);
    print(list2);
    print(list3);
    cout << "slice operation 1."<< endl;
    list2.splice(list2.end(), list1);
    print(list1);
    print(list2);
    print(list3);
    cout << "slice operation 2."<< endl;
    list3.splice(list3.end(), list2);
    print(list1);
    print(list2);
    print(list3);
    cout << "*************** case 2 ***************" << endl;
    list1 = l1;
    list2 = l2;
    list3 = l3;
    list<int>::iterator itr = list2.begin();
    list3.splice(list3.begin(), list2, itr);
    print(list1);
    print(list2);
    print(list3);
    cout << "*************** case 3 ***************" << endl;
    list1 = l1;
    list2 = l2;
    list3 = l3;
    list<int>::iterator itr1 = list2.begin();
    advance(itr1, 2);
    list<int>::iterator itr2 = list2.begin();
    advance(itr2, 5);
    list3.splice(list3.end(), list2, itr1, itr2);
    print(list1);
    print(list2);
    print(list3);

    cout << "*************** Original lists ***************" << endl;
    print(l1);
    print(l2);
    print(l3);

    cout << "*************** remove_if ***************" << endl;
    print(l2);
    l2.remove_if(odd);
    print(l2);

    cout << "*************** sort ***************" << endl;
    l2.sort();
    print(l2);

    cout << "*************** reverse ***************" << endl;
    l2.reverse();
    print(l2);
}
