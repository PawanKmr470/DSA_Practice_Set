#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &v)
{
    for (auto &i : v)
        cout << i << " ";
    cout << endl;

    /* for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl; */
}

int main()
{
    // Initializing ways

    vector<int> vec(5, 0);  // size , value

    for (auto i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    for (auto &i : vec)
        cout << i << " ";
    cout << endl;

    vector<int> v(20);  // only size
    for (auto &i : v)
        cout << i << " ";
    cout << endl;

    vector<int> ve;
    ve.assign(8, 70);
    for (auto &i : ve)
        cout << i << " ";
    cout << endl;

    vector<int> vect {9,8,7,6,5,4,3,2,1,0};
    for (auto &i : vect)
        cout << i << " ";
    cout << endl;

    vector<int> vectr = {9,8,7,6,5,4,3,2,1,0};
    for (auto &i : vectr)
        cout << i << " ";
    cout << endl;

    // Element access - [], at, front, back, data

    // Iterators - begin, end, rbegin, rend, cbegin, cend, crbegin, crend

    // Modifiers - assign, push_back, pop_back, insert, erase, swap, clear, emplace, emplace_back

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);
    cout << "elements are : ";
    print(v1);

    cout << "front element : " << v1.front() << endl;
    cout << "last element is : " << v1.back() << endl;
    v1.pop_back();
    cout << "elements are : ";
    print(v1);

    // insert (iterator position, const value_type& val);
    // insert (iterator position, size_type n, const value_type& val);
    // insert (iterator position, InputIterator first, InputIterator last);
    // In short : insert(itr, value)
    //            insert(itr, repitition, value)
    //            insert(itr, itr2 +1, itr2 + 3)
    vector<int>::iterator it = v1.begin();

    v1.insert(it + 1, 200);
    print(v1);

    v1.insert(it + 1, 2, 1024);
    print(v1);

    vector<int> v2(2, 420);
    v1.insert(it + 1, v2.begin(), v2.end());
    cout << "before erasing element." << endl;
    print(v1);

    // erase (iterator position);
    // erase (iterator first, iterator last);
    // https://www.geeksforgeeks.org/iterator-invalidation-cpp/

    cout << "erasing element." << endl;
    // v1.erase(it); // Runtime error
    v1.erase(v1.begin() + 5);
    print(v1);

    v1.erase(v1.begin() + 3, v1.begin() + 5);
    print(v1);

    v1.swap(v2);
    cout << "v1 is : ";
    print(v1);
    cout << "v2 is : ";
    print(v2);
 
    // Capacity - size, max_size, resize, capacity, empty, reserve, shrink_to_fit
    cout << "The size of vector is " << v2.size() << endl;
    cout << "The The maximum capacity is " << v2.capacity() << endl;

    // copy vector to another
    vector<int> v3(v2);
    cout << "copied vector is : ";
    print(v3);
    cout << endl;

    cout << "clearing vector..." << endl;
    v1.clear();
    v2.clear();
    print(v1);
    print(v2);
}