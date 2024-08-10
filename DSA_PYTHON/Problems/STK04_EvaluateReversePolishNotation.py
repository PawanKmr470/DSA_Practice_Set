# REF : https://leetcode.com/problems/evaluate-reverse-polish-notation/
# NOTES :
#       Use stack. while traversing once the operator comes, pop two values,
#       perform operation and push again into stack.

# T: O(n)
# S: O(n)

class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack = []
        for x in tokens:
            if x not in ["+", "-", "*", "/"]:
                stack.append(int(x))
            elif x == "+":
                a = stack.pop()
                b = stack.pop()
                stack.append(a + b)
            elif x == "-":
                a = stack.pop()
                b = stack.pop()
                stack.append(b - a)
            elif x == "*":
                a = stack.pop()
                b = stack.pop()
                stack.append(b * a)
            elif x == "/":
                a = stack.pop()
                b = stack.pop()
                stack.append(int(b / a))

        return stack[0]


def main():
    pass

if __name__ == "__main__":
    main()