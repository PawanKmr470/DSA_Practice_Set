#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/climbing-stairs/description/
// NOTES :
//      1. Recursion + memo
//          step 1 : Problem at first level -> either jump 1 step Or jump 2 step
//          step 2 : If jumped 1 step then again step 1
//          step 3 : If jumped 2 steps then again step 1

/*
    Climbing stairs, either 1 or 2 steps, distinct ways to reach top
    Ex. n = 2 -> 2 (1 + 1, 2), n = 3 -> 3 (1 + 1 + 1, 1 + 2, 2 + 1)

    Recursion w/ memoization -> DP, why DP? Optimal substructure
    Recurrence relation: dp[i] = dp[i - 1] + dp[i - 2]
    Reach ith step in 2 ways: 1) 1 step from i-1, 2) 2 steps from i-2

    Time: O(n)
    Space: O(1)
*/

/*
Basic recursion method
T - O(2^n)
S - O(2^n)
*/
class Solution1 {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Stepwise solution
class Solution1a {
public:
    int climbStairs(int n) {

        // Base condition OR Terminating condition
        if (n <= 2) {
            return n;
        }

        // Choice diagram
        int singleJump = climbStairs(n - 1);
        int doubleJump = climbStairs(n - 2);

        // Return value
        return singleJump + doubleJump;
    }
};

/*
Recursion method with Memoization method
T - O(n)
S - O(n)
*/
class Solution2 {
public:
    int climbStairs(int n) {
        vector<int> vec (n, -1);
        int result = stairs(n, vec);
        return result;
    }

    int stairs(int n, vector<int> &vec) {
        if (n <= 2) {
            return n;
        }
        if (vec[n - 1] != -1) {
            return vec[n - 1];
        }
        vec[n - 1] = stairs(n - 1, vec) + stairs(n - 2, vec);
        return vec[n - 1];
    }
};

/*
Tabulation Method
T - O(n)
S - O(constant)
*/
class Solution3 {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int x = 1;
        int y = 2;
        int temp;
        for (int i = 3; i <= n; i++) {
            temp = y;
            // new y is the sum of prev x and y
            y = y + x;
            // new x is the prev y
            x = temp;
        }
        return y;
    }
};

int main() {
    int result;
    Solution1 s1;
    result = s1.climbStairs(4);
    cout << "No of ways : " << result << endl;

    Solution2 s2;
    result = s2.climbStairs(4);
    cout << "No of ways : " << result << endl;

    Solution3 s3;
    result = s3.climbStairs(4);
    cout << "No of ways : " << result << endl;

    return 0;
}