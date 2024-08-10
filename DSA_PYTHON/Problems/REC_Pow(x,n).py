# REF : https://leetcode.com/problems/powx-n/description/
# NOTES :
#       Recursion to make it log n base 2
#       2^10 -> 2^5 * 2^5
#       2^5  -> 2 * 2^2 * 2^2 and so on

# T: O(log n , base 2)
# S: O(log n)

class Solution:
    def myPow(self, x: float, n: int) -> float:

        ### This gives TLE & O(n)
        # temp = float(1)
        # for i in range(abs(n)):
        #     temp = temp * x

        # if n < 0:
        #     temp = 1/temp
        # return temp

        def helper(x, n):
            if n == 0: return 1
            if x == 0: return 0

            res = helper(x, n // 2)
            res = res * res
            return x * res if n % 2 else res

        res = helper(x, abs(n))
        return res if n > 0 else 1 / res



def main():
    print("output : {}".format(Solution().myPow(2, 10)))
    print("output : {}".format(Solution().myPow(2, -10)))

if __name__ == "__main__":
    main()