# REF : https://leetcode.com/problems/validate-binary-search-tree/
# NOTES :
#       Need to compare given node with updated UPPER BOUND and LOWER BOUND
#       Like "Count good nodes in BT" deque stack will have now two more elements
#       [node, low, high] to implement iterative DFS/BFS solution

from collections import deque

# T: O(n)
# S: O(n)
# DFS recursive
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root) -> bool:

        def valid(node, low, high):
            if node is None:
                return True

            if not (node.val < high and node.val > low):
                return False

            return (valid(node.left, low, node.val) and
                    valid(node.right, node.val, high))

        return valid(root, float("-inf"), float("inf"))


# T: O(n)
# S: O(n)
# DFS iterative & BFS iterative with popleft change
class Solution2:
    def isValidBST(self, root) -> bool:
        if root is None:
            return True

        s = deque()
        s.append([root, float("-inf"), float("inf")])
        while s:
            node, low, high = s.pop()                       # BFS with popleft
            if not (node.val < high and node.val > low):
                return False
            if node.left:
                s.append([node.left, low, node.val])
            if node.right:
                s.append([node.right, node.val, high])

        return True


def main():
    pass

if __name__ == "__main__":
    main()