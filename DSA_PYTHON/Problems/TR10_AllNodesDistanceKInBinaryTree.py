# REF  : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
# NOTES :
#       1st way : find node address if not given
#                 create node:parent hash
#                 apply BFS (iterative using queue) with a visited set
#       2nd way : Convert this tree to graph and DFS with visit set till depth k.

from collections import deque

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# T: O(2n)
# S: O(2n)
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> list[int]:

        parentHash = {}
        def createParentHash(root):
            if root is None:
                return

            if root.left:
                parentHash[root.left] = root
            if root.right:
                parentHash[root.right] = root

            createParentHash(root.left)
            createParentHash(root.right)

        if root is None:
            return []

        createParentHash(root)

        result = []
        visited = set()
        q = deque()

        q.append(target)
        while q:
            for i in range(len(q)):
                node = q.popleft()
                visited.add(node)
                if k == 0:                          # This 'if' will be removed if 'print nodes till k' is asked
                    result.append(node.val)

                if node in parentHash and parentHash[node] not in visited:
                    q.append(parentHash[node])

                if node.left and node.left not in visited:
                    q.append(node.left)

                if node.right and node.right not in visited:
                    q.append(node.right)

            k -= 1
            if k < 0:
                break

        return result


# Need to fix it
class Solution2:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> list[int]:

        result = []

        def printNodeAtk(root, target, k):
            def printSubtree(root, k):
                if root is None or k < 0:
                    return
                if k == 0:
                    result.append(root.val)

                printSubtree(root.left, k - 1)
                printSubtree(root.right, k - 1)

            if root is None:
                return -1

            if root == target:
                printSubtree(target, k)
                return result

            dl = printNodeAtk(root.left, target, k)
            if dl != -1:
                if dl + 1 == k:
                    result.append(root.val)
                else:
                    printSubtree(root.right, k-dl-2)

                return dl + 1

            dr = printNodeAtk(root.right, target, k)
            if dr != -1:
                if dr + 1 == k:
                    result.append(root.val)
                else:
                    printSubtree(root.left, k - dr - 2)

                return dr + 1


        ret = printNodeAtk(root, target, k)
        if ret == -1:
            return result


def main():
    pass

if __name__ == "__main__":
    main()