#include <iostream>
#include <vector>
#include <map>
using namespace std;

// REF : https://leetcode.com/problems/target-sum/editorial/
// NOTES :
//      Target sum --> Same as DP10 - Count number of subset sum with given diff
//      Edge case : arr = [1,1,1] target = -700 --> not possible
//                  so abs(target) won't exceed sum value. So, abs(target) <= sum
//      we need to add '+' before some elements and '-' before some elements.
//      club all '+' elements and call it s1.
//      club all '-' elements and call it s2.
//      s1 - s2 = target (as per question)
//      s1 + s2 = sum    (we know)
//      s1 = (sum + target)/2
//                              If (sum + target) is not divisible by 2 (answer in decimal) then
//                              it means array can't be divided into two such subsets whose difference is target.
//                              Return 0 in this case (means not possible)
//      Now target can be given such that it's not possible to get target value by assigning '+' or '-' in any order.
//      That means abs(target) <= sum otherwise return 0

// T: O(2^n)
// S: O(n) stack lenght
class Solution {
public:
    int targetSum(vector<int> &set, int target) {
        int sum = 0;
        for (auto &i : set)
            sum += i;

        if (abs(target) > sum || (sum - target) % 2 != 0)    // sum - target ??
            return 0;                                   // instead sum + target % 2 != 0 also works
                                                        // bcz if it's not divisible then return 0
        int s1 = (sum + target)/2;
        return __subsetSum(set, s1, set.size());
    }

    int __subsetSum(vector<int> &set, int sum, int n) {
        if (sum == 0) return 1;
        if (n == 0 && sum > 0) return 0;

        if (set[n-1] <= sum) {
            return __subsetSum(set, sum - set[n-1], n-1) +
                    __subsetSum(set, sum, n-1);
        }
        else {
            return __subsetSum(set, sum, n-1);
        }
    }
};

// T: O(n*sum)
// S: O(n*sum) including aux space
// Tabulation method
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto &i : nums)
            sum += i;

        if (abs(target) > sum || (sum - target) % 2 != 0)
            return 0;

        int s1 = (sum + target)/2;

        vector<vector<int>> memo(nums.size()+1, vector<int> (s1 + 1, -1));
        return __subsetSum(nums, s1, nums.size(), memo);
    }

    int __subsetSum(vector<int> &set, int sum, int n, vector<vector<int>>& memo) {
        if (sum == 0) return 1;
        if (n == 0 && sum > 0) return 0;

        if (memo[n-1][sum] != -1)
            return memo[n-1][sum];

        if (set[n-1] <= sum) {
            memo[n-1][sum] = __subsetSum(set, sum - set[n-1], n-1, memo) +
                            __subsetSum(set, sum, n-1, memo);
            return memo[n-1][sum];
        }
        else {
            memo[n-1][sum] = __subsetSum(set, sum, n-1, memo);
            return memo[n-1][sum];
        }
    }
};

// Leetcode Editorial
// Non-subsetsum way approach
// T: O(2^n)
// S: O(n) stack lenght
class Solution3 {
private:
    int count;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        calculate(nums, 0, 0, target);
        return count;
    }

    void calculate(vector<int> &nums, int i, int cur_sum, int target) {
        
        if (i == nums.size()) {     // if we process all the elements
            if (cur_sum == target)  // and cur_sum gets equal to target
                count++;
        }
        else {
            calculate(nums, i + 1, cur_sum + nums[i], target);
            calculate(nums, i + 1, cur_sum - nums[i], target);
        }

    }
};

/*
    Needcode solution -
    Given int array & a target, want to build expressions w/ '+' & '-'
    Return number of different expressions that evaluates to target

    Recursion w/ memoization, cache on (index, total), which stores # ways
    If total ever reaches the target, return 1 (this is a way), else 0

    Time: O(n x target)
    Space: O(n x target)
*/
class Solution4 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums, target, 0, 0);
    }
private:
    // {(index, total) -> # of ways}
    map<pair<int, int>, int> dp;
    
    int backtrack(vector<int>& nums, int target, int i, int total) {
        if (i == nums.size()) {
            return total == target ? 1 : 0;
        }
        if (dp.find({i, total}) != dp.end()) {
            return dp[{i, total}];
        }
        
        dp[{i, total}] = backtrack(nums, target, i + 1, total + nums[i])
                       + backtrack(nums, target, i + 1, total - nums[i]);
        
        return dp[{i, total}];
    }
};


int main() {
    vector<int> set = {1,1,1,1,1};
    int target = 3;   // Question is calling this as sum
    cout << "Solution  : " << Solution().targetSum(set, target) << endl;
    cout << "Solution2  : " << Solution2().findTargetSumWays(set, target) << endl;
    cout << "Solution3 : " << Solution3().findTargetSumWays(set, target) << endl;
    return 0;
}

