#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/combination-sum-iii/
// NOTES :
//      Same combinations problem with 'sum' and 'size' constrains.

// T: O(k*n^k)
// S: O(k)

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> subset;

        dfs(1, 9, subset, k, n, result);
        return result;
    }

    void dfs(int start, int end, vector<int>& subset, int k, int target,
            vector<vector<int>>& result) {

        if (target == 0 && subset.size() == k) {    // only added if confition
            result.push_back(subset);
            return;
        }

        for (int i=start; i<=end; i++) {
            subset.push_back(i);
            dfs(i+1, end, subset, k, target-i, result);
            subset.pop_back();
        }

    }
};