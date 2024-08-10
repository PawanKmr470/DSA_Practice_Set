# REF : https://leetcode.com/problems/valid-palindrome-iv/description/
# NOTES :
#       Two pointer approach just ignore mismatch for 2 times at max.

# T: O(n)
# S: O(1)

class Solution:
    def makePalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        count = 0
        while l < r:
            if s[l] == s[r]:
                l += 1
                r -= 1
                continue
            else:
                if count < 2:
                    l += 1
                    r -= 1
                    count += 1
                    continue
                else:
                    return False
        return True


def main():
    print("output : {}".format(Solution().makePalindrome("abcdba")))

if __name__ == "__main__":
    main()