// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

struct myPair
{
   int x, y, z;
};

int main() {

    stack<pair<int, int>> s;
    
    s.push({20,-2});
    s.push(make_pair(10,-1));
    s.push(pair<int,int>(30,-3));
    
    pair<int, int> p;
    p = s.top();
    cout << p.first << endl;
    cout << p.second << endl;

    cout << "*********************" << endl;

    // Triplets way 1

    stack<myPair> s1;
    s1.push({100,10,1});
    s1.push({200,20,2});
    
    myPair ret;
    ret = s1.top();
    cout << ret.x << endl;
    cout << ret.y << endl;
    cout << ret.z << endl;

    cout << "*********************" << endl;

    // Triplets way 2

    stack<pair<int, pair<int, int>>> s2;
    s2.push({500, {50, 5}});
    pair<int, pair<int, int>> out;
    out = s2.top();
    cout << out.first << endl;
    cout << out.second.first << endl;
    cout << out.second.second << endl;

    return 0;
}