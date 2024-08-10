#include <iostream>
#include <queue>
using namespace std;

// 1. Sorting
// 2. Max Heap
// 3. Min Heap
// 4. QuickSelect Sort. Avg T: O(n) Worst T: O(n^2) and S: O(1)
// Checkout -
//      Top K frequent elements.
//      Kth largest elements in an array.
//      Kth largest elements in an stream.
//      k-way merge

// REF : https://leetcode.com/problems/kth-largest-element-in-an-array/description/
//       https://www.youtube.com/watch?v=Lk-QYXyPL3g
// NOTES :
//      1. Brute force way will be sort the array in descending order & return k-1 element.
//          T: O(nlogn) S: O(logn or n) S-> depeding upon sorting algorithm
//              Java sort()   - Quick sort. S: O(logn)
//              C++ sort()    - Intro sort. Hybrid of Quick Sort + Heap Sort + Insertion Sort  S: O(logn)
//              Python sort() - Timsort. S: O(n)
//
//      Build Heap => Insert elements => O(n * logn) AND heapify is different => make_heap() => O(n)
//      In solution, we are using priority_queue, so no heapify method only insert and create.
//      2. Max Heap.
//          Build max heap. Then pop k elements. k * pop (O(logn))
//          T: O(n) + O(klogn)     => O(n+klogn)    using Heap
//          T: O(nlogn) + O(klogn) => O((n+k)logn)  using priority_queue
//      3. Min Heap.
//          Min Heap of size K.
//          Keep filling the elements. If size reaches to k then return top element.
//          Build heap O(k) + push-pop n-k times O((n-k)logk)
//          T: O(k) + O((n-k)logk)     => O(nlogk)    using Heap
//          T: O(klogk) + O((n-k)logk) => O(nlogk)    using priority_queue
//      4. Counting sort
//          https://www.youtube.com/watch?v=4O6fuT9lJeE
//          But the limitation is that elements' range should be limited. Not like {2,5,1,12000}
//          Otherwise space waste will be too much.
//      5. Quick Select Sort
//          T: O(n)& S: O(n) But T: O(n^2) for worst case. Hence won't be best choice.
 
// Using Min Heap
// T: O(n*logk)
// S: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto &i : nums) {
            minHeap.push(i);
            if (minHeap.size() > k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};

// Using Counting Sort
// T: O(n*logk)
// S: O(k)
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = INT_MAX;                         // minValue initilized with max
        int maxValue = INT_MIN;                         // maxValue initilized with min
        
        // Find min & max
        for (int &i : nums) {
            minValue = min(minValue, i);
            maxValue = max(maxValue, i);
        }

        // Create frequency array (num as index & freq as value)
        vector<int> count(maxValue - minValue + 1);
        for (int &i : nums) {
            count[i - minValue]++;
        }

        // For largest, start from end till k and return index.
        int remains = k;
        for (int i = count.size()-1; i >= 0; i--) {
            // Reduce freq
            remains = remains - count[i];
            if (remains <= 0) {
                return i + minValue;
            }
        }

        return -1;
    }
};


int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << Solution().findKthLargest(nums, k) << endl;
    cout << Solution2().findKthLargest(nums, k) << endl;
}