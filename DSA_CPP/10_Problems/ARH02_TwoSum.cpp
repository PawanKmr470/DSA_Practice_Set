#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>&, int);
};

// vector<int> Solution::twoSum(vector<int>& nums, int target){
//     vector<int> result;
//     unordered_map<int, int> hash;
//     int i;
//     for (i = 0; i < nums.size(); i++){
//         hash[nums[i]] = i;                   // here hashmap is explicitly filled which is not required
//     }
//     for (i = 0; i < nums.size(); i++){
//         int remainingDigit = target - nums[i];
//         if ((hash.find(remainingDigit) != hash.end() && hash[remainingDigit] != i) ){
//             result.push_back(i);
//             result.push_back(hash[remainingDigit]);
//             return result;
//         }
//     }
//     return result;
// }

vector<int> Solution::twoSum(vector<int>& nums, int target){
    vector<int> result;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++){
        int remainingDigit = target - nums[i];
        if ((hash.find(remainingDigit) != hash.end() && hash[remainingDigit] != i) ){
            result.push_back(i);
            result.push_back(hash[remainingDigit]);
            return result;
        }
        hash[nums[i]] = i;
    }
    return result;
}

int main(){
    vector<int> result;
    Solution s;
    vector<int> v = {3,2,4};
    result = s.twoSum(v, 6);
    cout << "result is : ";
    for (auto &i: result){
        cout << i << " ";
    }
    cout << endl;

    result.clear();
    vector<int> vec = {2,11,7,15};
    result = s.twoSum(vec, 9);
    cout << "result is : ";
    for (auto &i: result){
        cout << i << " ";
    }
    cout << endl;
}