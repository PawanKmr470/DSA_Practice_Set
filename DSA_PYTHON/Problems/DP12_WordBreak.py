# https://www.youtube.com/watch?v=LPs6Qo5qlJM
# Recursion only
# T: O(2^n)
# S: O(n)
class Solution1:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        if s in wordDict:
            return True

        for i in range(1, len(s) + 1):
            left = s[0:i]
            right = s[i:]
            if left in wordDict and self.wordBreak(right, wordDict):
                return True

        return False


# Recursion with memoization
# T: O(n^3) recursion tree n^2 * by each word search n
# S: O(n)
class Solution2:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        # dp = [False for _ in range(len(s) + 1)]
        dp = {}
        return self.wordBreakRec(s, wordDict, dp)

    def wordBreakRec(self, s, wordDict, dp):
        if s in wordDict:
            return True

        if s in dp:
            return dp[s]

        for i in range(1, len(s) + 1):
            left = s[0:i]
            right = s[i:]
            if left in wordDict and self.wordBreakRec(right, wordDict, dp):
                dp[left] = True
                return True

        dp[s] = False
        return False

# DP - Bottom Up
# T: O(n^3)
# S: O(n)
class Solution3:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        word_set = set(wordDict)
        dp = [False] * (len(s) + 1)
        dp[0] = True

        for i in range(1, len(s) + 1):
            for j in range(i):
                if s[j:i] in word_set and dp[j]:
                    dp[i] = True
                    break
        return dp[len(s)]


def main():
    string = "catsandog"
    word_dict = ["cats", "dog", "sand", "and", "cat"]

    # string = "applepenapple"
    # word_dict = ["apple", "pen"]
    print("Can be word broken : {}".format(Solution1().wordBreak(string, word_dict)))
    print("Can be word broken : {}".format(Solution2().wordBreak(string, word_dict)))
    print("Can be word broken : {}".format(Solution3().wordBreak(string, word_dict)))
    return

if __name__ == "__main__":
    main()