// REF : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r) {
            int curSum = numbers[l] + numbers[r];
            if (curSum < target) {
                l++;
            }
            else if (curSum > target) {
                r--;
            }
            else {
                res.push_back(l + 1);
                res.push_back(r + 1);
                return res;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}