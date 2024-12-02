#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/subsets-ii/
// NOTES :
//      Backtrack. Subset I problem but with duplicates
//      need to skip duplcates only.
//      Sort the array first to club the duplicates at one place.
//      Sort the array & while backtracking skip the loop if adjacent elements are same.
//      Use the Standard BT Template as in Solution2 onwards

// T: O(n*2^n)
// S: O(n)

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(0, subset, nums, result);
        return result;
    }

    void dfs(int index, vector<int>& subset,
             vector<int>& nums, vector<vector<int>>& result) {

        result.push_back(subset);

        for (int i=index; i < nums.size(); i++) {

            if (i > index && nums[i] == nums[i-1])
                continue;

            subset.push_back(nums[i]);
            dfs(i+1, subset, nums, result);
            subset.pop_back();
        }
    }
};

class Solution1 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());     // Need to sort the input array to make the duplicate
        backtrack(0, subset, nums, result); // elements adjacent
        return result;
    }

    void backtrack(int i, vector<int>& subset,
                    vector<int>& nums, vector<vector<int>>& result) {

        if (i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(i+1, subset, nums, result);
        
        subset.pop_back();
        while (i+1 < nums.size() && nums[i] == nums[i+1])   // check boundary condition first
            i++;
        backtrack(i+1, subset, nums, result);
    }
};

// Using the Standard BT Template
class Solution2 {
public:
    vector<vector<int>> result; 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {    
        vector<int> subset;
        sort(nums.begin(), nums.end());         // #include <algorithm> for sort(). It will make duplicate adjacent
        backtrack(0, subset, nums);
        return result;
    }

    void backtrack(int i, vector<int>& subset, vector<int>& nums) {
        result.push_back(subset);

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1])          // Skip the duplicate iteration
                continue;
            subset.push_back(nums[j]);
            backtrack(j + 1, subset, nums);
            subset.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1,2,2};
    vector<vector<int>> result = Solution2().subsetsWithDup(nums);
    for (auto &i : result) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}