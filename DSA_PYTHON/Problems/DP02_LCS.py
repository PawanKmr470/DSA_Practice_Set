# REF : https://leetcode.com/problems/longest-common-subsequence/
# NOTES :
#

# T - O(2^n)
# S - O(2^n)

class Solution1:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        def lcs(str1, str2, len1, len2):
            if len1 == 0 or len2 == 0:
                return 0

            if str1[len1 - 1] == str2[len2 - 1]:
                return 1 + lcs(str1, str2, len1 - 1, len2 - 1)
            else:
                return max(lcs(str1, str2, len1 - 1, len2),
                           lcs(str1, str2, len1, len2 - 1))

        return lcs(text1, text2, len(text1), len(text2))

class Solution2:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        def lcs(str1, str2, len1, len2):
            if len1 == len(str1) or len2 == len(str2):
                return 0

            if str1[len1] == str2[len2]:
                return 1 + lcs(str1, str2, len1 + 1, len2 + 1)
            else:
                return max(lcs(str1, str2, len1 + 1, len2),
                           lcs(str1, str2, len1, len2 + 1))

        return lcs(text1, text2, 0, 0)

# T - O(n)
# S - O(n)
class Solution3:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m = len(text1)
        n = len(text2)
        memo = [[-1 for _ in range(n + 1)] for _ in range(m + 1)]

        def lcs(str1, str2, len1, len2):
            if len1 == 0 or len2 == 0:
                return 0

            if memo[len1][len2] != -1:
                return memo[len1][len2]

            if str1[len1 - 1] == str2[len2 - 1]:
                memo[len1][len2] = 1 + lcs(str1, str2, len1 - 1, len2 - 1)
            else:
                memo[len1][len2] = max(lcs(str1, str2, len1 - 1, len2),
                                       lcs(str1, str2, len1, len2 - 1))
            return memo[len1][len2]

        return lcs(text1, text2, len(text1), len(text2))

#   dp approach is and get_lcs string is in C++

def main():
    print("output : {}".format(Solution1().longestCommonSubsequence("abcde", "ace")))
    print("output : {}".format(Solution2().longestCommonSubsequence("abcde", "ace")))
    print("output : {}".format(Solution3().longestCommonSubsequence("abcde", "ace")))

if __name__ == "__main__":
    main()