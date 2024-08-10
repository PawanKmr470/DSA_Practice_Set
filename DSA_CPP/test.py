from collections import deque

class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])
        island = 0

        visited = set()
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in visited:
                    self.bfs(r, c, visited, grid, rows, cols)
                    island += 1

        return island

    def bfs(self, r, c, visited, grid, rows, cols):
        q = deque()
        q.append((r, c))
        visited.add((r, c))

        directions = [[1, 0], [0, 1], [0, -1], [-1, 0]]
        while q:
            row, col = q.popleft()
            for dr, dc in directions:
                x, y = row + dr, col + dc

                # if grid[x][y] == "1" and (x, y) not in visited and \
                #     x in range(rows) and y in range(cols):    # These conditions should be first

                if x in range(rows) and y in range(cols) and \
                    grid[x][y] == "1" and (x, y) not in visited:

                    q.append((x, y))
                    visited.add((x, y))


def main():
    grid1 = [
        ["1", "1", "1", "1", "0"],
        ["1", "1", "0", "1", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "0", "0", "0"]
    ]

    grid2 = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"]
    ]

    print("Number of islands : {}".format(Solution().numIslands(grid1)))
    print("Number of islands : {}".format(Solution().numIslands(grid2)))


if __name__ == "__main__":
    main()