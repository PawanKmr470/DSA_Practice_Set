# REF : https://leetcode.com/problems/longest-consecutive-sequence/
# NOTES :
#       SET is used to find the just previous element exists or not
#       If exists, skip the number because it's not a start of a sequence
#       If doesn't exist, it's a start of a sequence.

# T: O(n)
# S: O(n)

class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        ans_longest = 0
        num_set = set(nums)     # Create set from int list

        for n in nums:
            if (n-1) not in num_set:    # Means it's a new sequence
                length = 0
                while (n + length) in num_set:
                    length = length + 1

                # collect the ans
                ans_longest = max(ans_longest, length)
        return ans_longest


def main():
    print("output : {}".format(Solution().longestConsecutive([100,4,200,1,3,2])))

if __name__ == "__main__":
    main()