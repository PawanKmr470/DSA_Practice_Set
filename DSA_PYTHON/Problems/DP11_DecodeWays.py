class Solution1:
    def numDecodings(self, s: str) -> int:
        ways = self.dfs(s, 0)
        print("[S1 Recursive] Decode ways : {}".format(ways))
        return ways

    def dfs(self, s, pos):
        if pos == len(s):
            # because with last char only one way for decoding the string
            return 1

        if s[pos] == '0':
            # because with char '0' or double-digit starting from '0' can't be decoded
            return 0

        res = self.dfs(s, pos + 1)
        if pos + 1 < len(s) and \
           (s[pos] == '1' or (s[pos] == '2' and s[pos + 1] <= '6')):
            res = res + self.dfs(s, pos + 2)

        # without conditions, it would hv looked like this
        # return self.dfs(s, pos + 1) + self.dfs(s, pos + 2)
        return res


class Solution11:
    def numDecodings(self, s: str) -> int:
        dp = [-1] * (len(s) + 1)
        ways = self.dfs(s, 0, dp)
        print("[S1 Memoized Rec] Decode ways : {}".format(ways))
        return ways

    def dfs(self, s, pos, dp):
        if dp[pos] != -1:
            return dp[pos]

        if pos == len(s):
            # because with last char only one way for decoding the string
            return 1

        if s[pos] == '0':
            # because with char '0' or double-digit starting from '0' can't be decoded
            return 0

        res = self.dfs(s, pos + 1, dp)
        if pos + 1 < len(s) and \
           (s[pos] == '1' or (s[pos] == '2' and s[pos + 1] <= '6')):
            res = res + self.dfs(s, pos + 2, dp)

        # without conditions, it would hv looked like this
        # return self.dfs(s, pos + 1) + self.dfs(s, pos + 2)
        dp[pos] = res
        return dp[pos]



class Solution2:
    def numDecodings(self, s: str) -> int:
        ways = self.dfs(s, len(s) - 1)
        print("[S2 Rec backwards] Decode ways : {}".format(ways))
        return ways

    def dfs(self, s, pos):
        if pos == 0: return 1
        if pos < 0: return 1
        if s[pos - 1] == '0': return 0

        res = self.dfs(s, pos - 1)
        if pos - 1 >= 0 and \
           (s[pos - 1] == '1' or (s[pos - 1] == '2' and s[pos] <= '6')):
            res = res + self.dfs(s, pos - 2)

        return res


class Solution3:
    def numDecodings(self, s: str) -> int:
        if len(s) == 1:
            print("[DP array] Decode ways : {}".format(1))
            return 1

        dp = [0] * (len(s) + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, len(s) + 1):
            if s[i - 1] > '0':  # i.e. s[i - 1] -> could be anything b/w '1' to '9'
                c1 = dp[i - 1]
            if s[i - 2] == '1' or (s[i - 2] == '2' and s[i - 1] <= '6'):
                c2 = dp[i - 2]
            dp[i] = c1 + c2

        print("[DP array] Decode ways : {}".format(dp[len(s)]))
        return dp[len(s)]


def main():

    # NOTE : Needs to be fixed corner cases are not working.

    # mystr = "12"
    # mystr = "226"
    # mystr = "06"
    mystr = "123"
    s = Solution1()
    s.numDecodings(mystr)
    s = Solution11()
    s.numDecodings(mystr)
    s = Solution2()
    s.numDecodings(mystr)
    s = Solution3()
    s.numDecodings(mystr)
    return


if __name__ == "__main__":
    main()