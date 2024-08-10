#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

int main(){

    cout << "*************** array ************************" << endl;

    array <int, 5> arr1 = {1, 2, 3, 4, 5};
    array <char, 3> arr2 = {'G','f','G'};
    array<string, 3> arr3 = {"abc", "pqr", "xyz"};

    // using dereferencing
    cout << "arr elements are : " << endl;
    for (int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << " ";
    cout << endl;

    // using iterator
    for (auto i = arr3.begin(); i != arr3.end(); i++)
        cout << *i << " ";
    cout << endl;

    cout << "first element : " << arr3.front() << endl;
    cout << "last element  : " << arr3.back() << endl;

    cout << "*************** vector ************************" << endl;

    // Syntax -
    // vector<int> v(size, value)
    // vector<int> v{value1, value2, value3};

    vector<int> v1(5, 0);                   // size & value are given
    vector<int> v2 = {1,2,3,4,5,6,7,8,9};   // no need to give
    // vector<int> vect { 10, 20, 30 };     // These both ways are correct. This is direct initialization.
    // vector<int> vect = { 10, 20, 30 };   // This is indirect becuase temp obj will be created and
                                            // values will be copied
    // vector<int> vect1(vect.begin(), vect.end()); // Initialize from another vector
    // vector<bool> v(10, false);
    // for (auto x : v) 
    //     cout << x << " ";

    // vector<bool> v(10, false); is equal to 
    // vector<bool> v(10); fill(v.begin(), v.end(), false);

    vector<string> v3 = {"one", "two"};

    for (auto i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;

    for (auto &i : v2) {
        cout << i << " ";
    }
    cout << endl;

    for (auto &i : v3) {
        cout << i << " ";
    }
    cout << endl;
    
    cout << "*************** list ************************" << endl;
    // list is internally a DLL

    list<int> li = {1,2,3,4};
    list<string> ls = {"this", "is", "init"};

    list<string>::iterator itr;
    for (itr = ls.begin(); itr != ls.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    for (auto &i : ls) {
        cout << i << " ";
    }
    cout << endl;


    cout << "*************** deque ************************" << endl;
    // deque is internally a vector of lists (lists here are small memory chunks)

    deque<int> dq1 = {7, 5, 16, 8};
    deque<string> dq2 = {"abc", "pqr", "xyz"};

    for (int i=0; i < dq1.size(); i++) {
        cout << dq1[i] << " ";
    }
    cout << endl;

    for (int i=0; i < dq2.size(); i++) {
        cout << dq2[i] << " ";
    }
    cout << endl;

    for (auto &s : dq2) {
        cout << s << " ";
    }
    cout << endl;

    cout << "*************** set ************************" << endl;

    // ordered set
    set<int> s1 = {40,20,10,30,10};                                 // Ascending order by default
    set<int, greater<int> > s2 = {40,20,10,30,10};                  // Descending order

    // unordered_set<int> s1 = {40,20,10,30,10};                    // same operations
    // multiset<int> ms1 = {40,20,10,30,10};                        // same operations with duplicates
    // multiset<int, greater<int>> ms2 = {40,20,10,30,10};          // same operations with duplicates

    for (auto &i : s1) {
        cout << i << " ";
    }
    cout << endl;

    set<int>::iterator itr2;
    for (itr2 = s2.begin(); itr2 != s2.end(); itr2++) {
        cout << *itr2 << " ";
    }
    cout << endl;

    cout << "*************** map ************************" << endl;

    // ordered map
    map<int, string> m1;                                            // Ascending order by default
    m1[1] = "red";
    m1[3] = "yellow";
    m1[2] = "black";
    m1.insert(pair<int, string>(4, "white"));
    m1.insert(make_pair(5, "blue"));
    // m1.insert({1, "hello"});                                     // Simplest way to initialize
    // m1.insert({2, "world"});

    map<int, string, greater<int>> m2;                              // Descending order
    m2[1] = "red";
    m2[3] = "yellow";
    m2[2] = "black";
    m2.insert(pair<int, string>(4, "white"));
    m2.insert(make_pair(5, "blue"));

    // unordered_map<int, string> um1;                              // same operation
    // multimap<int, string> mm1;                                   // same operation with duplicates
    // multimap<int, string, greater<int>> mm2;                     // same operation with duplicates

    map<int, string>::iterator itr3;
    for (itr3 = m1.begin(); itr3 != m1.end(); itr3++) {
        cout << itr3->first << " - " << (*itr3).second << endl;
    }
    cout << endl;

    for (auto &i : m2) {
        cout << i.first << " - " << i.second << endl;
    }
    cout << endl;


    map<int, vector<int>> map1;                                     // key : value array
    vector<int> vals = {10, 100, 1000};
    map1[1] = vals;

    for (auto &i : map1) {
        cout << i.first << " - ";
        vector<int> tmp = i.second;
        for (auto &j : tmp) {
            cout << j << " ";
        }
        cout << endl;
    }

    map<int, vector<string>> map2;                                  // key : string list
    vector<string> strs = {"one", "two"};
    map2[1] = strs;

    for (auto &i : map2) {
        cout << i.first << " - ";
        vector<string> strtmp = i.second;
        for (auto &j : strtmp) {
            cout << j << " ";
        }
        cout << endl;
    }

    // looping for key and value
    unordered_map<int, string> um1;
    m1['a'] = "apple";
    m1['b'] = "boy";
    m1['c'] = "cat";

    unordered_map<int, string> um2;
    m2['a'] = "amazon";
    m2['b'] = "bloomberg";
    m2['c'] = "crowdstrike";

    unordered_map<int, string>::iterator umitr1;
    unordered_map<int, string>::iterator umitr2;

    for (umitr1 = um1.begin(), umitr2 = um2.begin(); umitr1 != um1.end(); umitr1++, umitr2++) {
        cout << umitr1->first << " - " << umitr1->second << endl;
        cout << umitr2->first << " - " << umitr2->second << endl;
    }

    for (auto &[key, value] : um1) {
        cout << key << " = " << value << "\n";
        cout << key << " - " << m2.at(key) << "\n";
    }

    cout << "*************** Heap ************************" << endl;

    priority_queue<int> pq1;                                         // Max Heap
    priority_queue<int, vector<int>, greater<int>> pq2;              // Min Heap

    pq1.push(5);
    pq1.push(1);
    pq1.push(20);
    pq1.push(15);
    pq1.push(10);
    
    pq2.push(5);
    pq2.push(1);
    pq2.push(20);
    pq2.push(15);
    pq2.push(10);

    while (!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;

    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;

    cout << "*************** String ************************" << endl;

    string str1 = "pawan";
    cout << str1.append("verma") << endl;

    string str2 = "ducati";
    str2.push_back('p');
    cout << str2 << endl;

    cout << str2 + "gale" << endl;  // + is as good as append

    cout << "************** comparator ******************" << endl;

    // each element in arr is a vector of pair of ints
    vector<pair<int, int>> arr[4];
    arr[0].push_back({0, 0});
    arr[1].push_back({1, 10});
    arr[2].push_back({2, 20});
    arr[3].push_back({3, 30});

    sort(arr, arr + 4);

    for (int i = 0; i < 4; i++) {
        cout << "src - " << i << " ";
        for (auto &j : arr[i]) {
            cout << "dst - " << j.first << " wt - " << j.second << endl;
        }
        cout << endl;
    }
}
