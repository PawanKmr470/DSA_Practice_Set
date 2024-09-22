#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <map>

using namespace std;

typedef pair<int, int> mypair;

class comp {
public:
    bool operator() (const int& a, const int& b) const {
        return a < b;
    }
};

int main() {
    
//    map<int, string, less<int>> mp1;
//    mp1[10] = "pawan";
//    mp1[20] = "kumar";
//    mp1[30] = "verma";
//    
//    for (auto &i : mp1) {
//        cout << i.first << " " << i.second << endl;
//    }
    
//    map<int, string, less<string>> mp2;   // Not working 'string class' as key is not accepted
//    mp2[10] = "pawan";
//    mp2[20] = "kumar";
//    mp2[30] = "verma";
    
//    map<char, int, less<int>> mp3;          // May give ambiguous result (trying to sort by value)
//    mp3['a'] = 100;                         // works in below case but don't follow
//    mp3['c'] = 200;
//    mp3['b'] = 300;
    
//    map<int, char, less<char>> mp3;           // In less<type> or greater<type>, the type is the first type in map declaration
//    mp3[100] = 'a';                           // Here it's working(sorting) as per value's char type But in above case it wasn't working
//    mp3[200] = 'c';
//    mp3[300] = 'b';
//    
//    for (auto &i : mp3) {
//        cout << i.first << " " << i.second << endl;
//    }
    
    map< int, char, comp> mp4;
    mp4[100] = 'a';
    mp4[200] = 'c';
    mp4[300] = 'b';

    for (auto &i : mp4) {
        cout << i.first << " " << i.second << endl;
    }
    
    return 0;
}