#include <iostream>
#include <queue>
using namespace std;

// REF : https://leetcode.com/problems/last-stone-weight/
// NOTES :
//      Max Heap

// T: O(nlogn)
// S: O(n)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (auto &i : stones)
            maxHeap.push(i);
        
        while (maxHeap.size() > 1) {
            int stoneX = maxHeap.top(); maxHeap.pop();
            int stoneY = maxHeap.top(); maxHeap.pop();
            if (stoneY > stoneX)
                maxHeap.push(stoneY - stoneX);
            if (stoneY < stoneX)
                maxHeap.push(stoneX - stoneY);
        }
        if (maxHeap.size() == 1)
            return maxHeap.top();
        else
            return 0;
    }
};