# REF : https://leetcode.com/problems/graph-valid-tree/
# NOTES :
#       A graph is a valid tree once two conditions are met -
#           1. It doesn't contian cycle
#           2. All Vertices are connected i.e. No disconnected components
#       And if len of visited set is equal to number of vertices
#       This problem is for undirected graph.

# T: O(V + E)
# S: O(V) due to hash set visited for vertices

class Solution:
    def validTree(self, n: int, edges: list[list[int]]) -> bool:

        if not n:
            return True     # No veritces is valid tree. Assumption

        adj_list = {i:[] for i in range(n)}
        for n1, n2 in edges:
            adj_list[n1].append(n2)
            adj_list[n2].append(n1)

        visited = set()

        def dfs(n, prev):
            if n in visited:
                return False

            visited.add(n)
            for nei in adj_list[n]:
                if nei == prev:
                    continue
                if not dfs(nei, n):        # if dfs(nei) returns False, return False. Otherwise continue
                    return False

            return True

        return dfs(0, -1) and n == len(visited)  # start vertex, default previous (-1 which won't match with any v)


def main():
    n = 5
    edges1 = [[0,1],[0,2],[0,3],[1,4]]                   # True
    edges2 = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]    # False

    print("Is graph valid tree : {}".format(Solution().validTree(n, edges1)))
    print("Is graph valid tree : {}".format(Solution().validTree(n, edges2)))


if __name__ == '__main__':
    main()