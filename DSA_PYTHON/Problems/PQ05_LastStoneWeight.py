# REF : https://leetcode.com/problems/last-stone-weight/
# NOTES :
#       maxHeap application

# T: O(n*logn), logn is of heap
# S: O(n) due to heap

import heapq

class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
        maxHeap = [-s for s in stones]
        heapq.heapify(maxHeap)
        while len(maxHeap) > 1:
            first = abs(heapq.heappop(maxHeap))
            second = abs(heapq.heappop(maxHeap))
            if first > second:
                heapq.heappush(maxHeap, -(first - second))

        return abs(maxHeap[0]) if len(maxHeap) == 1 else 0


def main():
    print("output : {}".format(Solution().lastStoneWeight([2,7,4,1,8,1])))

if __name__ == "__main__":
    main()