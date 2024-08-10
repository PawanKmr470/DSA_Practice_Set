#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  REF : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//  NOTES :
//          Given array prices, return max profit w/ 1 buy & 1 sell
//          Ex. prices = [7,1,5,3,6,4] -> 5 (buy at $1, sell at $6)
//          For each, get diff b/w ith & min value. Keep storing max profit.

//  O(T) : O(n)
//  O(S) : O(1)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int max_profit = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int cur_profit = prices[r] - prices[l];
                max_profit = max(max_profit, cur_profit);
            }
            else {
                l = r;
            }
            r++;
        }
        return max_profit;
    }
};


int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}