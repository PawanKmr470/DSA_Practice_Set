#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/palindrome-partitioning/
// NOTES :
//      Start partitioning from 0 index to n-1 and keep checking for palindrome

// T: O(n*2^n) - There could be 2^n possible substrings in the worst case. 
//                  For each substring, it takes O(n) time to GENERATE the substring and
//                  determine if it is a palindrome or not.
// S: O(n) - This space will be used to store the recursion stack.

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> cur;
        backtrack(0, cur, s, result);
        return result;
    }

    void backtrack(int index, vector<string>& cur,
                    string& s, vector<vector<string>>& result) {

        if (index == s.size()) {
            result.push_back(cur);
            return;
        }

        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                cur.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, cur, s, result);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};