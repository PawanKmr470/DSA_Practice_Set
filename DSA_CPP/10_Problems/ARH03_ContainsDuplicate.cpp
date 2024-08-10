// REF : https://leetcode.com/problems/contains-duplicate/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int i = 0; i < nums.size(); i++) {
            if ( hashset.find(nums[i]) != hashset.end() )
                return true;
            hashset.insert(nums[i]);
        }
        return false;
    }
};


int main() {
    vector<int> nums = {1,2,3,1};
    cout << Solution().containsDuplicate(nums) << endl;
    return 0;
}