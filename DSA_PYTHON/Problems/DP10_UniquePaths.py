# https://leetcode.com/problems/unique-paths/

# Only recursion
# Time Complexity: ~O( 2^ max(m, n))
# Space Complexity: ~O(max(m, n))
class Solution1:
    def uniquePaths(self, m: int, n: int) -> int:
        if m < 1 or n < 1: return 0
        if m == 1 or n == 1: return 1
        # go_down = self.uniquePaths(m - 1, n)
        # go_right = self.uniquePaths(m, n - 1)
        #
        # return go_down + go_right
        return self.uniquePaths(m, n - 1) + self.uniquePaths(m - 1, n)


# if we want to process from 0,0 position to m-1xn-1 then we need to pass 4 params
# pos1, pos2, m, n so that we can put check for limits
# for going mxn to 0x0 only two params are required m and n

# Time Complexity: ~O( 2^ max(m, n))
# Space Complexity: ~O(max(m, n))
class Solution2:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 0 or n == 0: return 0
        return self.__unique_paths(m - 1, n - 1)

    def __unique_paths(self, m, n):
        if m < 0 or n < 0: return 0
        if m == 0 or n == 0: return 1

        return self.__unique_paths(m - 1, n) + self.__unique_paths(m, n - 1)


# Recursion with memoization
# T : O(mxn)
# S : O(mxn)
class Solution3:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 0 or n == 0: return 0
        memo = [[-1 for j in range(n + 1)] for i in range(m + 1)]   # init with -1
        return self.__unique_paths(m - 1, n - 1, memo)

    def __unique_paths(self, m, n, memo):
        if m < 0 or n < 0: return 0
        if m == 0 or n == 0: return 1

        if memo[m][n] != -1:
            return memo[m][n]

        memo[m][n] = self.__unique_paths(m - 1, n, memo) + \
                     self.__unique_paths(m, n - 1, memo)
        return memo[m][n]

# DP
# T : O(mxn)
# S : O(mxn)
class Solution4:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 0 or n == 0: return 0

        dp = [[0 for j in range(n)] for i in range(m)]  # init with 0
        for i in range(m):
            dp[i][0] = 1
        for j in range(n):
            dp[0][j] = 1

        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        return dp[m - 1][n - 1]

# DP - Space optimization
# T : O(mxn)
# S : O(n) only 2 array would be required
class Solution5:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 0 or n == 0: return 0

        dp = [[0 for j in range(n)] for i in range(2)]
        for i in range(2):
            dp[i][0] = 1
        for j in range(n):
            dp[0][j] = 1

        for i in range(m - 1):
            for j in range(1, n):
                dp[1][j] = dp[0][j] + dp[1][j - 1]
            dp[0] = dp[1]

        return dp[1][n - 1]

def main():
    print("Unique paths : {}".format(Solution1().uniquePaths(3,7)))
    print("Unique paths : {}".format(Solution2().uniquePaths(3,7)))
    print("Unique paths : {}".format(Solution3().uniquePaths(3,7)))
    print("Unique paths : {}".format(Solution4().uniquePaths(3,7)))
    print("Unique paths : {}".format(Solution5().uniquePaths(3,7)))


if __name__ == "__main__":
    main()