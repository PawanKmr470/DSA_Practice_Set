#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/combination-sum-ii/
// NOTES :
//      Similar logic like Subset II
//      Sort the array first to club the duplicates at one place.

// T: O(n*2^n)
// S: O(n)
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(), candidates.end());     // So that duplicate elements become adjancent and we can skip them with loop
        dfs(0, subset, candidates, target);
        return result;
    }

    void dfs(int i, vector<int>& subset, vector<int>& nums, int target) {
        
        if (target < 0) return;     // by subtracting resultant me go into -ve. Hence condition is required.

        if (target == 0) {
            result.push_back(subset);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1])          // Skipping the loop for duplicate element
                continue;
            subset.push_back(nums[j]);
            dfs(j + 1, subset, nums, target - nums[j]);
            subset.pop_back();
        }
    }
};


// Another solution could be - while adding subset into result, store only unique subsets