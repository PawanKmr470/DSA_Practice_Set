#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/combinations/
// NOTES :
//      Subset problem just with limit of size k.
//      Note that combinations are unordered, i.e. -
//      [1,2] and [2,1] are considered to be the same combination.

// same as subset problem
// T: O(k* n!/(n-k)!*k!) - In short O(k*nCr). This is Tight Bound complexity
//  : O(n^k * k) - k for coying operation. This is Upper Bound complexity
// S: O(k) - recursion height.

// T : O(n! * n)   n! is for combination and for copying n size answer to result -> n
// S: O(k) - recursion height.

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> subset;

        dfs(1, subset, n, k, result);   // n is from 1 to n hence index starts from 1
        return result;
    }

    void dfs(int index, vector<int>& subset, int n, int k, vector<vector<int>>& result) {

        if (subset.size() == k) {
            result.push_back(subset);
            return;                     // return from here, going further not required.
        }

        for (int i=index; i <= n; i++) {
            subset.push_back(i);
            dfs(i + 1, subset, n, k, result);
            subset.pop_back();
        }
    }
};

// Same solution can be simplified by converting n into nums array
// making it subset problem with restriction of k elements.
class Solution1 {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        vector<int> subset;
        vector<int> nums;
        for (int i=1; i <= n; i++)
            nums.push_back(i);
        dfs(0, subset, nums, k);
        return result;
    }

    void dfs(int i, vector<int>& subset, vector<int>& nums, int k) {

        if (subset.size() == k) {
            result.push_back(subset);
            return;                     // return from here, going further not required.
        }

        for (int j = i; j < nums.size(); j++) {
            subset.push_back(nums[j]);
            dfs(j + 1, subset, nums, k);
            subset.pop_back();
        }
    }
};

// Solution1 and 2 are template based and correct ones.
// without for loop. Using the conventional way (i.e. include fun call then exclude fun call. No For loop)
class Solution2 {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        dfs(1, n, k, temp);
        return result;
    }

    void dfs(int i, int &n, int k, vector<int> &temp) {
        
        if (k == 0) {
            result.push_back(temp);
            return;
        }

        if (i > n) return;

        // if (i > n) {                         // also fine
        //     if (k == 0)
        //         result.push_back(temp);
        //     return;
        // }

        temp.push_back(i);
        dfs(i + 1, n, k - 1, temp);

        temp.pop_back();
        dfs(i + 1, n, k, temp);
    }
};

// Difference : n is converted into array.
class Solution3 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> subset;
        vector<int> nums;
        for (int i=1; i <= n; i++)
            nums.push_back(i);
        dfs(0, subset, nums, k, result);
        return result;
    }

    void dfs(int i, vector<int>& subset, vector<int>& nums, int k,
            vector<vector<int>>& result) {

        if (i >= nums.size()) {
            if (subset.size() == k)
                result.push_back(subset);
            return;
        }

        // including the ith element
        subset.push_back(nums[i]);
        dfs(i+1, subset, nums, k, result);

        // excluding the ith element
        subset.pop_back();
        dfs(i+1, subset,  nums, k, result);
    }
};