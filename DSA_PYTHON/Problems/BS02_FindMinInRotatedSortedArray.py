# REF : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solution/
# NOTES :
#       In rotated sorted array, min element will always be present in unsorted part of array

# T: O(logn)
# S: O(1)

class Solution:
    def findMin(self, nums: list[int]) -> int:
        if len(nums) == 1 or nums[0] < nums[-1]:
            return nums[0]

        l, r = 0, len(nums) - 1
        while l <= r:
            m = l + (r - l) // 2
            if m > 0 and nums[m - 1] > nums[m]:
                return nums[m]

            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m - 1

        return nums[l]

class Solution2:
    def findMin(self, nums: list[int]) -> int:
        if len(nums) == 1 or nums[0] < nums[-1]:
            return nums[0]

        l, r = 0, len(nums) - 1

        while l < r:
            if nums[l] < nums[r]:
                return nums[l]

            m = (l + r) // 2
            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m

        return nums[l]


# Recursive solution
class Solution3:
    def findMin(self, nums: list[int]) -> int:
        if len(nums) == 1 or nums[0] < nums[-1]:
            return nums[0]
        return self.find_rec(nums, 0, len(nums) - 1)

    def find_rec(self, nums, l, r):

        if nums[l] < nums[r]:
            return nums[l]
        if l < r:
            m = (l + r) // 2
            if nums[m] > nums[r]:
                return self.find_rec(nums, m + 1, r)
            else:
                return self.find_rec(nums, l, m)
        else:
            return nums[l]


def main():
    # nums = [4,5,6,7,0,1,2]
    nums = [5,6,7,8,9,10,0,1,2,3,4]
    # nums = [10,0,1,2,3,4,5,6,7,8,9]
    print("output : {}".format(Solution().findMin(nums)))
    print("output : {}".format(Solution2().findMin(nums)))
    print("output : {}".format(Solution3().findMin(nums)))

if __name__ == "__main__":
    main()