/*
weight [] - [5, 4, 6, 3] - These are bounded. and being fractional here means
                            we can take fraction of any item to fill the remaining space in knapsack.
value  [] - [30, 10, 50, 40]
Capacity w = 10

Ans - 96

How items should be picked up ?
Sort by profit to weight ratio. keep filling sack up items from higher ratio to lower ratio items.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The Complexity here is the Complexity of sort() funtion.
// T - O(nlog n)
// S - O(log n)-Avg case, O(n)-Worst case
class Solution1
{
public:
    static bool comp(vector<int>& vec1, vector<int>& vec2) {
        return vec1[1]/vec1[0] > vec2[1]/vec2[0];
    }
    int knapsack(vector<vector<int>>& vec, int W, int n) {
        sort(vec.begin(), vec.end(), comp);
        /* for (auto i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].size(); j++) {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        } */
        int curWeight = 0;
        double totalValue = 0;

        for (int i = 0; i < vec.size(); i++) {
            if (curWeight + vec[i][0] <= W) {
                curWeight += vec[i][0];
                totalValue += vec[i][1];
            }
            else {
                int remain = W - curWeight;
                if ((remain) > 0) {
                    totalValue += ( (double)vec[i][1]/(double)vec[i][0] * remain);
                    break;
                }
            }
        }
        return totalValue;
    }
};

int main() {
    vector<vector<int>> vec = {{5,30}, {4,10}, {6,50}, {3,40}};
    int W = 10;
    int n = vec.size();
    Solution1 s1;
    cout << s1.knapsack(vec, W, n) << endl;
    return 0;
}
