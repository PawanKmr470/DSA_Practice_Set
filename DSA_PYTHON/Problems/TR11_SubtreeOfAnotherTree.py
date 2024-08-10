# REF : https://leetcode.com/problems/subtree-of-another-tree/
# NOTES :
#       Same tree logic is re-used for if root's left subtree is subTree or
#       root's right subtree is subTree

# T: O(n^2)
# S: O(n^2)
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubtree(self, root, subRoot) -> bool:
        if root is None: return False
        if subRoot is None: return True

        if self.sameTree(root, subRoot):
            return True

        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)

    def sameTree(self, p, q):
        if not p and not q: return True
        if p and q and p.val == q.val:
            return self.sameTree(p.left, q.left) and self.sameTree(p.right, q.right)
        return False


def main():
    pass

if __name__ == "__main__":
    main()