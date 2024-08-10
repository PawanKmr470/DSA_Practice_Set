# REF : https://leetcode.com/problems/daily-temperatures/
# NOTES :
#       Monotinic Stack
#       Stack is used to keep last warmer temperature and it's day count so far
#       if temp increases (> than temps which are on stack) then it's compared with
#       stack's top value and days diff is updated in result array. Keep comparing
#       till stack's top element's temperature value is lower.

# T: O(n), brute force method will do in O(n^2)
# S: O(n)

class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        res = [0] * len(temperatures)
        stack = []  # stack value - pair [temp, index]

        for i, t in enumerate(temperatures):
            while stack and t > stack[-1][0]:
                stackTmp, stackInx = stack.pop()
                res[stackInx] = i - stackInx
            stack.append([t, i])

        return res

def main():
    print("output : {}".format(Solution().dailyTemperatures([73,74,75,71,69,72,76,73])))

if __name__ == "__main__":
    main()