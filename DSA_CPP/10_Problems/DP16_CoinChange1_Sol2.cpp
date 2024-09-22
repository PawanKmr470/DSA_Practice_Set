#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//      Simplified version of DP15_CoinChange1_Sol1.cpp

// REF : https://leetcode.com/problems/coin-change/description/
// NOTES :
//      Question is - Return min number of coins to make up the given amount.
//      Based on Unbounded Knapsack.
//      Unbounded Knapsack + Base condition + Recurrence relation
//      
//      Revision -
//      Ques : subset sum is possible or not
//      Ans  : We performed || operation in choice diagram
//      Ques : count of subset sum OR Max number of ways for subset sum
//      Ans  : We performed + operation in choice diagram
//      
//      When 'count number of ways' is asked then do + in choice diagram.
//      Basically add all the possible choices.
//      For Min number of ways, take min(include, exclude)
//      For Max number of ways, take max(include, exclude)

// T: O(2^n)
// S: O(n) or O(target)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = helper(n - 1, amount, coins);
        if (ans >= INT_MAX - 1)
            return -1;
        return ans;
    }

    int helper(int i, int T, vector<int>& coins) {
        if (i == 0) {
            if (T % coins[0] == 0)
                return T/coins[0];
            return INT_MAX - 1;
        }

        if (coins[i] <= T)
            return min(helper(i - 1, T, coins), 1 + helper(i, T - coins[i], coins));
        else
            return helper(i - 1, T, coins);
    }
    
};

// T: O(n*target)
// S: O(n*target)
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, dp);
        if (ans >= INT_MAX - 1)
            return -1;
        return ans;
    }

    int helper(int i, int T, vector<int>& coins, vector<vector<int>>& dp) {
        if (i == 0) {
            if (T % coins[0] == 0)
                return T/coins[0];
            return INT_MAX - 1;
        }

        if (dp[i][T] != -1)
            return dp[i][T];

        if (coins[i] <= T)
            return dp[i][T] = min(helper(i - 1, T, coins, dp), 1 + helper(i, T - coins[i], coins, dp));
        else
            return dp[i][T] = helper(i - 1, T, coins, dp);
    }

};

// T: O(n*target)
// S: O(n*target)
class Solution3 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));      // [n][amount+1]

        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0)
                dp[0][T] = T/coins[0];
            else
                dp[0][T] = INT_MAX - 1;
        }

        for (int i = 1; i < n; i++) {
            for (int T = 0; T <= amount; T++) {
                if (coins[i] <= T)
                    dp[i][T] = min(0 + dp[i - 1][T], 1 + dp[i][T - coins[i]]);
                else
                    dp[i][T] = dp[i - 1][T];
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= INT_MAX - 1)
            return -1;
        return ans;
    }
};

// Here initialization logic has been changed.
// No second row initialization.
class Solution31 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));      // [n+1][amount+1]

        // for (int T = 0; T <= amount; T++) {
        //     if (T % coins[0] == 0)
        //         dp[0][T] = T/coins[0];
        //     else
        //         dp[0][T] = INT_MAX - 1;
        // }
        for (int T = 1; T <= amount; T++) {
            dp[0][T] = INT_MAX - 1;
        }
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int T = 0; T <= amount; T++) {
                if (coins[i-1] <= T)
                    dp[i][T] = min(0 + dp[i - 1][T], 1 + dp[i][T - coins[i-1]]);
                else
                    dp[i][T] = dp[i - 1][T];
            }
        }

        int ans = dp[n][amount];
        if (ans >= INT_MAX - 1)
            return -1;
        return ans;
    }
    
};


// T: O(n*target)
// S: O(target)
class Solution4 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX - 1);        // init with INT_MAX - 1
        dp[0] = 0;


        for (int j = 1; j <= amount; j++) {
            for (int i = 0; i < n; i++) {
                if (coins[i] <= j)
                    dp[j] = min(0 + dp[j], 1 + dp[j - coins[i]]);
            }
        }

        // This loop also works. In later one, loops are exchanged.
        // Swapping loop doesn't work all the times.
        // for (int i = 0; i < n; i++) {
        //     for (int j = 1; j <= amount; j++) {
        //         if (coins[i] <= j)
        //             dp[j] = min(0 + dp[j], 1 + dp[j - coins[i]]);
        //     }
        // }

        // This will also work as per convention logic.
        // Conceptual approach
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= amount; j++) {
        //         if (coins[i-1] <= j)
        //             dp[j] = min(0 + dp[j], 1 + dp[j - coins[i-1]]);
        //     }
        // }

        int ans = dp[amount];
        if (ans == INT_MAX - 1)
            return -1;
        return ans;
    }
};

int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << Solution().coinChange(coins, amount) << endl;
    cout << Solution2().coinChange(coins, amount) << endl;
    cout << Solution3().coinChange(coins, amount) << endl;
    cout << Solution31().coinChange(coins, amount) << endl;
    cout << Solution4().coinChange(coins, amount) << endl;
}