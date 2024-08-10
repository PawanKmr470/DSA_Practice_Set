# REF : https://leetcode.com/problems/valid-palindrome-iii/description/
# NOTES :
#       Top Down approach where at each stage i and j is compared if equal i++ & j--
#       and if not then two choices are being made -
#       First - take i and j - 1 and Second - take i + 1 and j
#       and same process is repeated.
#       TODO_ITEM : it's Bottom Up solution need to tryout and 1D Solution also which has S : O(n)

# T: O(2^n)
# S: O(2^n)
class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:

        def dfs(st, i, j):
            if i == j:          # when remaining strlen is 1
                return 0

            if i == j - 1:      # when remaining strlen is 2
                return 1 if st[i] != st[j] else 0   # 2 elements are different
                                                    # then 1 can be eliminated to make
                                                    # 1 char string palindrome
            if st[i] == st[j]:
                return dfs(st, i + 1, j - 1)
            else:
                return 1 + min(dfs(st, i + 1, j), dfs(st, i, j - 1))

        return dfs(s, 0, len(s) - 1) <= k


# T: O(n^2) with memoization
# S: O(n^2)
class Solution2:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        dp = [[-1 for j in range(len(s))] for i in range(len(s))]

        def dfs(st, i, j):
            if i == j:
                return 0

            if i == j - 1:
                return 1 if st[i] != st[j] else 0

            if dp[i][j] != -1:
                return dp[i][j]

            if st[i] == st[j]:
                dp[i][j] = dfs(st, i + 1, j - 1)
                return dp[i][j]
            else:
                dp[i][j] = 1 + min(dfs(st, i + 1, j), dfs(st, i, j - 1))
                return dp[i][j]

        return dfs(s, 0, len(s) - 1) <= k

def main():
    s = "abcdeca"
    k = 2
    print("output : {}".format(Solution().isValidPalindrome(s, k)))
    print("output : {}".format(Solution2().isValidPalindrome(s, k)))

if __name__ == "__main__":
    main()