#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/combination-sum-ii/
// NOTES :
//      Subset II + Combination Sum III

// T: O(n*2^n)
// S: O(n)

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(0, subset, candidates, result, target);
        return result;
    }

    void dfs(int index, vector<int>& subset, vector<int>& nums,
             vector<vector<int>>& result, int target) {

        if (target == 0) {
            result.push_back(subset);
        }

        if (target < 0) return; // by subtracting resultant me go into -ve. Hence condition is required.

        for (int i=index; i<nums.size(); i++) {
            if (i > index && nums[i] == nums[i-1])
                continue;
            subset.push_back(nums[i]);
            dfs(i+1, subset, nums, result, target - nums[i]);
            subset.pop_back();
        }
    }
};
