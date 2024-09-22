#include <iostream>
#include <vector>
using namespace std;

// Ref : https://leetcode.com/problems/longest-increasing-subsequence/description/
// NOTES :
//      Solution refs -
//          https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/


// GFG - This is Recursion only solution.
//       It's Memoization & DP solution needs to be analyzed
// T : O(2^n)
// S : O(1) for no extra space But O(n) for stack length
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            res = max(res, ending_till_i(nums, i));
        }

        return res;
    }

    int ending_till_i(vector<int>& nums, int i) {
        if (i == 0)
            return 1;
        
        int cur_max = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                cur_max = max(cur_max, 1 + ending_till_i(nums, j))
        }

        return cur_max;
    }
};

// TakeUForward - https://www.youtube.com/watch?v=ekcwMsSIzVc
// T : O(2^n)
// S : O(1) for no extra space But O(n) for stack length
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums, 0, -1);
    }

    int helper(vector<int>& nums, int i, int prev_i) {
        if (i == nums.size())
            return 0;

        int len = 0 + helper(nums, i + 1, prev_i);          // not take
        if(prev_i == -1 || nums[i] > nums[prev_i])
            len = max(len, 1 + helper(nums, i + 1, i));     // take
        
        return len;
    }
};


// Same as above, variables adjusted
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums, 0, -1);
    }

    int helper(vector<int>& nums, int i, int prev_i) {
        if (i == nums.size())
            return 0;

        int notTake=0, take=0;
        
        notTake = 0 + helper(nums, i + 1, prev_i);      // not take
        if(prev_i == -1 || nums[i] > nums[prev_i])
            take = 1 + helper(nums, i + 1, i);          // take
        
        return max(notTake, take);
    }
};


// Same with Recursion + Memoization
// T : O(n^2)
// S : O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return helper(nums, 0, -1, dp);
    }

    int helper(vector<int>& nums, int i, int prev_i, vector<vector<int>>& dp) {
        if (i == nums.size())
            return 0;

        if (dp[i][prev_i + 1] != -1)
            return dp[i][prev_i + 1];

        int notTake=0, take=0;
        
        notTake = 0 + helper(nums, i + 1, prev_i, dp);      // not take
        if(prev_i == -1 || nums[i] > nums[prev_i])
            take = 1 + helper(nums, i + 1, i, dp);          // take
        
        return dp[i][prev_i + 1] = max(notTake, take);
    }
};


// codestorywithMIK
// Recursion + Memoization 
// https://www.youtube.com/watch?v=DG50PJIx2SM
// TODO

// DP - https://www.youtube.com/watch?v=h9rm4N8XbL0
// T : O(n^2)
// S : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int result = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        
        return result;
    }
};

// lower bound solution / Binary Search
// https://www.youtube.com/watch?v=dWmh3O8uX8A
// T : O(nlogn)
// S : O(n)
// TODO
