# REF : https://leetcode.com/problems/task-scheduler/
# NOTES:
#       maxHeap + Queue
#       python has only Min Heap. For Max Heap can be implemented using -ve numbers.

# T: O(n * c * log 26) ~ O(n)
# S: O(1), bcz Queue and maxHeap size can go upto 26 distinct elements

import heapq
from collections import Counter, deque

class Solution:
    def leastInterval(self, tasks: list[str], n: int) -> int:

        freq_dict = Counter(tasks)
        maxHeap = [ -i for i in freq_dict.values()]
        heapq.heapify(maxHeap)
        q = deque()

        time = 0
        while q or maxHeap:
            time += 1                                   # Increase timeline by 1 step by step
            if maxHeap:
                cnt = heapq.heappop(maxHeap)            # pop max freq element from heap
                cnt += 1                                # and reduce freq by 1 and

                if cnt:                                 # if count is non-zero then add it into queue
                    q.append((cnt, time + n))           # if count is 0, means that element has been consumed
                                                        # to its all freqency

            if q and q[0][1] == time:                   # when element's next occurance time matches with time
                new_freq = q.popleft()[0]               # then pop it from queue and push into heap
                heapq.heappush(maxHeap, new_freq)

        return time



def main():
    tasks = ["A","A","A","B","B","B"]
    n = 2
    print("output : {}".format(Solution().leastInterval(tasks, n)))

if __name__ == "__main__":
    main()