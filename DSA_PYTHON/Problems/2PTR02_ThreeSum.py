# REF : https://leetcode.com/problems/3sum/
# NOTES :
#       3 Pointers - 1 pointer for first pass 0th index to (len-1) +
#                    2 pointers similar to 2sum approach

# T: O(nlogn) + O(n^2) - sorting + (1 pass + 2 sum)
# S: O(1) but O(n) due sorting

class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        res = []
        nums.sort()

        for i, n in enumerate(nums):
            if i > 0 and n == nums[i - 1]:
                continue    # For skipping the duplicates

            l, r = i + 1, len(nums) - 1
            while l < r:
                three_sum = n + nums[l] + nums[r]
                if three_sum > 0:
                    r -= 1
                elif three_sum < 0:
                    l += 1
                else:
                    res.append([n, nums[l], nums[r]])
                    l += 1

                    # For skipping the duplicates
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return res


def main():
    print("output : {}".format(Solution().threeSum([-1,0,1,2,-1,-4])))
    print("output : {}".format(Solution().threeSum([0,1,1])))

if __name__ == "__main__":
    main()