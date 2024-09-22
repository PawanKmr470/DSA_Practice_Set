#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/palindromic-substrings/
// NOTES :
//      Brute force - populate all substrings and check for palindrome
//          T : O(n^3)
//      Optimized approach -
//      Two pointers - Neetcode
//      Check palindrome by expanding from center to both sides for each character
//      This will expand in fashion like - 1, 3, 5, 7...
//      For even case also we need to perform this operation
//      select two elements as middle then expand from center then expand fashion will be like - 2, 4, 6...
//      Rest approaches can be like Recursion, Recursion + Memoization like DP17_LongestPalindromicSubstring.cpp

// Recusion
// T : O(n^2)
// S : O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            palindrome(s, i, i, res);
            palindrome(s, i, i + 1, res);
        }

        return res;
    }

    void palindrome(string s, int i, int j, int& res) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
            res++;      // every true case needs to be counted
        }
    }
};

int main() {
    string s = "aaa";
    cout << Solution().countSubstrings(s) << endl;
}