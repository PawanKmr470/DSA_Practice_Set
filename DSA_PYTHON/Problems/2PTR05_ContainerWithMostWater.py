# REF : https://leetcode.com/problems/container-with-most-water/
# NOTES :
#       Brute force method is n^2 i.e. For each line calculate area with rest of the line
#       and take max of out those
#       Two pointers approach is in O(n)

# T: O(n)
# S: O(1)

class Solution:
    def maxArea(self, height: list[int]) -> int:

        res = 0
        l, r = 0, len(height) - 1
        while l < r:
            area = (r - l) * min(height[r], height[l])
            res = max(res, area)

            if height[l] < height[r]:
                l += 1
            elif height[l] > height[r]:
                r -= 1
            else:
                r -= 1
                # l += 1 # would have also worked out

        return res


def main():
    height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    print("output : {}".format(Solution().maxArea(height)))

if __name__ == "__main__":
    main()