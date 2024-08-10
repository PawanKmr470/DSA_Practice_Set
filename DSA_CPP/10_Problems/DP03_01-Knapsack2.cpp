#include <iostream>
#include <vector>
using namespace std;

// weight [] - [5, 4, 6, 3]
// value  [] - [10, 40, 30, 50]
// Capacity w = 10
// Calculate what maximum value knapsack can hold

// Similar Problems :
// ->Subset sum
// ->Equal sum partition
// ->Count of subsets sum with a given sum
// ->Minimum subset sum difference
// ->Count the number of subset with a given difference
// ->Target sum

/*
Basic recursion method
T - O(2^n)
S - O(1) no extra DS is required. O(n) with recursion stack lenght
*/
class Solution1
{
public:
    int knapsack(int weight[], int value[], int W, int n) {
        if (n == 0 || W == 0)
            return 0;

        if (weight[n-1] <= W) {
            return max(value[n-1] + knapsack(weight, value, W - weight[n-1], n-1),
                        knapsack(weight, value, W, n-1));
        }
        else {
            return knapsack(weight, value, W, n-1);
        }
    }
};

// Same as Solution1 but caller passed n-1 for array size.
class Solution2
{
public:
    int knapsack(int weight[], int value[], int W, int n) {
        if (n == 0 || W == 0)
            return 0;

        if (weight[n] <= W) {
            return max(value[n] + knapsack(weight, value, W - weight[n], n-1),
                        knapsack(weight, value, W, n-1));
        }
        else {
            return knapsack(weight, value, W, n-1);
        }
    }
};

// Recursion + Memoization
/*
T - O(n*W)
S - O(n*W) becuase of additional DS.
*/
class Solution3 {
public:
    int knapsack(int weight[], int value[], int W, int n) {
        vector<vector<int>> memo(n+1, vector<int> (W+1, -1));
        return helper(weight, value, W, n, memo);
    }

    int helper(int weight[], int value[], int W, int n, vector<vector<int>> &memo) {
        if (n == 0 || W == 0)
            return 0;

        if (weight[n-1] <= W) {
            memo[n][W] = max(value[n-1] + knapsack(weight, value, W-weight[n-1], n-1),
                                knapsack(weight, value, W, n-1));
            return memo[n][W];
        }
        else {
            memo[n][W] = knapsack(weight, value, W, n-1);
            return memo[n][W];
        }
    }
};

// Recursion + Memoization
// Same as Solution3 but caller passed n-1 for array size.
class Solution4 {
public:
    int knapsack(int weight[], int value[], int W, int n) {
        vector<vector<int>> memo(n+1, vector<int> (W+1, -1));
        return helper(weight, value, W, n, memo);
    }

    int helper(int weight[], int value[], int W, int n, vector<vector<int>> &memo) {
        if (n == 0 || W == 0)
            return 0;

        if (weight[n] <= W) {
            memo[n][W] = max(value[n] + knapsack(weight, value, W-weight[n], n-1),
                                knapsack(weight, value, W, n-1));
            return memo[n][W];
        }
        else {
            memo[n][W] = knapsack(weight, value, W, n-1);
            return memo[n][W];
        }
    }
};

// Using DP
// Rec+Memo solution's base conditions are the initialization condition of DP solution.
// Now passing array size n-1 won't work (can be made but avoid) 
// as we would need to create dp array of [n+2][W+1]
// So always pass n=vec.size() don't pass vec.size()-1
/*
T - O(n*W)
S - O(n*W)
*/
class Solution5 {
public:
    int knapsack(int weight[], int value[], int W, int n) {
        // int dp[n+1][W+1] = {0};
        // Can't be initialized bcz n & W are not determined.
        // Correct way is -
        // int dp[5][11] = {0};
        // If need to use n,W then only declare it and initialize it separately.
        int dp[n+1][W+1];
        // memset(dp, 0, sizeof(dp));
        memset(dp, 0, (n+1)*(W+1)*sizeof(int));

        // If vector had been taken then -
        // vector<vector<int>> dp(n+1, vector<int> (W+1, 0));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                if (weight[i-1] <= j) {
                    dp[i][j] = max(value[i-1] + dp[i - 1][j - weight[i-1]],
                                    dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }

        }

        return dp[n][W];

    }
};

// DP solution with row & col terminology
class Solution6 {
public:
    int knapsack(int weight[], int value[], int W, int n) {
        int dp[n+1][W+1];
        memset(dp, 0, (n+1)*(W+1)*sizeof(int));

        for (int row = 0; row <= n; row++) {
            for (int col = 0; col <= W; col++) {
                if (row == 0 || col == 0)
                    dp[row][col] = 0;
            }
        }

        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= W; col++) {
                if (weight[row - 1] <= col) {
                    dp[row][col] = max(value[row-1] + dp[row - 1][col - weight[row-1]],
                                    dp[row - 1][col]);
                }
                else {
                    dp[row][col] = dp[row - 1][col];
                }
            }

        }

        return dp[n][W];
    }
};

// 1D DP solution
/*
T - O(n*W)
S - O(W)    Space complexity is optimized. NOTE - w loop is in decrement manner why bcz filling it right to 
            to left will not overwrite previous values which represents prev row array.
*/
class Solution7 {
public:
    int knapsack(int weight[], int value[], int W, int n) {
        int dp[W+1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            for (int j = W; j >= 0; j--) {
                if (weight[i - 1] <= j) {
                    dp[j] = max(value[i - 1] + dp[j - weight[i - 1]], dp[j]);
                }
            }
        }

        return dp[W];
    }
};

// 1D solution with row & col terminology
class Solution8 {
public:
    int knapsack(int weight[], int value[], int W, int n) {
        int dp[W+1];
        memset(dp, 0, sizeof(dp));

        for (int row = 1; row <= n; row++) {
            for (int col = W; col >= 0; col--) {
                if (weight[row - 1] <= col) {
                    dp[col] = max(value[row - 1] + dp[col - weight[row - 1]], dp[col]);
                }
            }
        }

        return dp[W];
    }
};

int main() {
    int weight[] = { 5, 4, 6, 3 };
    int value[] = { 10, 40, 30, 50 };
    int W = 10;
    int n = sizeof(value) / sizeof(value[0]);

    // using arrays
    cout << "Solution 1 : ";
    Solution1 s1;
    cout << s1.knapsack(weight, value, W, n) << endl;

    cout << "Solution 2 : ";
    Solution2 s2;
    cout << s2.knapsack(weight, value, W, n-1) << endl;

    cout << "Solution 3 : ";
    Solution3 s3;
    cout << s3.knapsack(weight, value, W, n) << endl;

    cout << "Solution 4 : ";
    Solution4 s4;
    cout << s4.knapsack(weight, value, W, n-1) << endl;

    cout << "Solution 5 : ";
    Solution5 s5;
    cout << s5.knapsack(weight, value, W, n) << endl;

    cout << "Solution 6 : ";
    Solution6 s6;
    cout << s6.knapsack(weight, value, W, n) << endl;

    cout << "Solution 7 : ";
    Solution7 s7;
    cout << s7.knapsack(weight, value, W, n) << endl;

    cout << "Solution 8 : ";
    Solution8 s8;
    cout << s8.knapsack(weight, value, W, n) << endl;
}