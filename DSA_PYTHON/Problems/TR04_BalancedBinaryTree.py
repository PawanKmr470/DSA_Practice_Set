# REF : https://leetcode.com/problems/balanced-binary-tree/solution/
# NOTES :
#       1 way - calculate the heights of left and right subtrees and compare the result
#               need to implement height function. Total O(n^2). Top down approach
#       2 way - go to the leaves and while rolling back compare heights and return
#               return -1 if not balanced else return height of subtrees

# T: O(n^2)
# S: O(H^2) for balanced tree OR O(n^2) for skew tree case
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalanced(self, root):
        if root is None:
            return True         # BASE CASE ***

        lh = self.height(root.left)
        rh = self.height(root.right)
        if abs(lh - rh) > 1: return False

        return self.isBalanced(root.left) and self.isBalanced(root.right)

    def height(self, root):
        if root is None:
            return 0
        return 1 + max(self.height(root.left), self.height(root.right))

# T: O(n)
# S: O(H) - Height of BT : H = logn
#       In case of balanced tree S : O(H)
#       In case of skew tree     S : O(n)
class Solution2:
    def isBalanced(self, root):
        if root is None:
            return True         # BASE CASE ***

        return self.height(root) != -1

    def height(self, root):
        if root is None:
            return 0

        lh = self.height(root.left)
        if lh == -1:
            return -1
        rh = self.height(root.right)
        if rh == -1:
            return -1

        if abs(lh - rh) > 1:
            return -1

        return 1 + max(lh, rh)


def main():
    pass

if __name__ == "__main__":
    main()
