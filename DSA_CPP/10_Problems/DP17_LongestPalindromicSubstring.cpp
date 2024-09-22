#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/longest-palindromic-substring/description/
// NOTES :
//      Check palindrome by expanding from center to both sides for each character
//      Solution1 : Recursion + Memoization
//                  Important DP Question (int j = i)
//                  DP - https://www.youtube.com/watch?v=n_kL8BkURVA
//                  ******************** Explore tabulation method ********************
//      Solution2 : Two pointers - Neetcode

// Recusion
// T : O(n^3)
// S : O(1) (n/2 is for helper call stack ~ n)
class Solution1 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxStart = 0;
        int maxLen = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (helper(s, i, j) == true) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        maxStart = i;
                    }
                }
            }
        }

        return s.substr(maxStart, maxLen);
    }

    bool helper(string& s, int i, int j) {
    if (i >= j)
        return true;    // Base condition : if indices have reached here means string was palindrome
    
    if (s[i] == s[j])
        return helper(s, i + 1, j - 1);
    else
        return false;
    }
};

// DP (Recurison + Memoization)
// T : O(n^2)
// S : O(n^2)
class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        int maxStart = 0;
        int maxLen = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (helper(s, i, j, dp) == 1) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        maxStart = i;
                    }
                }
            }
        }

        return s.substr(maxStart, maxLen);
    }

    int helper(string& s, int i, int j, vector<vector<int>>& dp) {
    if (i >= j)
        return 1;    // Base condition : if indices have reached here means string was palindrome
    
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = helper(s, i + 1, j - 1, dp);
    else
        return dp[i][j] = 0;
    }
};

// Expanding from centers (Two Pointers)
// T : O(n^2)
// S : O(1)
class Solution3 {
public:
    string longestPalindrome(string s) {
        int maxStart = 0;
        int maxLen = INT_MIN;       // or 0
        

        for (int i = 0; i < s.size(); i++) {
            palindrome(s, i, i, maxStart, maxLen);      // Odd case
            palindrome(s, i, i + 1, maxStart, maxLen);  // Even case
        }

        return s.substr(maxStart, maxLen);
    }

    void palindrome (string s, int i, int j, int& maxStart, int& maxLen) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }

        if (j - i - 1 > maxLen) {
            maxLen = j - i - 1;
            maxStart = i + 1;
        }
    }
};

int main() {
    string s = "babad";
    cout << Solution1().longestPalindrome(s) << endl;
    cout << Solution2().longestPalindrome(s) << endl;
    cout << Solution3().longestPalindrome(s) << endl;
}