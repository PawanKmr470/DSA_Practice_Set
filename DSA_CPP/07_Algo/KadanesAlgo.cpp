#include <iostream>
#include <vector>
using namespace std;

// REF : https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// NOTES :
//      Keep two variables curMax & totalMax
//      keep adding elements into curMax
//      check if curMax > totalMax then update totalMax
//      And if curMax is < 0 then make curMax = 0 as we don't want totalMax to decrease

// O(T) : O(n)
// O(S) : O(1)

class Solution {
public:
    int maxSubArraySum(vector<int> &nums) {
        int totalMax = INT_MIN;
        int curMax = 0;

        for (int i = 0; i < nums.size(); i++) {
            curMax = curMax + nums[i];

            if (curMax > totalMax)
                totalMax = curMax;

            if (curMax < 0)
                curMax = 0;
        }

        return totalMax;
    }

    int printMaxSubArraySum(vector<int> &nums) {
        int totalMax = INT_MIN;
        int curMax = 0;
        int start = 0;
        int end = 0;

        for (int i = 0; i < nums.size(); i++) {
            curMax = curMax + nums[i];

            if (curMax > totalMax) {
                totalMax = curMax;
                end = i;
            }

            if (curMax < 0) {
                curMax = 0;
                start = i + 1;
            }
        }

        cout << "From " << start << " to " << end << endl;

        return totalMax;
    }
};

int main() {

    vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << Solution().maxSubArraySum(nums) << endl;
    cout << Solution().printMaxSubArraySum(nums) << endl;

    return 0;
}