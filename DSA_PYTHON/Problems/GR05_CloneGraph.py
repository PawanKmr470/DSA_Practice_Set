from collections import deque

# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


# T: O(V + E) - for BFS
# S: O(V) - for the hashmap
class Solution1:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None: return None
        oldToNew = {}    # visited dict - [oldNode] : newNone

        def dfs(node):
            if node in oldToNew:
                return oldToNew[node]

            copy = Node(node.val, [])
            oldToNew[node] = copy

            for nei in node.neighbors:
                copy.neighbors.append(dfs(nei))
            return copy

        return dfs(node)


# With DFS using stack
class Solution2:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None: return None
        oldToNew = {}   # HashMap
        s = deque()     # Stack

        s.append(node)
        oldToNew[node] = Node(node.val, [])
        while s:
            orig_node = s.pop()

            for nei in orig_node.neighbors:
                if nei not in oldToNew:
                    oldToNew[nei] = Node(nei.val, [])
                    s.append(nei)

                # Every node will be visited once and we need to copy whole adj list of orig node to new node
                oldToNew[orig_node].neighbors.append(oldToNew[nei])

        return oldToNew[node]


def main():
    return

if __name__ == '__main__':
    main()