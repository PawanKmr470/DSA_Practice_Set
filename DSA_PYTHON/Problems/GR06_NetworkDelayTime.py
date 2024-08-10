# REF : https://leetcode.com/problems/network-delay-time/
# NOTES :
#       BFS + minHeap = Dijkstra's Algorithm

# T: O(E*logV), logV due to minHeap
# S: O(V)

import heapq
from collections import defaultdict

class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        adjList = defaultdict(list)
        for n1, n2, wt in times:
            adjList[n1].append((n2, wt))

        t = 0
        visit = set()
        minHeap = []
        heapq.heappush(minHeap, (0, k))

        while minHeap:
            w1, n1 = heapq.heappop(minHeap)
            if n1 in visit:                     # does it work without this condition ?
                continue
            visit.add(n1)
            t = max(t, w1)
            for n2, w2 in adjList[n1]:
                if n2 not in visit:
                    heapq.heappush(minHeap, (w2 + w1, n2))

        return t if len(visit) == n else -1


def main():
    times = [[2,1,1],[2,3,1],[3,4,1]]
    n = 4
    k = 2
    print("min time taken : {}".format(Solution().networkDelayTime(times, n, k)))

if __name__ == "__main__":
    main()