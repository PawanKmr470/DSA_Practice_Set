# REF : https://leetcode.com/problems/merge-two-binary-trees/
# NOTES :
#       preorder traversal

# T: O(n + m)
# S: O(nH + mH) if balanced or O(n + m) if skew

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def mergeTrees(self, root1, root2):
        if not root1 and not root2:
            return None

        v1 = root1.val if root1 else 0
        v2 = root2.val if root2 else 0
        root = TreeNode(v1 + v2)

        if root1 and root2:
            root.left = self.mergeTrees(root1.left, root2.left)
        if not root1 and root2:
            root.left = self.mergeTrees(None, root2.left)
        if root1 and not root2:
            root.left = self.mergeTrees(root1.left, None)

        if root1 and root2:
            root.right = self.mergeTrees(root1.right, root2.right)
        if not root1 and root2:
            root.right = self.mergeTrees(None, root2.right)
        if root1 and not root2:
            root.right = self.mergeTrees(root1.right, None)
        return root

        # root.left = self.mergeTrees(root1.left if root1 else None, root2.left if root2 else None)
        # root.right = self.mergeTrees(root1.right if root1 else None, root2.right if root2 else None)
        # return root


# Merging root2 into root1. Not separate BT
class Solution2:
    def mergeTrees(self, root1, root2):
        if not root1:
            return root2
        if not root2:
            return root1

        root1.val += root2.val

        root1.left = self.mergeTrees(root1.left if root1 else None, root2.left if root2 else None)
        root1.right = self.mergeTrees(root1.right if root1 else None, root2.right if root2 else None)

        return root1


def main():
    pass

if __name__ == "__main__":
    main()