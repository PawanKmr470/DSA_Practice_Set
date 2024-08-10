# REF : https://leetcode.com/problems/valid-palindrome-ii/
# NOTES :
#       palindrome string's reverse is also happens to be the same string
#       2 pointer towards the middle if then mismatch then 2 choices
#       skip left char and check rest of the string for palindrome and skip right & do the same.

# T: O(2n) ~O(n) due to 2 choices skip left & skip right
# S: O(n) can be reduced to O(1) with small function to check parlindrome at given indices

class Solution:
    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                skip_left_str = s[l+1:r+1]  # py str is s[l,r)
                skip_right_str = s[l:r]
                return skip_left_str == skip_left_str[::-1] or \
                    skip_right_str == skip_right_str[::-1]
            l += 1
            r -= 1
        return True


def main():
    print("output : {}".format(Solution().validPalindrome("abca")))

if __name__ == "__main__":
    main()