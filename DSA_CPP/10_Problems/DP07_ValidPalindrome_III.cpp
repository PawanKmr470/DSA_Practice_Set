#include <iostream>
#include <vector>
#include <string>
using namespace std;

// REF : https://leetcode.com/problems/valid-palindrome-iii/description/
// NOTES :
//      Take start & end pointer, compare and proceed towards middle.
//      if they match then increment start and decrement end.
//      if they don't then go into decision tree with (star++ && end) OR (start && end--)
//      we have to find the minimum number of elements by which strings (start:mid and mid:end) will differ.
//      or minimum number of skipping elements by which they will be palindrome.
//      EXPLORE it's tabulation method

// T: O(2^n)
// S: O(n) stack lenght

class Solution {
private:
    vector<vector<int>> memo;
public:
    int __dfs(string &s, int i, int j) {
        if (i == j)
            return 0;

        if (i == j - 1)
            return s[i] != s[j];    // return 1 if elements don't match & 0 if they do

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] == s[j])
            return memo[i][j] = __dfs(s, i + 1, j - 1);
        else
            return memo[i][j] = 1 + min(__dfs(s, i + 1, j), __dfs(s, i, j - 1));
    }

    bool isValidPalindrome(string s, int k) {
        memo.resize(s.length(), vector<int>(s.length(), -1));
        return __dfs(s, 0, s.length() - 1) <= k;
    }
};


int main() {
    string s = "abcdeca";
    int k = 2;
    cout << "output : " << Solution().isValidPalindrome(s, k) << endl;
    return 0;
}