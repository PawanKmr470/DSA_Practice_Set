"""
Graph Implementation : directed, undirected and weighted
Graph using adjancy list
In adj list to add weight, we can have list of tuple for each vertex
[0] -> [(1, 25), (2, 30)]
"""
from collections import deque
from copy import deepcopy


class Graph:

    def __init__(self, vertices, directed=False):
        self.vertices = vertices
        self.directed = directed
        self.adj_list = [[] for v in range(self.vertices)]

    def add_edge(self, v1, v2, weight=1):
        self.adj_list[v1].append((v2, weight))
        if not self.directed:
            self.adj_list[v2].append((v1, weight))

    # If weight is given, edge can be removed with O(1)
    def remove_edge(self, v1, v2):
        for i, dst in enumerate(self.adj_list[v1]):
            if dst[0] == v2:
                self.adj_list[v1].pop(i)

        if not self.directed:
            for i, dst in enumerate(self.adj_list[v2]):
                if dst[0] == v1:
                    self.adj_list[v2].pop(i)

    def print(self):
        print("Adj list : ")
        for index, x in enumerate(self.adj_list):
            print("{} -> {}".format(index, x))

    def bfs(self, start):
        print("BFS traversal : ", end="")
        visited = set()
        self.__bfs(start, visited)

    # Deque as a queue
    def __bfs(self, start, visited):
        q = deque()
        q.append(start)
        visited.add(start)
        while len(q):
            v = q.popleft()
            print(v, end=" ")
            for next_v in self.adj_list[v]:
                if next_v[0] not in visited:
                    q.append(next_v[0])
                    visited.add(next_v[0])
        print()

    def disconnected_graphs_bfs(self):
        visited = set()
        count = 0
        for start in range(len(self.adj_list)):
            if start not in visited:
                self.__bfs(start, visited)
                count += 1
        print("BFS Disconnected graphs : {}".format(count))

    def dfs(self, start):
        print("DFS traversal : ", end="")
        visited = set()
        self.__dfs(start, visited)

    # Deque as a stack : q -> s
    # popleft() -> pop() and rest is similar like bfs ***
    def __dfs(self, start, visited):
        q = deque()
        q.append(start)
        visited.add(start)
        while len(q):
            v = q.pop()
            print(v, end=" ")
            for next_v in self.adj_list[v]:
                if next_v[0] not in visited:
                    q.append(next_v[0])
                    visited.add(next_v[0])
        print()

    def disconnected_graphs_dfs(self):
        visited = set()
        count = 0
        for start in range(len(self.adj_list)):
            if start not in visited:
                self.__dfs(start, visited)
                count += 1
        print("DFS Disconnected graphs : {}".format(count))

    def dfs_rec(self, start):
        print("DFS rec traversal : ", end="")
        visited = set()
        visited.add(start)
        self.__dfs_rec(start, visited)
        print()

    def __dfs_rec(self, start, visited):
        print("{}".format(start), end=" ")
        for next_v in self.adj_list[start]:
            if next_v[0] not in visited:
                visited.add(next_v[0])
                self.__dfs_rec(next_v[0], visited)

    def disconnected_graphs_dfs_rec(self):
        visited = set()
        count = 0
        for start in range(len(self.adj_list)):
            if start not in visited:
                visited.add(start)
                self.__dfs_rec(start, visited)
                count += 1
                print()
        print("DFS rec Disconnected graphs : {}".format(count))

    # T(n) = O(V^V)
    # S(n) = O(V^V)
    # DFS uses stack so better implement recursive method
    def print_all_paths_dfs(self, start, end):
        visited = set()
        path = []
        print("All DFS path from {} to {} : ".format(start, end))
        self.__all_paths_dfs(start, end, visited, path)

    def __all_paths_dfs(self, start, end, visited, path):
        visited.add(start)
        path.append(start)

        if start == end:
            print(str(path))
        else:
            for next_v in self.adj_list[start]:
                if next_v[0] not in visited:
                    self.__all_paths_dfs(next_v[0], end, visited, path)

        path.pop()
        visited.remove(start)

    # BFS uses queue so better implement iterative method
    def print_all_paths_bfs(self, start, end):
        path = []
        print("All BFS path from {} to {} : ".format(start, end))
        self.__all_paths_bfs(start, end, path)

    @staticmethod
    def __is_visited(v, path):
        for x in path:
            if x == v:
                return True
        return False

    def __all_paths_bfs(self, start, end, path):
        q = deque()
        path.append(start)
        q.append(deepcopy(path))

        while len(q):
            path = q.popleft()
            last_v = path[-1]
            if last_v == end:
                print("{}".format(path))

            for i in range(len(self.adj_list[last_v])):
                if not self.__is_visited(self.adj_list[last_v][i][0], path):
                    # new_path = path # buggy -> new_path.append will modify the path variable also
                    # new_path = path.copy()    # This also works. It's list's built-in method.
                    new_path = deepcopy(path)
                    new_path.append(self.adj_list[last_v][i][0])
                    q.append(new_path)


    # def print_shortest_path - Dijkstra's Algo
    # def print_MST - Prim's Algo
    # def print_cycles
    # def print all Hamiltonian paths


def main():

    # 0 --------- 1
    # |           |
    # |           |
    # |           |
    # 2 --------- 3 -------- 4

    # Undirected graph
    g = Graph(5)
    # g = Graph2(5)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 3)
    g.add_edge(3, 4)
    g.print()
    # g.remove_edge(3, 4)
    g.bfs(0)
    g.dfs(0)
    g.print_all_paths_dfs(0, 4)
    g.print_all_paths_bfs(0, 4)
    print("***********************")

   #  0 <-----> 2
   #  |       //\
   #  |     /   |    __
   # \|/ /     \|/ /    \
   # 1          3        |
   #             /\\ ___ /

    # Directed graph
    g = Graph(4, directed=True)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(2, 0)
    g.add_edge(2, 3)
    g.add_edge(3, 3)
    g.print()
    g.bfs(2)
    g.dfs(2)
    g.dfs_rec(2)
    g.print_all_paths_dfs(0, 3)
    g.print_all_paths_bfs(0, 3)
    print("***********************")


    # 0 ----- 1
    #
    # 2 ---- 3 ---- 4

    # Disconnected graphs
    g = Graph(5)
    g.add_edge(0, 1)
    g.add_edge(2, 3)
    g.add_edge(3, 4)
    g.disconnected_graphs_bfs()
    g.disconnected_graphs_dfs()
    g.disconnected_graphs_dfs_rec()
    g.print_all_paths_dfs(2, 4)
    g.print_all_paths_bfs(2, 4)
    print("***********************")

    #      0
    #    / |   \
    #  /   |    \\/
    # 2    |      3
    #  \  \|/    //\
    #    \\/ 1 /

    g = Graph(4, directed=True)
    g.add_edge(0, 2)
    g.add_edge(2, 0)
    g.add_edge(2, 1)
    g.add_edge(0, 1)
    g.add_edge(0, 3)
    g.add_edge(1, 3)
    g.print_all_paths_bfs(2, 3)
    print("***********************")


if __name__ == "__main__":
    main()