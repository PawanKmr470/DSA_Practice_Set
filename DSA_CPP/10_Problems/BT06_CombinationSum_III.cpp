#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/combination-sum-iii/
// NOTES :
//      Same combinations problem with 'sum' and 'size' constrains.
//      Like BT03_Combinations.cpp, 
//      nums array can be created and then process that Or
//      process directly on number as they are increasing order 1,2,3... or 0,1,2,3...

// T: O(k*n^k)
// S: O(k)

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {    
        vector<int> subset;
        dfs(1, 9, subset, k, n);
        return result;
    }

    void dfs(int start, int end, vector<int>& subset, int k, int target) {
        if (target == 0 && subset.size() == k) {
            result.push_back(subset);
            return;
        }

        if (target < 0)
            return;

        for (int j = start; j <= end; j++) {
            subset.push_back(j);
            dfs(j + 1, end, subset, k, target - j);
            subset.pop_back();
        }
    }
};