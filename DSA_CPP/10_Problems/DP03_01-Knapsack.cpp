#include <iostream>
#include <vector>
using namespace std;

/*
weight [] - [5, 4, 6, 3]
value  [] - [10, 40, 30, 50]
Capacity w = 10

Put weights in knapsack in such a way that it has max value.
Ans - 90

Similar Problems :
->Subset sum
->Equal sum partition
->Count of subsets sum with a given sum
->Minimum subset sum difference
->Count the number of subset with a given difference
->Target sum
*/

/*
Basic recursion method
T - O(2^n)
S - O(1) no extra DS is required. O(n) with recursion stack lenght
*/
class Solution1
{
public:
    int knapsack(int weight[], int value[], int W, int n) {
        if (n == 0 || W == 0) return 0;
        if (weight[n - 1] <= W) {
            return max(value[n - 1] + knapsack(weight, value, W - weight[n - 1], n - 1),
                        knapsack(weight, value, W, n - 1));
        }
        else {
            return knapsack(weight, value, W, n - 1);
        }
    }
};

/*
Recursion with memoization
T - O(n*W)
S - O(n*W) becuase of additional DS.
*/
int dp1[5][11]; // global is initialized with 0, it works or Better initialize with -1
class Solution2
{
public:
    int knapsack(int weight[], int value[], int W, int n) {
        if (n == 0 || W == 0) return 0;

        // Memoization
        if (dp1[n][W] != 0) {
            return dp1[n][W];
        }

        if (weight[n - 1] <= W) {
            dp1[n][W] = max(value[n - 1] + knapsack(weight, value, W - weight[n - 1], n - 1),
                                knapsack(weight, value, W, n - 1));
            return dp1[n][W];
        }
        else {
            dp1[n][W] = knapsack(weight, value, W, n - 1);
            return dp1[n][W];
        }
    }
};


/*
Tabulation method
T - O(n*W)
S - O(n*W)
*/
class Solution3
{
public:
    int dp2[5][11]; // [n+1][W+1] because it will go from 0,0 to n, W
                    // And we will get result at dp2[4][10].
                    // Each cell donotes max profit till there.
    int knapsack(int weight[], int value[], int W, int n) {
        int row, col;
        for (row = 0; row <= n; row++) {
            for (col = 0; col <= W; col++) {
                if (row == 0 || col == 0) {
                    dp2[row][col] = 0;
                }
            }
        }

        for (row = 1; row <= n; row++) {
            for (col = 1; col <= W; col++) {
                // initialization can be done here also.
                // if (row == 0 || col == 0) dp2[row][col] = 0;
                if (weight[row-1] <= col) {
                    dp2[row][col] = max(value[row-1] + dp2[row-1][col-weight[row-1]],
                                        dp2[row-1][col]);
                }
                else {
                    dp2[row][col] = dp2[row-1][col];
                }
            }
        }
        return dp2[n][W];
    }
};


// using vector
class Solution4
{
public:
    int knapsack(vector<int>& weight, vector<int>& value, int W, int n, vector<vector<int>>& dp2) {
        int row, col;
        for (row = 0; row < dp2.size(); row++) {
            for (col = 0; col < dp2[row].size(); col++) {
                if (row == 0 || col == 0) dp2[row][col] = 0;
            }
        }

        for (row = 1; row <= n; row++) {
            for (col = 1; col <= W; col++) {
                if (weight[row-1] <= col) {
                    dp2[row][col] = max(value[row-1] + dp2[row-1][col-weight[row-1]] ,
                                        dp2[row-1][col]);
                }
                else {
                    dp2[row][col] = dp2[row-1][col];
                }
            }
        }
        return dp2[n][W];
    }
};

// using dynamic memory
class Solution5
{
private:
    vector<vector<int>> *dp2;
public:
    int knapsack(vector<int>& weight, vector<int>& value, int W, int n) {
        dp2 = new vector<vector<int>>(n+1, vector<int>(W+1, -1));
        int row, col;
        for (row = 0; row <= n; row++) {
            for (col = 0; col <= W; col++) {
                if (row == 0 || col == 0) (*dp2)[row][col] = 0;
            }
        }

        for (row = 1; row <= n; row++) {
            for (col = 1; col <= W; col++) {
                if (weight[row-1] <= col) {
                    (*dp2)[row][col] = max(value[row-1] + (*dp2)[row-1][col-weight[row-1]] ,
                                        (*dp2)[row-1][col]);
                }
                else {
                    (*dp2)[row][col] = (*dp2)[row-1][col];
                }
            }
        }
        return (*dp2)[n][W];
    }
};

/*
using 1D array
T - O(n*W)
S - O(W)    Space complexity is optimized. NOTE - w loop is in decrement manner why bcz filling it right to 
            to left will not overwrite previous values which represents prev row array.
*/

class Solution6
{
private:
    vector<int> *dp;
public:
    int knapsack(vector<int>& weight, vector<int>& value, int W, int n) {
        dp = new vector<int> (W+1, 0);
        for (int i = 1; i <= n; i++) {
            for (int w = W; w >= 0; w--) {
                if (weight[i-1] <= w) {
                    (*dp)[w] = max(value[i-1] + (*dp)[w-weight[i-1]], (*dp)[w]);
                }
            }
        }
        return (*dp)[W];
    }
};

int main() {
    int weight[] = { 5, 4, 6, 3 };
    int value[] = { 10, 40, 30, 50 };
    int W = 10;
    int n = sizeof(value) / sizeof(value[0]);

    // using arrays
    cout << "Solution 1 : ";
    Solution1 s1;
    cout << s1.knapsack(weight, value, W, n) << endl;

    cout << "Solution 2 : ";
    Solution2 s2;
    cout << s2.knapsack(weight, value, W, n) << endl;

    cout << "Solution 3 : ";
    Solution3 s3;
    cout << s3.knapsack(weight, value, W, n) << endl;


    vector<int> wt = { 5, 4, 6, 3 };
    vector<int> val = { 10, 40, 30, 50 };
    W = 10;
    n = wt.size();

    // using vectors
    cout << "Solution 4 : ";
    vector<vector<int>> dp2(n+1, vector<int> (W+1, -1));
    Solution4 s4;
    cout << s4.knapsack(wt, val, W, n, dp2) << endl;

    // using dynamic memory
    cout << "Solution 5 : ";
    Solution5 s5;
    cout << s5.knapsack(wt, val, W, n) << endl;

    // using 1D array
    cout << "Solution 6 : ";
    Solution6 s6;
    cout << s5.knapsack(wt, val, W, n) << endl;

    return 0;
}
