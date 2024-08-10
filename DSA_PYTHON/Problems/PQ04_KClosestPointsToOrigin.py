# REF : https://leetcode.com/problems/k-closest-points-to-origin/
# NOTES:
#       Two ways to do -
#       1. create maxHeap of size k and after popping n-k elements,
#          last k remaining elements in the maxHeap will be answers. O(k + (n-k)logk)
#       2. create minHeap with all elements from the list and keep popping till k. That'll be ans.
#          O(n + klogn), n -> heapify AND klogn for popping k times. BETTER
#       Heap elements will be (x*x + y*y, x, y). sorting will be based on Euclidean distance.

import heapq

class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:

        # T: O(n + klogn), n -> for heapify AND klogn for popping k elements from minHeap
        # S: O(n)
        minHeap = []
        for x, y in points:
            dist = x*x + y*y                # x**2 + y**2
            minHeap.append([dist, x, y])

        heapq.heapify(minHeap)
        # pop k elements
        result = []
        while k > 0:
            dist, x, y = heapq.heappop(minHeap)
            result.append([x, y])
            k -= 1

        return result


def main():
    points = [[3,3],[5,-1],[-2,4]]
    k = 2
    print("output : {}".format(Solution().kClosest(points, k)))

if __name__ == "__main__":
    main()