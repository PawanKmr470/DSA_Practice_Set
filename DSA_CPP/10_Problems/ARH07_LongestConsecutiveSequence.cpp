// REF : https://leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> nset;     // basic way to initialize set with vector<int>
        // for (auto &i : nums) {
        //     nset.insert(i);
        // }
        unordered_set<int> nset(nums.begin(), nums.end());
        int ans_longest = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nset.find(nums[i] - 1) == nset.end()) {
                int length = 0;
                while (nset.find(nums[i] + length) != nset.end()) {
                    length += 1;
                }
                ans_longest = max(ans_longest, length);
            }
        }
        return ans_longest;
    }
};


int main() {
    vector<int> nums = {100,4,200,1,3,2};
    int ans = Solution().longestConsecutive(nums);
    cout << "output : " << ans << endl;
    return 0;
}