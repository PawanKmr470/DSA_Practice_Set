# REF : https://leetcode.com/problems/kth-largest-element-in-a-stream/
# NOTES :
#       Kth Largest element using minHeap

# T: O(logn) of add, O( (n-k)*logn ) of constructor ~ O(nlogn)
# S: O(n) due to minHeap

import heapq

class KthLargest:

    def __init__(self, k: int, nums: list[int]):
        self.k = k
        self.minHeap = nums
        heapq.heapify(self.minHeap)
        while len(self.minHeap) > k:
            heapq.heappop(self.minHeap)

    def add(self, val: int) -> int:
        heapq.heappush(self.minHeap, val)
        if len(self.minHeap) > self.k:
            heapq.heappop(self.minHeap)
        return self.minHeap[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
def main():
    print("output : {}".format(KthLargest(3, [4, 5, 8, 2]).add(3)))

if __name__ == "__main__":
    main()
