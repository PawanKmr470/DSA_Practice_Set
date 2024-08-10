#include <iostream>
#include <vector>
#include <string>
using namespace std;

// REF : https://leetcode.com/problems/generate-parentheses/
// NOTES :
//      Backtracking -
//      Decison tree with 4 rules -
//  	1. Start with Open
//	    2. Open < N
//	    3. Close < Open
//      It can be solved with DP also. Explore it. Recursion can't handle if n is big.

// T: O(n*2^(2n))
// S: O(2n) Recursion height

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        findAll("(", 1, 0, result, n);
        return result;
    }

    void findAll(string cur, int open, int close, vector<string>& result, int n) {

        if (cur.size() == 2*n) {
            result.push_back(cur);
            return;
        }

        if (open < n)
            findAll(cur + "(", open + 1, close, result, n);
        if (close < open)
            findAll(cur + ")", open, close + 1, result, n);
    }
};