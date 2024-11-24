#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int> visited;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        dfs(cur, nums);
        return result;
    }

    void dfs(vector<int> &cur, vector<int> &nums) {
        if (cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }

        for (int j = 0; j < nums.size(); j++) {

            if (visited.find(nums[j]) == visited.end()) {
                cur.push_back(nums[j]);
                visited.insert(nums[j]);
                dfs(cur, nums);
                cur.pop_back();
                visited.erase(nums[j]);
            }
        }
    }
};

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = Solution().permute(nums);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
