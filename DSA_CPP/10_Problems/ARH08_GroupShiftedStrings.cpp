// REF : https://leetcode.com/problems/group-shifted-strings/description/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> map;

        for (auto &s : strings) {
            string skey = "";
            for (int i = 0; i < s.size() - 1; i++) {
                int diff = ( (s[i + 1] - s[i]) + 26 ) % 26;
                skey = skey + to_string(diff) + ',';
            }

            map[skey].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &i : map) {
            res.push_back(i.second);
        }
        return res;
    }
};


int main() {
    vector<string> s = {"abc","bcd","acef","xyz","az","ba","a","z"};
    vector<vector<string>> ans;
    ans = Solution().groupStrings(s);
    for (auto &i : ans) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}