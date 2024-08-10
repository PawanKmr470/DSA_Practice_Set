#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(40);
    for (auto &i:s){
        cout << i << " ";
    }
    cout << endl;
    if (s.find(10) != s.end()){
        cout << "found" << endl;
    }
    else{
        cout << "didn't find" << endl;
    }
}