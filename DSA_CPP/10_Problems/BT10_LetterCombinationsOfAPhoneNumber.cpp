#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// REF : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// NOTES :
//      Logic template is similar to the subset problem.

// T: O(n*4^n) -- "pqrs". Worst time complexity also ~ O(n*3^n)
// S: (n) Recursion height

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if (digits.empty())
            return {};

        vector<string> result;
        string cur = "";
        unordered_map<char, string> hashmap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        dfs(0, cur, hashmap, result, digits);
        return result;
    }

    void dfs(int index, string& cur, unordered_map<char, string>& hashmap,
             vector<string>& result, string& digits) {

        if (cur.size() == digits.size()) {
            result.push_back(cur);
            return;
        }

        string s = hashmap[digits[index]];
        for (int i=0; i < s.size(); i++) {
            cur.push_back(s[i]);
            dfs(index + 1, cur, hashmap, result, digits);
            cur.pop_back();
        }
    }
};