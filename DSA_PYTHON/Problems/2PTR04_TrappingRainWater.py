# REF : https://leetcode.com/problems/trapping-rain-water/
# NOTES :
#       Brute force way is to calculate water unit for ith position with taking
#       min(max(left_wall),max(right_wall)) - height[i] i.e.
#       for every i, need to do i to 0 and i to n - 1 to find max left_wall & right_wall
#       T: O(n^2) & S: O(1)
#       More acceptable solution would be keeping Prefix Max & Postfix Max
#       Prefix Max is going to tell what is maximum (i-1) till ith position &
#       Postfix Max is going to tell what is maximum (i+1) after ith position.
#       O(n) for prefix max + O(n) for postfix max + O(n) for calculating answer
#       T: O(n) & S: O(2n)
#       Most optimal solution is using Two pointer approach T: O(n) & S: O(n)

# 2nd Approach
# T: O(n)
# S: O(2n)
class Solution:
    def trap(self, height: list[int]) -> int:
        prefix_max = []
        pmax = 0
        for h in height:
            pmax = max(pmax, h)
            prefix_max.append(pmax)

        postfix_max = []
        pmax = 0
        for h in height[::-1]:
            pmax = max(pmax, h)
            postfix_max.append(pmax)
        postfix_max.reverse()

        res = 0
        for i, h in enumerate(height):
            min_wall = min(prefix_max[i], postfix_max[i])
            water_unit = min_wall - h
            if water_unit > 0:
                res += water_unit
        return res


# 3rd Approach
# T: O(n)
# S: O(1)
class Solution2:
    def trap(self, height: list[int]) -> int:
        if not height: return 0

        res = 0
        l, r = 0, len(height) - 1
        left_max, right_max = height[l], height[r]
        while l < r:
            if left_max < right_max:
                l += 1
                left_max = max(left_max, height[l])
                res += left_max - height[l]
            else:
                r -= 1
                right_max = max(right_max, height[r])
                res += right_max - height[r]

        return res


def main():
    height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print("output : {}".format(Solution().trap(height)))
    print("output : {}".format(Solution2().trap(height)))

if __name__ == "__main__":
    main()