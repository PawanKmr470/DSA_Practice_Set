#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// REF : https://leetcode.com/problems/group-anagrams/
// NOTES :
//        Input : strs = ["eat","tea","tan","ate","nat","bat"]
//        Output : [["bat"],["nat","tan"],["ate","eat","tea"]]
//
//        Hash map -> counts : strings
//        aet -- eat, tea, ate
//        ant -- tan, nat
//        abt -- bat
// T: O(words * chars in word * sorting) ~ O(m*n*nlogn)
// S: O(m*n) with ignoring sorting space.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> anagrams;
        for (auto &v : mp) {
            anagrams.push_back(v.second);
        }
        return anagrams;
    }
};

//  T: O(words * word count * 26) ~ O(m*n)
//  S: O(m*n)
class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string &s : strs) {
            string t = s;
            t = mysort(t);
            mp[t].push_back(s);
        }

        vector<vector<string>> anagrams;
        for (auto &v : mp) {
            anagrams.push_back(v.second);
        }
        return anagrams;
    }

    string mysort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        // t is unique ID for anagram strings
        // string (size_t n, char c);
        // fill constructor LINK - https://cplusplus.com/reference/string/string/string/
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');   // cout << string(2, 'a') << endl; => "aa"
        }
        return t;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution2 s;
    vector<vector<string>> res = s.groupAnagrams(strs);
    for (auto &i : res) {
        cout << "group : " << " ";
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}