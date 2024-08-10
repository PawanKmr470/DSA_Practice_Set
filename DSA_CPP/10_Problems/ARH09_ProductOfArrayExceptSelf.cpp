// REF : https://leetcode.com/problems/product-of-array-except-self/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prefix;
            prefix = prefix * nums[i];
        }

        int postfix = 1;
        for (int i = nums.size() - 1; i > -1; i-- ) {
            res[i] = res[i] * postfix;
            postfix = postfix * nums[i];
        }

        return res;
    }
};


int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> ans = Solution().productExceptSelf(nums);
    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}