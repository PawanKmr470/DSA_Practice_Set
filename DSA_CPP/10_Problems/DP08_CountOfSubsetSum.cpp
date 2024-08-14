#include <iostream>
#include <vector>
using namespace std;

// REF : https://www.youtube.com/watch?v=MqYLmIzl8sQ
// NOTES :
//      Need to count the subset sum arrays.
//      Base condition would be -
//          if sum == 0, then return 1
//          if index == 0 and sum > 0 then return 0 --> means this path doesn't give
//                                                      any subset whose sum is zero.
//      And || --> + as it requires the count

// T: O(2^n)
// S: O(n) stack lenght
class Solution {
public:
    int countSubsetSum(vector<int> &set, int sum) {
        return __subsetSum(set, sum, set.size());
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


// Recursion with memoization
// T: O(n*sum)
// S: O(n*sum) including aux space
class Solution2 {
public:
    int countSubsetSum(vector<int> &set, int sum) {
        vector<vector<int>> memo(set.size()+1, vector<int> (sum+1, -1));
        return __subsetSum(set, sum, set.size(), memo);
    }

    int __subsetSum(vector<int> &set, int sum, int n, vector<vector<int>>& memo) {
        if (sum == 0) return 1;
        // if (n == 0 && sum > 0) return 0;
        if (n == 0) {
            if (sum == 0)
                return 1;
            else
                return 0;
        }

        if (memo[n-1][sum] != -1)
            return memo[n-1][sum];

        if (set[n-1] <= sum) {
            memo[n-1][sum] = __subsetSum(set, sum - set[n-1], n-1, memo) +
                            __subsetSum(set, sum, n-1, memo);
            return memo[n-1][sum];
        }
        else {
            memo[n-1][sum] = __subsetSum(set, sum, n-1, memo);
            return memo[n-1][sum];
        }
    }

};


// T: O(n*sum)
// S: O(n*sum) including aux space
// Tabulation method
class Solution3 {
public:
    int countSubsetSum(vector<int> &set, int sum) {
        int M = set.size() + 1;
        int N = sum + 1;

        vector<vector<int>> dp (M, vector<int> (N, 0));

        // First col is all 1's means pick any size of array, if sum 0 is to be achieved
        // it can be done with including empty subset so subset count is 1.
        for (int i = 0; i < M; i++) {
            dp[i][0] = 1;
        }

        // And first row 1 to n is 0 because if array is empty then subset sum count is 0
        for (int j = 1; j < N; j++) {
            dp[0][j] = 0;
        }

        for (int row = 1; row < M; row++) {
            for (int col = 1; col < N; col++) {
                
                if (set[row - 1] <= col) {
                    dp[row][col] = dp[row - 1][col] + dp [row - 1][col - set[row - 1]];
                }
                else {
                    dp[row][col] = dp[row - 1][col];
                }
            }
        }

        return dp[M - 1][N - 1];
    }

};

int main() {
    // vector<int> set = {1, 2, 1};
    vector<int> set = {2, 3, 5, 6, 8, 10};
    // int sum = 3;
    int sum = 10;
    cout << "Solution : " << Solution().countSubsetSum(set, sum) << endl;
    cout << "Solution2 : " << Solution2().countSubsetSum(set, sum) << endl;
    cout << "Solution3 : " << Solution3().countSubsetSum(set, sum) << endl;
    return 0;
}