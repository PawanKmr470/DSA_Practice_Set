# REF : https://leetcode.com/problems/koko-eating-bananas/
# NOTES :
#       we will start checking from k = 1 to k = max(time array given) -> this is brute force
#       with Binary search k can be found between 1 and max value
#       A condition on which BS will work is that k selected value can be either > or < h

# T: O(n * logm)
# S: O(1)

import math

class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        start, end = 1, max(piles)
        res = end

        while start <= end:
            mid = start + (end - start) // 2

            hours = 0
            for p in piles:
                hours += math.ceil(p/mid)

            if hours <= h:                          # <= greater and equal to sign
                res = min(res, mid)
                end = mid - 1
            else:
                start = mid + 1

        return res


def main():
    piles = [3,6,7,11]
    h = 8
    print("output : {}".format(Solution().minEatingSpeed(piles, h)))

if __name__ == "__main__":
    main()