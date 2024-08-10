# REF : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
# NOTES :
#      Apply DFS and in each call if node val is > than it's ascendants
#      then update the max_val with node.val and increase the count.

from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# T: O(n)
# S: O(n)
# DFS recursive
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0

        def dfs(node, maxVal):
            nonlocal count
            if node.val >= maxVal:
                count += 1

            if node.left:
                dfs(node.left, max(node.val, maxVal))
            if node.right:
                dfs(node.right, max(node.val, maxVal))

        count = 0
        dfs(root, float("-inf"))
        return count

# T: O(n)
# S: O(n)
# DFS iterative & BFS iterative with popleft change
class Solution2:
    def goodNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0

        count = 0
        s = deque()
        s.append([root, float("-inf")])
        while s:
            node, maxVal = s.pop()          # BFS with popleft
            if node.val >= maxVal:
                count += 1
            if node.left:
                s.append([node.left, max(maxVal, node.val)])
            if node.right:
                s.append([node.right, max(maxVal, node.val)])

        return count


def main():
    pass

if __name__ == "__main__":
    main()