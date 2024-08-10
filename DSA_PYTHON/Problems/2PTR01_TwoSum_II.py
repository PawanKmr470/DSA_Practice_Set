# REF : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
# NOTES :
#       Two Sum : By using Hashmap
#       Two Sum II : Since the array is already sorted, Two pointer approach is useful.

# T: O(n)
# S: O(1)

class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            cur_sum = numbers[l] + numbers[r]
            if cur_sum < target:
                l += 1
            elif cur_sum > target:
                r -= 1
            else:
                return [l + 1, r + 1]   # +1 because in output 0th position is 1st position

        return []

def main():
    print("output : {}".format(Solution().twoSum([2,7,11,15], 9)))

if __name__ == "__main__":
    main()