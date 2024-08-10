#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/permutations/
// NOTES :
//      Backtrack
//      WIRE IT
//      combination -> arrangement of elements doesn't matter (subset/powerset)
//      permutation -> arrangement of elements matters
//      It can also be solved with the help of visited set (True/False) or boolean vector.

// T: O(n! * n) n -> array lenght & n! is number of permutations
// S: O(n) stack lenght

// With using visited array
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> visited (nums.size(), false);
        dfs(cur, visited, result, nums);
        return result;
    }

    void dfs(vector<int>& cur, vector<bool>& visited,
             vector<vector<int>>& result, vector<int>& nums) {

        if (cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }

        // IMP : for loop starts from i = 0 (full loop)
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                cur.push_back(nums[i]);
                visited[i] = true;
                dfs(cur, visited, result, nums);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
};


// With swapping elements
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        // cur won't be required as we're swapping elements in nums array
        // and storing into result
        dfs(0, result, nums);
        return result;
    }

    void dfs(int index, vector<vector<int>>& result, vector<int>& nums) {

        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        // IMP : FOR loop starts from i = index (progressive loop)
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);     // swap it
            dfs(index + 1, result, nums);
            swap(nums[index], nums[i]);     // swap it back
        }
    }
};


// Without using visited array & without swapping
class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(cur, result, nums);
        return result;
    }

    void dfs(vector<int>& cur, vector<vector<int>>& result, vector<int>& nums) {

        if (cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }

        // loop runs for all elements i.e. from i = 0 (full loop)
        for (auto num : nums) {

            // if element is present in the cur then skip it
            // (bcz we are skipping the visited element)
            if (find(cur.begin(), cur.end(), num) != cur.end())
                continue;

            cur.push_back(num);
            dfs(cur, result, nums);
            cur.pop_back();
        }
    }
};

