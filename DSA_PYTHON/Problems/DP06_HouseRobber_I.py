# House Robber 1
# T - O(2^n)
# S - O(n) The max depth of recursion can go upto n.
class Solution1:

    def rob(self, nums: list[int]) -> int:
        # return self.rob_rec(nums, len(nums) - 1)
        return self.rob_rec2(nums, 0)

    def rob_rec(self, nums, n):
        if n < 0:
            return 0
        if n == 0:
            return nums[0]
        return max(nums[n] + self.rob_rec(nums, n-2), self.rob_rec(nums, n-1))

    def rob_rec2(self, nums, n):
        if n >= len(nums):
            return 0
        return max(nums[n] + self.rob_rec2(nums, n+2), self.rob_rec2(nums, n+1))


# T - O(n)
# S - O(n) Required for dp and implicit recursive stack.
class Solution2:

    def rob(self, nums: list[int]) -> int:
        dp = [0] * (len(nums) + 1)
        return self.rob_rec2(nums, 0, dp)

    def rob_rec2(self, nums, n, dp):
        if n >= len(nums):
            return 0
        if dp[n] != 0:
            return dp[n]

        dp[n] = max(nums[n] + self.rob_rec2(nums, n + 2, dp), self.rob_rec2(nums, n + 1, dp))
        return dp[n]

# T - O(n)
# S - O(n) Required for dp.
class Solution3:

    def rob(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]

        dp = [0] * (len(nums) + 1)
        dp[0] = 0
        dp[1] = nums[0]
        for i in range(2, len(nums) + 1):
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1])
        return dp[len(nums)]

# T - O(n)
# S - O(1) Required only two variables.
class Solution4:

    def rob(self, nums: list[int]) -> int:
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]

        one = nums[0]
        two = max(one, nums[1])

        for i in range(2, len(nums)):
            tmp = two
            two = max(nums[i] + one, two)
            one = tmp
        return two


def main():
    s = Solution1()
    ret = s.rob([1,2,3,1])
    print("Recursion Output is : {}".format(ret))

    s = Solution2()
    ret = s.rob([1,2,3,1])
    print("Rec with memoization Output is : {}".format(ret))

    s = Solution3()
    ret = s.rob([1, 2, 3, 1])
    print("DP Output is : {}".format(ret))

    s = Solution4()
    ret = s.rob([1, 2, 3, 1])
    print("DP Output is : {}".format(ret))


if __name__ == "__main__":
    main()
