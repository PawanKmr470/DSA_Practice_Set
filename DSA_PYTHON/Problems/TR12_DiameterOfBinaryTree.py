# REF : https://leetcode.com/problems/diameter-of-binary-tree/
# NOTES :
#       while stack unwinding, calculate height of the node and just before that
#       keep storing the max result

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Working but not efficient
# T: O(n^2) due to height calculation
# S: O(H^2) for balanced tree or O(N^2) in case of skew tree
class Solution1:
    def diameterOfBinaryTree(self, root):
        if root is None:
            return 0

        left_dia = self.diameterOfBinaryTree(root.left)
        right_dia = self.diameterOfBinaryTree(root.right)

        cur = self.height(root.left) + self.height(root.right)

        return max(cur, max(left_dia, right_dia))

    def height(self, root):
        if root is None:
            return 0
        return 1 + max(self.height(root.left), self.height(root.right))


# T: O(n)
# S: O(H) for balanced tree or O(n) in case of skew tree
class Solution2:
    def diameterOfBinaryTree(self, root):
        result = []
        result.append(0)

        def heightwithself(root):
            if root is None:
                return 0

            lh = heightwithself(root.left)
            rh = heightwithself(root.right)

            result[0] = max(result[0], lh + rh)     # Nothing to do with node val
                                                    # count of edges is required i.e. lh + rh
            return 1 + max(lh, rh)

        heightwithself(root)
        return result[0]


def main():
    pass

if __name__ == "__main__":
    main()