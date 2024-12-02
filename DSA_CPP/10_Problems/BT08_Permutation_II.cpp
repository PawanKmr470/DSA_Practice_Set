#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// REF : https://leetcode.com/problems/permutations-ii/  
// (only difference from Permutations I is that it contains duplicates)
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
//
// NOTES :
//      Here 3 ways have been shown -
//          1. What used in Subset II & Combination II problems i.e. sorting input and skipping loop for adjacent duplicate elements
//              Sort the array first to club the duplicates at one place.
//              Similar logic like Subset II & Combination Sum II for handling duplicate elements.
//              BT02_Subsets_II.cpp & BT05_CombinationSum_II.cpp
//          2. By using frequency counter.
//          3. By using swap method (with unordered set).
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

// Approach 2 & 3 are good.

// Approach 1
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> visited (nums.size(), false);

        sort(nums.begin(), nums.end());         // This sort() line wrt Permutations I problem
        dfs(cur, visited, result, nums);
        return result;
    }

    void dfs(vector<int>& cur, vector<bool>& visited,
             vector<vector<int>>& result, vector<int>& nums) {

        if (cur.size() == nums.size() && 
            // check duplicates getting added into result & skip them
            find(result.begin(), result.end(), cur) == result.end()) {      // And this second line wrt Permutations I problem
            
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


// Approach 1 (duplicate condition moved from base condition block to for loop)
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
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) continue;           // Unable to understand 

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


// Approach 2 (By using freqency counter)
// T : O(n! * n)
// S : O(n + n ~ n) Auxiliary space + recursion space 
class Solution2 {
public:
    int n;
    vector<vector<int>> result;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        unordered_map<int, int> mp;
        n = nums.size();

        for (auto i : nums) {
            mp[i]++;
        }

        solve(temp, mp);
        return result;
    }

    void solve(vector<int> &temp, unordered_map<int, int> &mp) {

        if (temp.size() == n) {
            result.push_back(temp);     // O(n) for copying elements into result 
            return;
        }

        for (auto &ele : mp) {          // For loop running from 0 to n-1 NOT index to n-1
            if (ele.second == 0)        // If freq is 0 then skip the element
                continue;
            
            temp.push_back(ele.first);
            mp[ele.first]--;

            solve(temp, mp);

            temp.pop_back();
            mp[ele.first]++;
        }
    }
};


// By using swap method + set for removing duplicate decision path
// Set will be local to each function call - LOCAL SET
class Solution3 {
public:
    int n;
    vector<vector<int>> result;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        solve(0, nums);
        return result;
    }

    void solve(int index, vector<int>& nums) {

        if (index == n) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> uniqueSet;
        for (int i = index; i < n; i++) {
            if (uniqueSet.find(nums[i]) != uniqueSet.end())
                continue;
            
            uniqueSet.insert(nums[i]);
            swap(nums[index], nums[i]);

            solve(index + 1, nums);

            swap(nums[index], nums[i]);
        }
    }
};