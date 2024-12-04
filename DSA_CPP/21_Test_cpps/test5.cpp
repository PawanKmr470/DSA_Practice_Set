#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {

    vector<int> v1 {20,20,30,20,40,30,40,50,10,20,10,40,10,10,20};
    map<int, int> freq;
    for (auto i : v1) {
        freq[i]++;
    }

    for (auto i : freq) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    vector<pair<int, int>> v2(freq.begin(), freq.end());
    sort(v2.begin(), v2.end(), [] (const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; });

    for (auto i : v2) {
        cout << i.first << " " << i.second << endl;
    }


    return 0;
}
