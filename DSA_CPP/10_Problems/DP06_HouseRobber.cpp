#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/house-robber/description/
// NOTES :
//      Base condition - If no houses, return 0
//                       If 1 house, return that money
//      Decision tree - maxof(rob current house + call rec fun for n-2, 
//                            skip current house and call rec fun directly for n-1)
//      1-D DP problem

/*
T - O(2^n)
S - O(n) The max depth of recursion can go upto n.
*/
class Solution1
{
public:
    int rob(vector<int>& nums) {
        //return recRob(nums, nums.size()-1);
        return recRob2(nums, 0);
    }
    int recRob(vector<int>& nums, int n) {
        if (n < 0) return 0;
        if (n == 0) return nums[0];
        return max(nums[n] + recRob(nums, n-2), recRob(nums, n-1));
    }

    int recRob2(vector<int>& nums, int n) {
        if (n >= nums.size()) return 0;
        return max(nums[n] + recRob2(nums, n+2), recRob2(nums, n+1));
    }
};

/*
T - O(n)
S - O(n) Required for dp and implicit recursive stack.
*/
class Solution2
{
public:
    int rob(vector<int>& nums) {
        vector<int> dp (nums.size()+1, 0);
        return recRob2(nums, 0, dp);
    }

    int recRob2(vector<int>& nums, int n, vector<int>& dp) {
        if (n >= nums.size()) return 0;
        if (dp[n] != 0) return dp[n];
        dp[n] = max(nums[n] + recRob2(nums, n+2, dp), recRob2(nums, n+1, dp));
        return dp[n];
    }
};

/*
T - O(n)
S - O(n) Required for dp.
*/
class Solution3
{
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size()+1, 0);

        dp[0] = 0;                          // Initialization of tabulation
        dp[1] = nums[0];                    // we can put max(num[0], 0)
        for (int i=2; i<=nums.size(); i++) {
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);  // only prev 2 elements are being used to
                                                        // calculate dp[i]. So two variable will work
                                                        // instead of 1D array.
        }
        return dp[nums.size()];

        /* for (int i=1; i< nums.size(); i++) {         // just different looping, same result.
            dp[i+1] = max(nums[i] + dp[i-1], dp[i]);
        }
        return dp[nums.size()]; */
    }
};

/*
T - O(n)
S - O(1) Required only two variables.
*/
class Solution4
{
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int one = nums[0];
        int two = max(one, nums[1]);
        for (int i=2; i<nums.size(); i++) {
            int tmp = two;
            two = max(nums[i]+one, two);
            one = tmp;
        }
        return two;
        // dp [0, 1, 2, 4, 4] => one and two are here only. nums[i] + one(means -2 pos) OR two(-1 pos)
        // [1, 2, 3, 1]
    }
};

int main() {
    vector<int> vec = {1,2,3,1};
    Solution1 s1;
    cout << "Solution 1 : ";
    cout << s1.rob(vec) << endl;

    Solution2 s2;
    cout << "Solution 2 : ";
    cout << s2.rob(vec) << endl;

    Solution3 s3;
    cout << "Solution 3 : ";
    cout << s3.rob(vec) << endl;

    Solution4 s4;
    cout << "Solution 4 : ";
    cout << s4.rob(vec) << endl;
    return 0;
}
