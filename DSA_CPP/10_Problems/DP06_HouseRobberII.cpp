#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/house-robber-ii/description/
// NOTES :
//      Same as House Robber I but due to cyclic condition, run 2 times HRI solution -
//      max(0 to n-1, 1 to n)

class Solution4
{
public:
    int robII(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(rob(nums, 0, nums.size()-1),
                    rob(nums, 1, nums.size()));
    }
    int rob(vector<int>& nums, int start, int end) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int one = nums[start];
        int two = max(one, nums[start+1]);
        for (int i=start+2; i<end; i++) {
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
    //vector<int> vec = {1, 2, 3, 1};
    vector<int> vec = {2,3,2};
    Solution4 s4;
    cout << "Solution 4 : ";
    cout << s4.robII(vec) << endl;
    return 0;
}
