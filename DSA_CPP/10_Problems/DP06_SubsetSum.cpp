#include <iostream>
#include <vector>
using namespace std;

// REF : https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
// NOTES :
//      set[] = {3, 34, 4, 12, 5, 2}, sum = 9
//      Answer : True (There is a subset (4, 5) with sum 9.)
//      Recursion, Memoization and Tabulation

// T: O(2^n)
// S: O(n) stack lenght
class Solution {
public:
    bool subsetSum(vector<int> &set, int sum) {
        return __subsetSum(set, sum, set.size());
    }

    bool __subsetSum(vector<int> &set, int sum, int n) {
        if (sum == 0) return true;
        if (n == 0 && sum > 0) return false;

        if (set[n-1] <= sum) {      // This if condition means If the number is > sum then we definitely ignore it
            return __subsetSum(set, sum - set[n-1], n-1) ||
                    __subsetSum(set, sum, n-1);
        }
        else {
            return __subsetSum(set, sum, n-1);
        }
    }

};

// T: O(n*sum)
// S: O(n*sum) including aux space
// With memoization
class Solution2 {
public:
    bool subsetSum(vector<int> &set, int sum) {
        // vector<vector<int>> memo (set.size(), vector<int> (sum + 1, -1)); also would have worked
        // becuase rows required are from 0 to n-1 but sum is going from 0 to sum hence sum+1 is ok
        vector<vector<int>> memo (set.size() + 1, vector<int> (sum + 1, -1));
        return __subsetSum(set, sum, set.size(), memo);
    }

    bool __subsetSum(vector<int> &set, int sum, int n, vector<vector<int>> &memo) {
        if (sum == 0) return true;
        if (n == 0 && sum > 0) return false;

        if (memo[n-1][sum] != -1)
            return memo[n-1][sum];

        if (set[n-1] <= sum) {
            memo[n-1][sum] = __subsetSum(set, sum - set[n-1], n-1, memo) ||
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
// With memoization but private memo member
class Solution3 {
private:
    vector<vector<int>> memo;
public:
    bool subsetSum(vector<int> &set, int sum) {
        memo.resize(set.size() + 1, vector<int> (sum + 1, -1));
        return __subsetSum(set, sum, set.size());
    }

    bool __subsetSum(vector<int> &set, int sum, int n) {
        if (sum == 0) return true;
        if (n == 0 && sum > 0) return false;

        if (memo[n-1][sum] != -1)
            return memo[n-1][sum];

        if (set[n-1] <= sum) {
            memo[n-1][sum] = __subsetSum(set, sum - set[n-1], n-1) ||
                                __subsetSum(set, sum, n-1);
            return memo[n-1][sum];
        }
        else {
            memo[n-1][sum] = __subsetSum(set, sum, n-1);
            return memo[n-1][sum];
        }
    }

};

// T: O(n*sum)
// S: O(n*sum) including aux space
// Tabulation method
class Solution4 {
public:
    bool subsetSum(vector<int> &set, int sum) {
        int M = set.size() + 1;
        int N = sum + 1;

        // First col is all true and first row 1 to n is false
        vector<vector<bool>> dp (M, vector<bool> (N, false));
        for (int i = 0; i < M; i++) {
            dp[i][0] = true;            // because by picking up empty subset/not picking any element will result sum 0
        }
        for (int j = 1; j < N; j++) {
            dp[0][j] = false;           // If subset is empty then sum be anything, result is false
        }

        for (int row = 1; row < M; row++) {
            for (int col = 1; col < N; col++) {
                
                if (set[row - 1] <= col) {
                    dp[row][col] = dp[row - 1][col] || dp [row - 1][col - set[row - 1]];
                }
                else {
                    dp[row][col] = dp[row - 1][col];
                }
            }
        }

        return dp[M - 1][N - 1];
        // return dp[set.size()][sum];
        // return dp[row-1][col-1];         // because row is now row == M in last iteration of row loop. same for col
    }

};

int main() {

    vector<int> set = { 3, 34, 4, 12, 5, 2 };
    int sum = 7;
    cout << "Solution   : " << Solution().subsetSum(set, sum) << endl;
    cout << "Solution2  : " << Solution2().subsetSum(set, sum) << endl;
    cout << "Solution3  : " << Solution3().subsetSum(set, sum) << endl;
    cout << "Solution4  : " << Solution4().subsetSum(set, sum) << endl;
    return 0;
}