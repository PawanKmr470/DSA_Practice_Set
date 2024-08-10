# REF : https://leetcode.com/problems/binary-tree-maximum-path-sum/
# NOTES :
#       Run DFS & while rolling back calculate max sum so far and store it in a max_sum variable.
#       max_sum will be -> max including this current node OR excluding this current node
#       (i.e. max_sum so far) -> max(maxSum, node.val + left_max + right_max)
#       while returning, it will return including current node val + max so far
#       (i.e. max(left_max,right_max)

# T: O(n)
# S: O(H) for balanced tree OR O(n) for skew tree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root) -> int:

        def dfs(node):
            nonlocal maxSum
            if not node:
                return 0

            left_max = dfs(node.left)
            right_max = dfs(node.right)

            left_max = max(left_max, 0)  # This will avoid -ve or sum reducing cases
            right_max = max(right_max, 0)

            maxSum = max(maxSum, node.val + left_max + right_max)

            return node.val + max(left_max, right_max)

        maxSum = float("-inf")
        dfs(root)
        return maxSum


def main():
    pass

if __name__ == "__main__":
    main()