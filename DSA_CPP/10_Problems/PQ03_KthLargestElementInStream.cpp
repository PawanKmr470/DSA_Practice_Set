#include <iostream>
#include <queue>
using namespace std;

// Checkout -
//      Top K frequent elements.
//      Kth largest elements in an array.
//      Kth largest elements in an stream.
//      k-way merge

// REF : https://leetcode.com/problems/kth-largest-element-in-a-stream/
// NOTES :
//      Same logice like PQ02_KthLargestElementInAnArray
//      Push nums element into Min Heap of len k. Pop elements exceeding k.
//      In Add method, add element into Min Heap and return top element AND
//      if k is exceeding then pop the element from Min Heap.

// T: O(n*logk)
// S: O(k)

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int &i : nums) {
            minHeap.push(i);

            if (minHeap.size() > k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k)
            minHeap.pop();
        
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */