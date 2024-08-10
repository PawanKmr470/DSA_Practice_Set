#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// REF : https://leetcode.com/problems/first-missing-positive/
// NOTES :
//      Hash set
//      Start from 1 till n+1 and search in hash set. If missing that's the answer.

// T: O(n)
// S: O(n)
class Solution {
public:
    int missingNum(vector<int> nums) {
        int n = nums.size();
        unordered_set<int> hashSet(nums.begin(), nums.end());

        int i = 1;
        for (; i <= n + 1; i++) {
            if (hashSet.find(i) == hashSet.end())
                break;
        }

        return i;
    }
};

int main() {

    vector<int> nums = {1, 4, 2, -1, 6, 5};
    cout << Solution().missingNum(nums) << endl;

    vector<int> nums2 = {1, 2, 3, 4};
    cout << Solution().missingNum(nums2) << endl;

    vector<int> nums3 = {-1, -3};
    cout << Solution().missingNum(nums3) << endl;

    return 0;
}