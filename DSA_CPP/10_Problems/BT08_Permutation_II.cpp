#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/permutations-ii/
// NOTES :
//      Sort the array first to club the duplicates at one place.
//      Similar logic like Subset II & Combination Sum II for handling duplicate elements.
//      BT02_Subsets_II.cpp & BT05_CombinationSum_II.cpp
//
//      Why visited set array won't work here (as in BT07_Permutations.cpp) ?
//      because for unique elements set was working fine -
//          {1,2,3} : temp array -> {1,2} & visited set -> {1,2}, remaining is {3} which is also not visited.
//      But for duplicate case -
//          {1,1,2} : temp array -> {1,2} & visited set -> {1,2}, remaining is {1} but it is present in the visited set.
//                  so it will not let form {1,2,1}.
//      Hence Frequecy Counter is required here.


// T: O(n! * n) n -> array lenght & n! is number of permutations
// S: O(n + n) stack lenght + bool array

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> visited (nums.size(), false);

        sort(nums.begin(), nums.end());
        dfs(cur, visited, result, nums);
        return result;
    }

    void dfs(vector<int>& cur, vector<bool>& visited,
             vector<vector<int>>& result, vector<int>& nums) {

        if (cur.size() == nums.size() && 
            // check duplicates getting added into result & skip them
            find(result.begin(), result.end(), cur) == result.end()) {
            
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

class Solution1 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> visited (nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(cur, visited, result, nums);
        return result;
    }

    void dfs(vector<int>& cur, vector<bool>& visited, vector<vector<int>>& result, vector<int>& nums) {

        if (cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }

        // IMP : for loop starts from i = 0 (full loop)
        for (int i = 0; i < nums.size(); i++) {

            // skip the iteration if the element is already visited
            // if next element is duplicate then make sure previous one has been marked visited.
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) continue;

            cur.push_back(nums[i]);
            visited[i] = true;
            dfs(cur, visited, result, nums);
            cur.pop_back();
            visited[i] = false;
        }
    }
};



// https://leetcode.com/problems/permutations-ii/solutions/933190/c-4-different-solutions-with-explanations-and-tips/
// https://leetcode.com/problems/permutations-ii/solutions/3214219/best-c-3-solution-ever-easy-solution-backtracking-one-stop-solution/
//      Approach 3




