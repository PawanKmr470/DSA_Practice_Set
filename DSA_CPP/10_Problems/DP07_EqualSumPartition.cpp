#include <iostream>
#include <vector>
using namespace std;

// REF : https://www.geeksforgeeks.org/partition-problem-dp-18/
//       https://leetcode.com/problems/partition-equal-subset-sum/
// NOTES :
//      Same as subset sum problem only the difference is that -
//      if the array can be divided into equal sum then sum of all the elements
//      would be even number (2S) and problem turns into subset sum for S.

// Complete it's all approaches.

// T: O(2^n)
// S: O(n) stack lenght
class Solution {
public:
    bool canPartition(vector<int> &set) {
        int sum = 0;
        for (auto &i : set)
            sum += i;

        if (sum % 2 != 0) return false;

        sum = sum/2;
        return __subsetSum(set, sum, set.size());
    }

    bool __subsetSum(vector<int> &set, int sum, int n) {
        if (sum == 0) return true;
        if (n == 0 && sum > 0) return false;

        if (set[n-1] <= sum) {
            return __subsetSum(set, sum - set[n-1], n-1) ||
                    __subsetSum(set, sum, n-1);
        }
        else {
            return __subsetSum(set, sum, n-1);
        }
    }

};

// T: O(n*sum)
// S: O(n*sum) including aux space
// With memoization
class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto &i : nums)
            sum += i;

        if (sum % 2 != 0) return false;
        
        sum = sum/2;
        vector<vector<int>> memo (nums.size() + 1, vector<int> (sum + 1, -1));
        return __subsetSum(nums, sum, nums.size(), memo);
    }

    bool __subsetSum(vector<int> &set, int sum, int n, vector<vector<int>> &memo) {
        if (sum == 0) return true;
        if (n == 0 && sum > 0) return false;

        if (memo[n-1][sum] != -1)
            return memo[n-1][sum];

        if (set[n-1] <= sum) {
            memo[n-1][sum] = __subsetSum(set, sum - set[n-1], n-1, memo) ||
                                __subsetSum(set, sum, n-1, memo);
            return memo[n-1][sum];
        }
        else {
            memo[n-1][sum] = __subsetSum(set, sum, n-1, memo);
            return memo[n-1][sum];
        }
    }
};

int main() {
    vector<int> set = { 3, 1, 5, 9, 12 };
    cout << "Solution : " << Solution().canPartition(set) << endl;
    cout << "Solution : " << Solution2().canPartition(set) << endl;
    return 0;
}