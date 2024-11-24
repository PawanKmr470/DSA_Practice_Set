#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// REF : https://leetcode.com/problems/permutations/
// NOTES :
//      Backtrack
//      WIRE IT
//      combination -> arrangement of elements doesn't matter (subset/powerset)
//      permutation -> arrangement of elements matters
//      It can also be solved with the help of visited set (True/False) or boolean vector.
//      2 Ways -
//          By swapping elements (progressive loop i.e. i to n-1) [Solution1]
//          By using visited array (full loop i.e. 0 to n-1) [Solution, Solution2, Solution3 all are same]
//                  Standard BT Template (full loop i.e. 0 to n-1) Based on Standard BT Template (For Loop Template)
//          
//          Why swap() method exists ? Because permutation is arrangement so swapping works
//          and doesn't work in case of combination which is a selection process.

// vector<bool> visited(nums.size(), false)
// unordered_set<int> visited;
// pay attention to these visited array and set
// set will only have unique elements but 
// boolean visited array will have status of every element as visited or not visited
//      and those elements can be duplicates.
// In this problem they both are solving same issue But in Permutations II they play differently.

// T: O(n! * n) n -> array lenght & n! is number of permutations
// S: O(n) stack lenght

// By swapping elements
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

// By using visited array
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




// Without using visited array & without swapping
// By using Standard BT Template (For loop Template)
class Solution2 {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        dfs(0, cur, nums);
        return result;
    }

    void dfs(int i, vector<int> &cur, vector<int> &nums) {
        if (cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }

        for (int j = 0; j < nums.size(); j++) {     // j is starting from 0 everytime so dfs call doesn't need i

            // if element is present in the cur then skip it
            // (either do the find operation in cur array or use a set (i.e. visited array))
            // Use set preferably as find would be O(n) operation and set would be hashset
            if (find(cur.begin(), cur.end(), nums[j]) != cur.end()) {
                cur.push_back(nums[j]);
                dfs(j + 1, cur, nums);
                cur.pop_back();
            }
        }
    }
};

// Same as Solution3 but corrected using set and i paramemter in loop
class Solution3 {
public:
    vector<vector<int>> result;
    unordered_set<int> visited;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        dfs(cur, nums);
        return result;
    }

    void dfs(vector<int> &cur, vector<int> &nums) {
        if (cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }

        for (int j = 0; j < nums.size(); j++) {

            if (visited.find(nums[j]) == visited.end()) {
                cur.push_back(nums[j]);
                visited.insert(nums[j]);
                dfs(cur, nums);
                cur.pop_back();
                visited.erase(nums[j]);
            }
        }
    }
};