#include <iostream>
#include <vector>
using namespace std;

// Partition with given difference (Synonym)
// REF : https://www.geeksforgeeks.org/count-of-subsets-with-given-difference/
//       https://leetcode.com/discuss/interview-question/1271034/count-no-of-subsets-with-given-difference-dp
// NOTES :
//      S1 + S2  is the total sum array nums = sum
//      S1 – S2 is the given diff            = diff & solving these two equations
//      S1 = (sum + diff) / 2
//      Now the question becomes count of subset sum with given sum S1.

// T: O(2^n)
// S: O(n) stack lenght
class Solution {
public:
    int partitionWithGivenDiff(vector<int> &set, int diff) {
        int sum = 0;
        for (auto &i : set)
            sum += i;
        int s1 = (sum + diff)/2;
        return __subsetSum(set, s1, set.size());
    }

    int __subsetSum(vector<int> &set, int sum, int n) {
        if (sum == 0) return 1;
        if (n == 0 && sum > 0) return 0;

        if (set[n-1] <= sum) {
            return __subsetSum(set, sum - set[n-1], n-1) +
                    __subsetSum(set, sum, n-1);
        }
        else {
            return __subsetSum(set, sum, n-1);
        }
    }
};

// T: O(n*sum)
// S: O(n*sum) including aux space
// Tabulation method
// class Solution2 {
// public:
//     int partitionWithGivenDiff(vector<int> &set, int diff) {
// };

int main() {
    vector<int> set = {1, 2, 3, 1, 2};
    int diff = 3;
    cout << "Solution : " << Solution().partitionWithGivenDiff(set, diff) << endl;
    return 0;
}