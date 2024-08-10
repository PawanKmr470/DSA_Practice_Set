# REF : https://leetcode.com/problems/generate-parentheses/
# NOTES :
#       Stack + DFS + Backtracking => Solution 1
#       if open count == close count == n then it's one of the results
#       if open count < n then we can add "("
#       if close count < open count then we can add ")"

#       DFS => Solution 2
#       Use two integers to count the remaining left parenthesis (n)
#       and the right parenthesis (m) to be added.
#       At each function call add a left parenthesis if n > 0
#       and add a right parenthesis if m > 0

# T: O( 4^n / n * sqrt(n) )
# S: O( 4^n / n * sqrt(n) )
class Solution:
    def generateParenthesis(self, n: int) -> list[str]:

        res = []
        stack = []

        def backtrack(open_cnt, close_cnt):
            if open_cnt == close_cnt == n:
                res.append("".join(stack))
                return

            if open_cnt < n:
                stack.append("(")
                backtrack(open_cnt + 1, close_cnt)
                stack.pop()     # Need to pop the same element that we added

            if close_cnt < open_cnt:
                stack.append(")")
                backtrack(open_cnt, close_cnt + 1)
                stack.pop()     # Need to pop the same element that we added

        backtrack(0, 0)
        return res

# T: O(2^n)
# S: O(2^n)
class Solution2:
    def generateParenthesis(self, n: int) -> list[str]:
        res = []

        def dfs(n, m, ans):
            if n == 0 and m == 0:
                res.append(ans)
                return

            if n > 0:
                dfs(n-1, m+1, ans + '(')
            if m > 0:
                dfs(n, m-1, ans + ')')

        dfs(n, 0, "")
        return res

def main():
    print(Solution().generateParenthesis(3))
    print(Solution2().generateParenthesis(3))

if __name__ == "__main__":
    main()