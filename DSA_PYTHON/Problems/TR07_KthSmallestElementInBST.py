# REF : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
# NOTES :
#       Inorder traversal of BST gives sorted output

# T: O(n)
# S: O(n)
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthSmallest(self, root, k) -> int:
        sortlist = []

        def inorder(node):
            if node is None:
                return

            inorder(node.left)
            sortlist.append(node.val)
            inorder(node.right)

        inorder(root)
        return sortlist[k - 1]


def main():
    pass

if __name__ == "__main__":
    main()