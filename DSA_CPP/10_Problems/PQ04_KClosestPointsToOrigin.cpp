#include <iostream>
#include <queue>
using namespace std;

// REF : https://leetcode.com/problems/k-closest-points-to-origin/
// NOTES :
//      Min Heap would require pushing all the elements and popping top k elements.
//      Max Heap of size k & popping top elements if size reaches k.
//      remaining elements in the Max Heap will be answer.

typedef pair<int, pair<int, int>> mypair;

// T: O(n + klogn) n -> pushing all elements & k times popping logn
// S: O(n)
// Using Min Heap
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<mypair, vector<mypair>, greater<mypair>> minHeap;
        for (auto &i : points) {
            int dist = i[0]*i[0] + i[1]*i[1];
            minHeap.push({dist, {i[0], i[1]}});
        }

        vector<vector<int>> result;
        while (k > 0) {
            mypair element = minHeap.top();
            minHeap.pop();
            result.push_back({element.second.first, element.second.second});
            k--;
        }
        return result;
    }
};

// T: O(nlogk)
// S: O(k)      Max Heap will be maintaining k elements only
// Using Max Heap
class Solution1 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<mypair> maxHeap;
        for (auto &i : points) {
            int dist = i[0]*i[0] + i[1]*i[1];
            maxHeap.push({dist, {i[0], i[1]}});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            mypair element = maxHeap.top();
            maxHeap.pop();
            result.push_back({element.second.first, element.second.second});
        }
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{3,2}, {7,7}, {-9,9}, {4,-6}, {-3,-6}};
    int k = 4;
    vector<vector<int>> result;

    result = Solution1().kClosest(points, k);
    for (auto &i : result) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}