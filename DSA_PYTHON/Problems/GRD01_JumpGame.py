# REF : https://leetcode.com/problems/jump-game/
# NOTES :
#       Here Greedy is preferred over DP.
#       If the question asks min no of hops to reach end index instead of returing T/F,
#       may be DP could solve that but with same idea starting from end to index 0.
#       Brute Force approach - T: O(n^n)
#       Brute Force with caching T: O(n^2)

# T: O(n)
# S: O(1)

class Solution:
    def canJump(self, nums: list[int]) -> bool:
        goal = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[i] >= goal:
                goal = i

        return True if goal == 0 else False


def main():
    nums = [2,3,1,1,4]
    print("can jump : {}".format(Solution().canJump(nums)))

if __name__ == "__main__":
    main()
