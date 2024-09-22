#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/coin-change-ii/description/
// NOTES :
//      Based on Unbounded Knapsack. And it perfectly follows.
//      Unbounded Knapsack + Base condition + Recurrence relation
//      It's a DP question. But as it's asking total number of ways, it's backtracking.
//      Try to apply BT format (i.e. for loop recursion)

// Recursion (Top down approach) and i goes from n -> 0
// T: O(2^n)
// S: O(n) or O(amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(n, amount, coins);
    }

    int solve(int i, int amount, vector<int> &coins) {
        if (amount == 0)
            return 1;
        if (i == 0) {                       // At i == 1, coins[0] will be considered (last coin).
            return amount == 0 ? 1 : 0;     // But when i == 0, then it means there is no coins left and amount has reached 0 or not.
        }                                   // So we need to pass n to solve() function.

        if (coins[i - 1] <= amount)
            return solve(i - 1, amount, coins) + solve(i, amount - coins[i - 1], coins);
        else
            return solve(i - 1, amount, coins);
    }
};


// Recursion (i goes from 0 -> n)
// T: O(2^n)
// S: O(n) or O(amount)
class Solution2 {
public:
    int change(int amount, vector<int>& coins) {
        return solve(0, amount, coins);
    }

    int solve(int i, int amount, vector<int> &coins) {
        if (amount == 0)
            return 1;
        if (i == coins.size()) {
            return amount == 0 ? 1 : 0;
        }

        if (coins[i] <= amount)
            return solve(i + 1, amount, coins) + solve(i, amount - coins[i], coins);
        else
            return solve(i + 1, amount, coins);
    }
};


// Recursion + memoization (top down dp)
// T : O(n*amount)
// S : O(n*amount)
class Solution3 {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        return solve(n, amount, coins, dp);
    }

    int solve(int i, int amount, vector<int> &coins, vector<vector<int>>& dp) {
        if (amount == 0)
            return 1;
        if (i == 0) {
            return amount == 0 ? 1 : 0;
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];

        if (coins[i - 1] <= amount)
            return dp[i][amount] = solve(i - 1, amount, coins, dp) + solve(i, amount - coins[i - 1], coins, dp);
        else
            return dp[i][amount] = solve(i - 1, amount, coins, dp);
    }
};

// Tabulation (bottom up dp)
// T : O(n*amount)
// S : O(n*amount)
class Solution4 {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, 0));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[0][j] = 0;
                dp[i][0] = 1;
            }
        }

        dp[0][0] = 1;   // if no coins given then sum 0 can be achieved by selecting empty coin array (1 way)

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i-1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][amount];
    }
};

// Tabulation (bottom up dp) with space optimization
// T : O(n*amount)
// S : O(amount)
class Solution5 {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        // Conceptual approach
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j)
                    dp[j] = dp[j] + dp[j - coins[i - 1]];
            }
        }

        // This also works. dp is initialized at declaration itself (means first row is initialized)
        // so we can start from considering next row 0 or 1. coins' indexing will be required to be adjusted accordingly.
        // for (int i = 0; i < n; i++) {
        //     for (int j = 1; j <= amount; j++) {
        //         if (coins[i] <= j)
        //             dp[j] = dp[j] + dp[j - coins[i]];
        //     }
        // }

        return dp[amount];
    }
};


int main() {
    vector<int> coins {1,2,5};
    int amount = 5;
    cout << Solution().change(amount, coins) << endl;
    cout << Solution2().change(amount, coins) << endl;
    cout << Solution3().change(amount, coins) << endl;
    cout << Solution4().change(amount, coins) << endl;
    cout << Solution5().change(amount, coins) << endl;
}