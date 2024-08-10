#include <iostream>
#include <queue>
using namespace std;

// REF : https://leetcode.com/problems/find-median-from-data-stream/
// NOTES :
//      Max Heap for left element + Min Heap for right element
//      start filling maxHeap first (we can pick any but here maxHeap)
//      diff of both heap sizes won't exceed more than 1
//      because if there are odd number of elements then either of heap
//      will be of size + 1.
//      If the new element is going in bigger size heap then we need to
//      balance them.

// T: O(nlogn)
// S: O(n)

class MedianFinder {
private:
    priority_queue<int> maxHeap_left;
    priority_queue<int, vector<int>, greater<int>> minHeap_right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap_left.empty() || num < maxHeap_left.top())
            maxHeap_left.push(num);
        else
            minHeap_right.push(num);

        if (maxHeap_left.size() > minHeap_right.size() + 1) {
            minHeap_right.push(maxHeap_left.top());
            maxHeap_left.pop();
        }
        if (maxHeap_left.size() + 1 < minHeap_right.size()) {
            maxHeap_left.push(minHeap_right.top());
            minHeap_right.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap_left.size() == minHeap_right.size()) {
            if (maxHeap_left.size() == 0) {
                return 0;
            }
            else {
                double mid = (maxHeap_left.top() + minHeap_right.top()) / 2.0;
                return mid;
            }
        }
        else {
            return maxHeap_left.size() > minHeap_right.size() ? maxHeap_left.top() : minHeap_right.top();
        }
    }
};
