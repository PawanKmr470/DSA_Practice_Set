#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/unique-paths/description/
// NOTES :
//      Only two movements will be required 1. move right (m-1) 2. move down (n-1)
//      At given cell, value is the number of ways coming from adjacent cells
//      that is from above and from left.

// T: O(2^n)
// S: O(n) stack lenght
class Solution {
public:
    int uniquePaths(int m, int n) {

        // return 1 means when we reach at destination then path lenght is 1
        if (m == 1 || n == 1)
            return 1;

        int move_right = uniquePaths(m-1, n);
        int move_down  = uniquePaths(m, n-1);

        return move_right + move_down;
    }
};

class Solution1 {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;

        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};

// Rec + Memoization
// T : O(n * m)
// S : O(n * m)
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m+1, vector<int> (n+1, -1));
        return helper(m, n, memo);
    }

    int helper(int m, int n, vector<vector<int>>& memo) {
        if (m == 1 || n == 1)
            return 1;

        if (memo[m][n] != -1)
            return memo[m][n];

        memo[m][n] = helper(m-1, n, memo) + helper(m, n-1, memo);
        return memo[m][n];
    }
};


// DP (Bottom Up)
// T : O(n * m)
// S : O(n * m)
class Solution3 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 1));
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        return dp[m-1][n-1];

        // return dp[row-1][col-1]; // with 'int row,col' explicit declaration;
    }
};


/*
    Neetcode Solution :
    Given grid, return # of unique paths from top-left to bottom-right
    Ex. m = 3, n = 2 -> 3 unique paths (R->D->D, D->D->R, D->R->D)

    DP: edges have 1 unique path, inner cells consider where it comes from
    Recurrence relation: grid[i][j] = grid[i-1][j] + grid[i][j-1]

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution4 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            grid[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            grid[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        
        return grid[m - 1][n - 1];
    }
};
