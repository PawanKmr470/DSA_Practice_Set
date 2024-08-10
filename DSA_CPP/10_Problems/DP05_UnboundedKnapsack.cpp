/*
weight [] - [5, 4, 6, 3] - unlimited weights of given array values.
value  [] - [10, 40, 30, 50]
Capacity w = 10

Put weights in knapsack in such a way that it has max value.
Ans - 150 from (3 + 3 + 3)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution1
{
public:
    int knapsack(int weight[], int value[], int W, int n) {
        if (n == 0 || W == 0) return 0;
        if (weight[n - 1] <= W) {

            /* return max(value[n - 1] + knapsack(weight, value, W - weight[n - 1], n - 1),
                        knapsack(weight, value, W, n - 1));  // n -1 => n bcz it can be reconsidered.*/

            return max(value[n - 1] + knapsack(weight, value, W - weight[n - 1], n),
                        knapsack(weight, value, W, n - 1));
        }
        else {
            return knapsack(weight, value, W, n - 1);
        }
    }
};

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
                if (weight[row-1] <= col) {
                    /* dp2[row][col] = max(value[row-1] + dp2[row-1][col-weight[row-1]],
                                        dp2[row-1][col]); */
                    dp2[row][col] = max(value[row-1] + dp2[row][col-weight[row-1]],
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

class Solution6
{
private:
    vector<int> *dp;
public:
    int knapsack(vector<int>& weight, vector<int>& value, int W, int n) {
        dp = new vector<int> (W+1, 0);
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (weight[i-1] <= w) {
                    (*dp)[w] = max(value[i-1] + (*dp)[w-weight[i-1]], (*dp)[w]);
                }
            }
            /* for (int w = W; w >= 0; w--) {
                if (weight[i-1] <= w) {
                    (*dp)[w] = max(value[i-1] + (*dp)[w-weight[i-1]], (*dp)[w]);
                }
            } */
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
    Solution1 s1;
    cout << s1.knapsack(weight, value, W, n) << endl;

    Solution3 s3;
    cout << s3.knapsack(weight, value, W, n) << endl;

    vector<int> wt = { 5, 4, 6, 3 };
    vector<int> val = { 10, 40, 30, 50 };
    W = 10;
    n = wt.size();
    Solution6 s6;
    cout << s6.knapsack(wt, val, W, n) << endl;
    return 0;
}
