# REF : https://leetcode.com/problems/product-of-array-except-self/
# NOTES :
#       Traverse untill the end and back to start.
#       Calculating product of till i-1 & storing it at i-1 and similarly traversing back.

# T: O(n)
# S: O(1)

class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        res = [0] * len(nums)
        prefix = 1
        for i in range(len(nums)):
            res[i] = prefix
            prefix = prefix * nums[i]
        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            res[i] = res[i] * postfix
            postfix = postfix * nums[i]
        return res


def main():
    print("output : {}".format(Solution().productExceptSelf([1,2,3,4])))
    print("output : {}".format(Solution().productExceptSelf([-1,1,0,-3,3])))

if __name__ == "__main__":
    main()