#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/subsets/description/
// NOTES :
//      Bruteforce way : cascading
//          [1] --> [], [1]
//          [1,2] --> [], [1], [2], [1,2]         Here [], [1] is common
//          only 2 is being added into [], [1] to get [2], [1,2].
//      Another approach : Backtracking
//          Where each ith element is included or excluded from the given array
//          to form a subset. Draw the decision tree.
//      GOLDEN condition :
//          Combinations vs subsets -
//          subsets are those combinations where element is present OR not present AND
//          if present then only once. Then only we can compare.
//      DP is another approach if counting subsets is asked #TODO

//      NOTE : Use the standard BT Template for solving BT problems as mentioned in Solution2 here. <<========== IMP

// T: O(n*2^n)
//      2^N subsets will be generated.
//      while generating each subset we have to copy one of the previous subset so n.
// S: O(n*2^n)
//      we have to store 2^N subsets in ans each of size O(N)
//      In Detail -
//          O(n) - we used by adding elemments into one subset list and removing from it.
//          O(n*2^n) - (if not ignored) for saving output. 2^n operation and each taking max space n.
//          O(n) - recursion height.

// Cascading
// NOTE - Prefer other two methods of backtracking. This is non-intuitive.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        // Added one empty set {} already as it always going to be present as first subset.
        vector<vector<int>> result = {{}}; // or do result.push_back({}) later.

        int n = nums.size();
        for (int i=0; i<n ; i++) {

            // we need to pick each subset from the result & add element in each subset
            // hence run the loop for result.size() times
            int size = result.size();
            for (int j = 0; j < size; j++) {
                vector<int> temp = result[j];   // take the subset from the result into temp
                temp.push_back(nums[i]);        // add the element into temp
                result.push_back(temp);         // add back temp to result
            }
        }
        return result;
    }
};

// Conventinal Backtracking Method
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        dfs(0, subset, nums, result);
        return result;
    }

    void dfs(int i, vector<int>& subset, vector<int>& nums, vector<vector<int>>& result) {

        if (i >= nums.size()) {             // With this approach subsets will get formed at the leaf level
            result.push_back(subset);       // Though they also get formed in the path but as they are at leaf level
            return;                         // better to collect them with this terminating condition.
        }

        // including the ith element
        subset.push_back(nums[i]);
        dfs(i+1, subset, nums, result);

        // excluding the ith element
        subset.pop_back();
        dfs(i+1, subset, nums, result);
    }
};

// Standard Backtracking Method (using for loop. Standard BT Template)
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        dfs(0, subset, nums, result);
        return result;
    }

    void dfs(int index, vector<int>& subset, vector<int>& nums, vector<vector<int>>& result) {
        
        result.push_back(subset);                   // First call will put [] in result and every call would form subsets
                                                    // which is collected in result
        for (int i=index; i<nums.size(); i++) {     // For loop will take care of out of bound cases.
            subset.push_back(nums[i]);
            dfs(i+1, subset, nums, result);
            subset.pop_back();
        }
    }
};

// Same logic as above just i & j are there
class Solution3 {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(0, temp, nums);
        return result;
    }

    void backtrack(int i, vector<int> &temp, vector<int>& nums) {
        result.push_back(temp);

        for (int j = i; j < nums.size(); j++) {
            temp.push_back(nums[j]);
            backtrack(j + 1, temp, nums);
            temp.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = Solution3().subsets(nums);
    for (auto &i : result) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}