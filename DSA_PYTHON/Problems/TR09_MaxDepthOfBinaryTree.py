# REF : https://leetcode.com/problems/maximum-depth-of-binary-tree/
# NOTES :
#       possible ways : DFS - recursive + iterative AND BFS also
#       For BFS : number of levels = max depth

from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# DFS O(n)
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0

        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

# DFS O(n)
class Solution2:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0

        result = 1
        s = deque()
        s.append([root, 1])      # Append [root, depth], depth will be same for all the children for a processing node
        while s:
            node, depth = s.pop()
            if node:
                result = max(result, depth)
                s.append([node.left, depth + 1])
                s.append([node.right, depth + 1])

        return result

# BFS O(n)
class Solution3:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0

        depth = 0
        q = deque()
        q.append(root)
        while q:
            for i in range(len(q)):     # Increment depth every time the Queue is empty
                node = q.popleft()      # Queue will get empty each time when a level is traversed
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            depth += 1

        return depth


def main():
    n = TreeNode(3)
    n.left = TreeNode(9)
    n.right = TreeNode(20)
    n.right.left = TreeNode(15)
    n.right.right = TreeNode(7)
    print("output : {}".format(Solution().maxDepth(n)))

if __name__ == "__main__":
    main()