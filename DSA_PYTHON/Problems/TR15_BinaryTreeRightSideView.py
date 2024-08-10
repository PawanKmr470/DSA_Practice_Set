# REF : https://leetcode.com/problems/binary-tree-right-side-view/
# NOTES :
#       BFS with queue where queue's last element is required at each level

# T: O(n)
# S: O(n)

from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root):
        if root is None:
            return []

        result = []
        q = deque()
        q.append(root)
        while q:
            for i in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            result.append(node.val)
        return result


def main():
    pass

if __name__ == "__main__":
    main()