# REF : https://leetcode.com/problems/find-median-from-data-stream/
# NOTES :
#       1-way -> add incoming number into list in sorted fasion but shifting is req
#       2-way -> add number in insertion sort fashion but shifting is still involved
#       3-way -> Two heaps - median's smaller value from maxHeap(left)
#                            and larger value from minHeap(right)

# T: addNum - O(logn) & findMedian - O(1)
# S: O(n)

import heapq

class MedianFinder:

    def __init__(self):
        self.maxHeap = []  # left side maxHeap
        self.minHeap = []  # right side minHeap

    def addNum(self, num: int) -> None:
        heapq.heappush(self.maxHeap, -1 * num)

        if self.maxHeap and self.minHeap and (-1 * self.maxHeap[0] > self.minHeap[0]):
            val = -1 * heapq.heappop(self.maxHeap)
            heapq.heappush(self.minHeap, val)

        if len(self.maxHeap) > len(self.minHeap) + 1:
            val = -1 * heapq.heappop(self.maxHeap)
            heapq.heappush(self.minHeap, val)

        if len(self.maxHeap) + 1 < len(self.minHeap):
            val = heapq.heappop(self.minHeap)
            heapq.heappush(self.maxHeap, -1 * val)

    def findMedian(self) -> float:

        if len(self.maxHeap) > len(self.minHeap):
            return self.maxHeap[0] * -1

        if len(self.maxHeap) < len(self.minHeap):
            return self.minHeap[0]

        return (-1 * self.maxHeap[0] + self.minHeap[0]) / 2

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()