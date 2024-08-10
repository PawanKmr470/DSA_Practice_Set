# REF : https://leetcode.com/problems/invert-binary-tree/
# NOTES :
#       Just preorder traversal and swap the elements
#       Actually any order traversal works

from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: TreeNode):
        if root is None:
            return 0

        root.left, root.right = root.right, root.left

        self.invertTree(root.left)
        self.invertTree(root.right)

        return root

    def invertTree_iterative(self, root):
        if root is None:
            return None

        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            node.left, node.right = node.right, node.left
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

        return root

def main():
    return

if __name__ == "__main__":
    main()