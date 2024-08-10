#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
    // NOTE - copying of each array element into iterator variable. To avoid copying use reference operator &

    int a[] = {0, 1, 2, 3, 4, 5};     
    for (int &n : a)
        cout << n << ' ';
    cout << endl;

    string s{"abcd"};
    for(auto &c : s)
        cout << c << " ";
    cout << endl;

    array<int, 6> arr = {1,2,3,4,5,6};
    for (auto &i : arr)
        cout << i << " ";
    cout << endl;

    for (auto i = arr.begin(); i != arr.end(); i++)
        cout << *i << " ";
    cout << endl;

    vector<int> vect{ 10, 20, 30 };
    for (auto &x : vect)
        cout << x << " ";
    cout << endl;

    vector<int> v = {1, 2, 3, 4, 5};
    for (auto &i : v)
        std::cout << i << ' ';
    cout << endl;

    for (int n : {0, 1, 2, 3, 4, 5})
        cout << n << ' ';
    cout << endl;

    map <int, int> MAP({{1, 1}, {2, 2}, {3, 3}});
    for (auto &i : MAP)
        cout << '{' << i.first << ", " 
            << i.second << "}\n";
}