#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/combination-sum/description/
// NOTES :
//      Important Question - Repition is allowed. Any number can be chosen any number of times.
//      It's said that it's similar to that coin change 2 problem using DP. visit that and try DP solution.
//      #TODO
//      total == target can be replaced like total == 0 then caller will be dfs(i, comb, total - candidates[i])

// T: O(2^target) As decision tree is making 2 decisions at a time
// S: O(target)
// BT Template based
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {    
        vector<int> comb;
        dfs(0, comb, candidates, target);
        return result;
    }
    
    void dfs(int i, vector<int>& subset, vector<int>& nums, int target) {

        if (target == 0) {
            result.push_back(subset);
            return;
        }

        if (target < 0)     // by subtracting resultant me go into -ve. Hence condition is required.
            return;

        for (int j = i; j < nums.size(); j++) {
            subset.push_back(nums[j]);
            dfs(j, subset, nums, target - nums[j]);     // j is not incremented because same number can be picked again
            subset.pop_back();
        }
    }
};

class Solution1 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        dfs(0, comb, 0, candidates, target, result);
        return result;
    }

    void dfs(int i, vector<int>& comb, int total, 
        vector<int>& candidates, int target, vector<vector<int>>& result) {

        if (total == target) {
            result.push_back(comb);
            return;
        }

        if (total > target || i >= candidates.size())
            return;

        comb.push_back(candidates[i]);
        dfs(i, comb, total + candidates[i], candidates, target, result);    // we can pick the same element
                                                                            // hence i is not decremented.
        comb.pop_back();
        dfs(i+1, comb, total, candidates, target, result);
    }
};