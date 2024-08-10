# REF : https://leetcode.com/problems/min-stack/
# NOTES :
#       Keep two stack one for actual stack and another for min value so far
#       length of both should be same

# T: O(1)
# S: O(n)

class MinStack:

    def __init__(self):
        self.stack = []
        self.minStack = []

    def push(self, val: int) -> None:
        self.stack.append(val)

        min_val = val
        if self.minStack:
            min_val = self.minStack[-1]

        val = min(val, min_val)
        # val = min(val, self.minStack[-1] if self.minStack else val)
        self.minStack.append(val)

    def pop(self) -> None:
        self.stack.pop()
        self.minStack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minStack[-1]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

def main():
    pass

if __name__ == "__main__":
    main()