# REF : https://leetcode.com/problems/same-tree/
# NOTES :
#       Base condition - If both p, q are null then they are same -> True
#       While traversing any of the node is None then return False
#       Check if the node value is not same then return False
#       call recursively to left right for both

# T: O(n)
# S: O(n) stack space
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p, q) -> bool:
        if not p and not q:
            return True

        if not p or not q:
            return False

        if p.val != q.val:
            return False

        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

        # Also same logic

        # if p and q and p.val == q.val:
        #     return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        # return False



def main():
    pass

if __name__ == "__main__":
    main()