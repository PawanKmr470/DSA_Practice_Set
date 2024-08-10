#include <iostream>
#include <vector>
using namespace std;

// Ref : https://leetcode.com/problems/longest-common-subsequence/

/*
Basic recursion solution.
T - O(2^n)
S - O(2^n)
*/
class Solution1 {
public:
    int lcs(string s1, string s2) {
        int result = lcs_rec(s1, s2, s1.length(), s2.length());
        return result;
    }

    int lcs_rec(string &str1, string &str2, int len1, int len2) {
        if (len1 == 0 || len2 == 0) {
            return 0;
        }
        if (str1[len1 - 1] == str2[len2 - 1]) {
            return 1 + lcs_rec(str1, str2, len1 - 1, len2 - 1);
        }
        else {
            return max(lcs_rec(str1, str2, len1, len2 - 1),     //NOTE : returning 0 here will o/p - LCSstr
                         lcs_rec(str1, str2, len1 - 1, len2));
        }
    }
};

/*
Recursion solution starting from index 0.
Earlier one is traversing backwards.
T - O(2^n)
S - O(2^n)
*/
class Solution2 {
public:
    int lcs(string s1, string s2) {
        int result = lcs_rec(s1, s2, 0, 0);
        return result;
    }

    int lcs_rec(string &str1, string &str2, int len1, int len2) {
        if (len1 == (str1.length()) || len2 == (str2.length())) {
            return 0;
        }
        if (str1[len1] == str2[len2]) {
            return 1 + lcs_rec(str1, str2, len1 + 1, len2 + 1);
        }
        else {
            return max(lcs_rec(str1, str2, len1, len2 + 1),
                         lcs_rec(str1, str2, len1 + 1, len2));
        }
    }
};

/*
Recursion solution with memoization - DP.
T - O(n)
S - O(n)
*/
class Solution3 {
public:
    int lcs(string s1, string s2) {
        vector<vector<int>> vec(s1.length() + 1, vector<int> (s2.length() + 1, -1));
        int result = lcs_rec(s1, s2, s1.length(), s2.length(), vec);
        return result;
    }

    int lcs_rec(string &str1, string &str2, int len1, int len2, vector<vector<int>> &vec) {
        if (len1 == 0 || len2 == 0) {
            return 0;
        }
        if (vec[len1][len2] != -1) {
            return vec[len1][len2];
        }
        if (str1[len1 - 1] == str2[len2 - 1]) {
            vec[len1][len2] = 1 + lcs_rec(str1, str2, len1 - 1, len2 - 1, vec);
        }
        else {
            vec[len1][len2] = max(lcs_rec(str1, str2, len1, len2 - 1, vec),
                         lcs_rec(str1, str2, len1 - 1, len2, vec));
        }
        return vec[len1][len2];
    }
};

/*
Solution using tabulation - DP And find the LCS string also.
T - O(mxn)
S - O(mxn)
*/
class Solution4 {
public:
    int lcs(string s1, string s2) {
        if (s1.empty() || s2.empty()) return 0;
        vector<vector<int>> dp(s1.length() + 1, vector<int> (s2.length() + 1, 0));
        int row, col;
        for (row = 1; row <= s1.length(); row++) {          // from row = 1
            for (col = 1; col <= s2.length(); col++) {      // from col = 1
                if (s1[row - 1] == s2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                }
                else {
                    dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
                }
            }
        }
        return dp[row - 1][col - 1]; // at the end of for loops row & col are incremented hence - 1
    }

    vector<char> get_lcs(string s1, string s2) {
        vector<char> result;
        if (s1.empty() || s2.empty()) return result;
        vector<vector<int>> dp(s1.length() + 1, vector<int> (s2.length() + 1, 0));
        int row, col;
        for (row = 1; row <= s1.length(); row++) {
            for (col = 1; col <= s2.length(); col++) {
                if (s1[row - 1] == s2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                }
                else {
                    dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
                }
            }
        }

        result = buildString(dp, s1);
        return result;
    }

    vector<char> buildString(vector<vector<int>> &dp, string s1) {
        vector<char> result;
        int row = dp.size() - 1;
        int col = dp[0].size() - 1;
        while (row != 0 && col != 0) {
            if (dp[row][col] == dp[row - 1][col]) {
                row--;
            }
            else if (dp[row][col] == dp[row][col - 1]) {
                col--;
            }
           else {
                result.insert(result.begin(), s1[row - 1]);
                row--;
                col--;
            }
        }
        return result;
    }
};

int main() {
    Solution1 s1;
    int result = s1.lcs("pawan", "pawn");
    cout << "result : " << result << endl;

    Solution2 s2;
    result = s2.lcs("pawan", "pawn");
    cout << "result : " << result << endl;

    Solution3 s3;
    result = s3.lcs("pawan", "pawn");
    cout << "result : " << result << endl;

    Solution4 s4;
    result = s4.lcs("pawan", "pawn");
    cout << "result : " << result << endl;

    vector<char> lcs_string = s4.get_lcs("pawan", "pawn");
    cout << "LCS string is : ";
    for (char &i: lcs_string) {
        cout << i;
    }
    cout << endl;

    return 0;
}