# REF : https://leetcode.com/problems/search-in-rotated-sorted-array/
# NOTES :
#       Basic method would be find min in array and search in two arrays partitioned from min element

# T: O(log n)
# S: O(1)

class Solution:
    def search(self, nums: list[int], target: int) -> int:
        if len(nums) == 1:
            if target == nums[0]:
                return 0
            else:
                return -1

        min_idx = self.findMin(nums)
        if target == nums[min_idx]:
            return min_idx
        res1 = self.binarySearch(nums[0:min_idx], target)
        if res1 != -1: return res1
        res2 = self.binarySearch(nums[min_idx:], target)
        if res2 != -1:
            return min_idx + res2

        return -1

    def findMin(self, nums: list[int]) -> int:
        if len(nums) == 1 or nums[0] < nums[-1]:
            return nums[0]

        l, r = 0, len(nums) - 1

        while l < r:
            if nums[l] < nums[r]:
                return l

            m = (l + r) // 2
            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m

        return l

    def binarySearch(self, arr, x):

        low = 0
        high = len(arr) - 1

        while low <= high:

            mid = low + (high - low) // 2

            if arr[mid] == x:
                return mid

            elif arr[mid] < x:
                low = mid + 1

            else:
                high = mid - 1

        return -1


class Solution2:
    def search(self, nums: list[int], target: int) -> int:
        if not nums:
            return -1

        low, high = 0, len(nums) - 1

        while low <= high:
            mid = (low + high) // 2
            if target == nums[mid]:
                return mid

            if nums[low] <= nums[mid]:
                if nums[low] <= target <= nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if nums[mid] <= target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1

        return -1


def main():
    nums = [4, 5, 6, 7, 0, 1, 2]
    target = 0
    print("output : {}".format(Solution().search(nums, target)))
    print("output : {}".format(Solution2().search(nums, target)))

if __name__ == "__main__":
    main()