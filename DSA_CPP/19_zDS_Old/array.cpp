#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
    // Initialization
    array<int, 5> ar1{{3, 4, 5, 1, 2}};
    array<int, 5> ar2 = {1, 2, 3, 4, 5};
    array <char , 3> ar3={'G','f','G'};
    array<string, 2> ar4 = {{string("abc"), "xyz"}};

    array<int, 6> arr = {1,2,3,4,5,6};

    // Capacity -  size, max_size, empty
    int len = arr.size();
    int max_size = arr.max_size();
    cout << "size of the arr : " << len << endl;
    cout << "max size of the arr : " << max_size << endl; // it will return same value as .size()

    // Element access - [], at, front, back, data
    cout << "arr elements are : ";
    for (int i = 0; i < len; i++)
        cout << arr.at(i) << " ";
    cout << endl;

    cout << "first element : " << arr.front() << endl;
    cout << "last element  : " << arr.back() << endl;

    // Iterators - begin, end, rbegin, rend, cbegin, cend, crbegin, crend

    // keyword auto is very useful for reducing the verbosity of the code.
    // auto a = 2;   // a is an interger
    // auto b = 8.7; // b is a double
    // auto c = a;   // c is an integer
    // instead of - for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    // we can now write - for (auto it = v.begin(); it != v.end(); ++it)
    cout << "begin to end elements are : ";
    for (auto i = arr.begin(); i != arr.end(); i++)
        cout << *i << " ";
    cout << endl;

    cout << "rbegin to rend elements are : ";
    for (auto i = arr.rbegin(); i != arr.rend(); i++)
        cout << *i << " ";
    cout << endl;

    // Modifiers - swap, fill
    array<int, 6> arr2 = {11,22,33,44,55,66};
    arr.swap(arr2);
    cout << "swaped elements in arr2 : ";
    for (auto i = arr2.begin(); i != arr2.end(); i++)
        cout << *i << " ";
    cout << endl;
    cout << "filled elements in arr : ";
    for (auto i = arr.begin(); i != arr.end(); i++)
        cout << *i << " ";
    cout << endl;

    arr.fill(10);
    cout << "filled elements in arr : ";
    for (auto i = arr.begin(); i != arr.end(); i++)
        cout << *i << " ";
    cout << endl;

    // empty() Returns a bool value, true if the array size is 0, false otherwise.
    if (arr.empty())
        cout << "arr is empty" << endl;
    else
        cout << "arr is non empty" << endl;

    // arr.data()
    int *ptr = arr2.data();
    cout << "pointer to first element : " << ptr << endl;
    cout << "pointer's value to first element : " << *ptr << endl;
    cout << "arr through pointer" << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << *ptr++ << " ";
    cout << endl;
}