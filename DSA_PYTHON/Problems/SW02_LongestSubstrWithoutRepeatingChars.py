# REF : https://leetcode.com/problems/longest-substring-without-repeating-characters/
# NOTES :
#       Brute force way is to calculate substr len for each character and get the max out of it
#       Efficient approach is to use Sliding window technique.
#       Since it's non-repeating substr, we need to have set.
#       Keeping filling set with moving right ptr and as right ptr encounters duplicate
#       remove that duplicate char from set and move left ptr untill the duplicate char is removed.

# T: O(n)
# S: O(n)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        char_set = set()
        l = 0
        for r in range(len(s)):
            while s[r] in char_set:
                char_set.remove(s[l])
                l += 1
            char_set.add(s[r])
            res = max(res, r - l + 1)

        return res

def main():
    print("output : {}".format(Solution().lengthOfLongestSubstring("abcabcbb")))

if __name__ == "__main__":
    main()