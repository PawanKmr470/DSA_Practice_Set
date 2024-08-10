# REF: https://leetcode.com/problems/maximum-subarray/
# NOTES:
#       Max Subarray solution is Kadane's Algorithm

# T: O(n)
# S: O(1)

class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        maxSum = nums[0]
        curSum = 0
        for n in nums:
            if curSum < 0:
                curSum = 0
            curSum += n
            maxSum = max(curSum, maxSum)
        return maxSum

        # for n in nums:
        #     curSum = max(curSum + n, n)
        #     maxSum = max(maxSum, curSum)
        #
        # return maxSum


def main():
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    print("max sumarray sum : {}".format(Solution().maxSubArray(nums)))

if __name__ == "__main__":
    main()
