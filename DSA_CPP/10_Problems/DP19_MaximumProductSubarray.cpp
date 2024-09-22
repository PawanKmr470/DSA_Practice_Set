#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/maximum-product-subarray/description/
// NOTES :
//      Brute force way -
//          calculate each subarray and max product for it (i = 0; then j = i;) and return max. O(n^2)
//      Optimized : Calculate minProduct, maxProduct while parsing array and 
//                  use previously calculated result to calculate next.
//                  Important DP Question (int j = i)
//      TakeUForward : https://www.youtube.com/watch?v=hnswaLJvr6g


// Brute force
// T : O(n^2)
// S : O(1)
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int result = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int accu = 1;
            for (int j = i; j < nums.size(); j++) {
                accu *= nums[j];
                result = max(result, accu);
            }
        }

        return result;
    }
};

// Optimized
// T : O(n)
// S : O(1)
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int curMin = 1;
        int curMax = 1;
        int res = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];

            int tempMax = n * curMax;
            curMax = max(max(n * curMax, n * curMin), n);
            curMin = min(min(tempMax, n * curMin), n);
            res = max(res, curMax);
        }

        return res;
    }
};

// Same as Solution2 but initialization and loop is different.
class Solution3 {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int curMin = nums[0];
        int curMax = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];

            int tempMax = n * curMax;
            curMax = max(max(n * curMax, n * curMin), n);
            curMin = min(min(tempMax, n * curMin), n);
            res = max(res, curMax);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {2,3,-2,4};
    cout << Solution1().maxProduct(nums) << endl;
    cout << Solution2().maxProduct(nums) << endl;
    cout << Solution3().maxProduct(nums) << endl;
}