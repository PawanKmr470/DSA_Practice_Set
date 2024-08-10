#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/min-cost-climbing-stairs/description/
// NOTES :
//      Basic concept is similar to Climbing stairs but with cost associated.
//      and we have to find minimum cost.

/*
    Given cost array, ith step is cost[i], can climb 1 or 2 steps
    Return min cost to reach top floor, can start at index 0 or 1
    Ex. cost = [10,15,20] -> 15, start at idx 1, pay 15, climb 2

    Recursion w/ memoization -> DP, min cost to reach 1/2 steps below curr step
    Recurrence relation: minCost[i] = min(minCost[i-1] + cost[i-1], minCost[i-2] + cost[i-2])

    Time: O(n)
    Space: O(1)
*/

/*
Brute force method - Recursion
T - O(2^n)
S - O(2^n)
*/
class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(stairs(cost, 0), stairs(cost, 1));
    }
    int stairs(vector<int> &cost, int i) {
        if (i >= cost.size()) return 0;
        return cost[i] + min(stairs(cost, i + 1), stairs(cost, i + 2));
    }
};

/*
Memoization method - Recursion
T - O(n)
S - O(n)
*/
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp (cost.size(), 0);
        return min(stairs(cost, 0, dp), stairs(cost, 1, dp));
    }
    int stairs(vector<int> &cost, int i, vector<int> &dp) {
        if (i >= cost.size()) return 0;
        if (dp[i]) return dp[i];
        dp[i] = cost[i] + min(stairs(cost, i + 1, dp), stairs(cost, i + 2, dp));
        return dp[i];
    }
};

/*
Tabulation Method
T - O(n)
S - O(n)
*/
class Solution3 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) return min(cost[0], cost[1]);
        int n = cost.size();
        vector<int> dp (n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

/*
Tabulation Method
T - O(n)
S - O(1)
*/
class Solution4 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) return min(cost[0], cost[1]);
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];
        for (int i = 2; i < n; i++) {
            int cur = cost[i] + min(first, second);
            first = second;
            second = cur;
        }
        return min(first, second);
    }
};

int main() {
    //vector<int> cost = {10, 15, 20};
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int result;
    
    Solution1 s1;
    result = s1.minCostClimbingStairs(cost);
    cout << "Min cost is : " << result << endl;

    Solution1 s2;
    result = s2.minCostClimbingStairs(cost);
    cout << "Min cost is : " << result << endl;

    Solution1 s3;
    result = s3.minCostClimbingStairs(cost);
    cout << "Min cost is : " << result << endl;

    Solution1 s4;
    result = s4.minCostClimbingStairs(cost);
    cout << "Min cost is : " << result << endl;

    return 0;
}