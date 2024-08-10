# REF : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
# NOTES :
#       Common ancestor - closest parent/grand parent which is connecting the given nodes p and q
#       we are not checking q is where and q is where, instead we are checking that
#       on what conditions this parent/grand parent will be on left or right or they are at left/right
#       from the current node i.e. split condition

# T: O(logn) visiting one node while traversing down the tree
# S: O(1)
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # p and q do exist so
        cur = root
        while cur:
            if p.val > cur.val and q.val > cur.val:
                cur = cur.right
            elif p.val < cur.val and q.val < cur.val:
                cur = cur.left
            else:
                # This is split condition i.e. one(p/q) would be at left and another(p/q) would be at right
                # or p and q are same then cur is the ancestor
                return cur

def main():
    pass

if __name__ == "__main__":
    main()