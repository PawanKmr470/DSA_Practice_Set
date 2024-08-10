# REF : https://leetcode.com/problems/kth-largest-element-in-an-array/
# NOTES :
#       Normal sorting : O(nlogn)
#       maxHeap : O(n + klogn), n for heapify and klogn for popping k elements
#       This solution is Quick Select sorting. Avg case O(n) AND Worst case O(n^2)

class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        return


