class Graph2:
    """ Graph using adjancy matrix """
    def __init__(self, vertices, directed=False):
        self.vertices = vertices
        self.directed = directed
        self.adj_matrix = [[0 for col in range(self.vertices)] for row in range(self.vertices)]

    def add_edge(self, v1, v2, weight=1):
        self.adj_matrix[v1][v2] = weight
        if not self.directed:
            self.adj_matrix[v2][v1] = weight

    def remove_edge(self, v1, v2):
        self.adj_matrix[v1][v2] = 0
        if not self.directed:
            self.adj_matrix[v2][v1] = 0

    def print(self):
        print("Adj matrix : ")
        return [print(x) for x in self.adj_matrix]


def main():
    return


if __name__ == "__main__":
    main()