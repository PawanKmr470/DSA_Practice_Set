# REF : https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
# NOTES :
#   Rank doesn't let form skew tree
#   Path compression reduces the tree height and converges O(log n) to O(1)
#   For cycle detection keep unioning the edges and check for p1 == p2
#   Other standard approach : DFS/BFS on each node with visited array

# With DFS solution T & S complexities are -
# T: O(E+V)
# S: Building the adjacency list O(E)
#    visited set O(V)
#    run-time stack for DFS will use O(V)

# With Disjoint set -
# T: O(log V)
# S: O(V) due to rank & parent array

class Solution:
    def countComponents(self, n: int, edges: list[list[int]]) -> int:
        parent = [i for i in range(n)]
        rank = [1] * n

        def find(n):
            res = n
            while res != parent[res]:
                parent[res] = parent[parent[res]]   # Path compresssion
                res = parent[res]
            return res

        def union(n1, n2):

            p1 = find(n1)
            p2 = find(n2)

            if p1 == p2:
                return 0

            if rank[p1] > rank[p2]:
                parent[p2] = p1         # Make p1 parent of p2
                rank[p1] += rank[p2]    # Increase p1's rank with p2
            else:
                parent[p1] = p2
                rank[p2] += rank[p1]

            return 1

        res = n
        for n1, n2 in edges:
            res -= union(n1, n2)
        return res


def main():
    n = 5
    edges = [[0,1],[1,2],[3,4]]

    print("No of components : {}".format(Solution().countComponents(n, edges)))

if __name__ == '__main__':
    main()