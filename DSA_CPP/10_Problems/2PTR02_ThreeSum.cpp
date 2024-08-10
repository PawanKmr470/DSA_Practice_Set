// REF : https://leetcode.com/problems/3sum/description/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // sort(v.begin(), v.end(), greater<int>());    // For decreasing order

        for (int i = 0; i < nums.size(); i++) {
            if ((i > 0) && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int threeSum = nums[i] + nums[l] + nums[r];
                if (threeSum > 0)
                    r--;
                else if (threeSum < 0)
                    l++;
                else {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    l++;
                    while ((nums[l] == nums[l - 1]) && (l < r)) {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};


int main() {
    vector<vector<int>> res;
    vector<int> nums = {-1,0,1,2,-1,-4};
    res = Solution().threeSum(nums);

    for (auto &i : res) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}