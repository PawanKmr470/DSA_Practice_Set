// REF : https://leetcode.com/problems/container-with-most-water/description/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            int area = (r - l) * min(height[r], height[l]);
            res = max(res, area);

            if (height[l] < height[r])
                l++;
            else if (height[l] > height[r])
                r--;
            else
                r--;
        }
        return res;
    }
};


int main() {
    return 0;
}