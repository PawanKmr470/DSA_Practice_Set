#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

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

        int notTake = 0 + helper(i - 1, T, coins);
        int take = INT_MAX - 1;

        if (coins[i] <= T)
            take = 1 + helper(i, T - coins[i], coins);

        return min(take, notTake);
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

        int notTake = 0 + helper(i - 1, T, coins, dp);
        int take = INT_MAX - 1;

        if (coins[i] <= T)
            take = 1 + helper(i, T - coins[i], coins, dp);

        return dp[i][T] = min(take, notTake);
    }
    
};

// T: O(n*target)
// S: O(n*target)
class Solution3 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0)
                dp[0][T] = T/coins[0];
            else
                dp[0][T] = INT_MAX - 1;
        }

        for (int i = 1; i < n; i++) {
            for (int T = 0; T <= amount; T++) {
                int notTake = 0 + dp[i - 1][T];
                int take = INT_MAX - 1;

                if (coins[i] <= T)
                    take = 1 + dp[i][T - coins[i]];

                dp[i][T] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= INT_MAX - 1)
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
}