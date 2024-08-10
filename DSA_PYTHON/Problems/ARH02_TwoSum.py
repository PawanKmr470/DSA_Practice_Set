# REF : https://leetcode.com/problems/two-sum/
# NOTES :
#       Hash map to check if the complementing digit (y = t - x) is present in
#       hash map or not. Map (not set) for storing index number
# T: O(n)
# S: O(n)

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hashmap = {}
        for i, n in enumerate(nums):
            rem_digit = target - n
            if rem_digit in hashmap:
                return [hashmap[rem_digit], i]
            hashmap[n] = i
        return []

def main():
    nums = [2,7,11,15]
    target = 9
    print("output : {}".format(Solution().twoSum(nums, target)))

if __name__ == "__main__":
    main()