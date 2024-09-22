#include <iostream>
#include <vector>
#include <limits.h>     // For INT_MAX & INT_MIN
using namespace std;

// REF : https://leetcode.com/problems/coin-change/description/
// NOTES :
//      Unbounded Knapsack + Base condition + Recurrence relation

// Inspired by Aditya Verma solution
// https://www.youtube.com/watch?v=I-l6PBeERuc
// https://github.com/skjha1/Aditya-verma-youtube-playlist-code/blob/main/Dynamic%20Programming/13%20Coin%20change%20problem_%20Minimum%20number%20of%20coin.cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = helper(coins, amount);
        if (res == INT_MAX - 1)
            return -1;
        else
            return res;
    }

    int helper(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {

                if (i == 0)
                    dp[i][j] = INT_MAX - 1;

                if (j == 0)
                    dp[i][j] = 0;

                if (i == 1) {
                    if (j % coins[0] == 0)
                        dp[i][j] = j / coins[0];
                    else
                        dp[i][j] = dp[0][j];
                }

            }
        }

        dp[0][0] = 0;   // Minimum number of coins required to give sum 0 => is 0.

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount];
    }
};


// Inspired by Nikhil Lohia solution
// https://www.youtube.com/watch?v=NNcN5X1wsaw
// 1D array DP
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = helper(coins, amount);
        if (res == INT_MAX - 1)
            return -1;
        else
            return res;
    }

    // int helper(vector<int>& coins, int amount) {
    //     if (amount < 1) return 0;
        
    //     vector<int> dp(amount + 1);
        
    //     for (int i = 1; i <= amount; i++) {
    //         dp[i] = INT_MAX - 1;
            
    //         for (int &coin : coins) {
    //             if (coin <= i && dp[i - coin] != INT_MAX - 1) {
    //                 dp[i] = min(dp[i], 1 + dp[i - coin]);
    //             }
    //         }
    //     }
    //     return dp[amount];
    // }

    // Concept is same, this is my solution
    int helper(vector<int> &coins, int amount) {
        if (amount < 1) return 0;

        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX - 1);        // init with INT_MAX - 1
        dp[0] = 0;

        for (int j = 1; j <= amount; j++) {
            for (int i = 0; i < n; i++) {
                if (coins[i] <= j)
                    dp[j] = min(0 + dp[j], 1 + dp[j - coins[i]]);
            }
        }

        return dp[amount];
    }
};


int main() {
    vector<int> coins {1,2,5};
    int amount = 11;
    cout << Solution().coinChange(coins, amount) << endl;
    cout << Solution2().coinChange(coins, amount) << endl;

    return 0;
}