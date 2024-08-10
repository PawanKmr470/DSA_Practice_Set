# REF : https://leetcode.com/problems/pacific-atlantic-water-flow/
# NOTES :
#       Run dfs from first row and first column to find cells from where water can flow to pacific
#       Run dfs from last row and last column to find cells from where water can flow to atlantic
#       Common visited cells from pacific visited and atlantic visited will be the answer

# T: O(M*N)
# S: O(M*N)

class Solution:
    def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:
        rows, cols = len(heights), len(heights[0])
        pac_visit, atl_visit = set(), set()

        def dfs(r, c, visit):
            visit.add((r,c))

            dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
            for dr, dc in dirs:
                new_r, new_c = r + dr, c + dc

                if (new_r,new_c) not in visit and \
                        new_r >= 0 and new_c >= 0 and new_r < rows and new_c < cols and \
                        heights[r][c] <= heights[new_r][new_c]:

                    dfs(new_r, new_c, visit)


        for c in range(cols):
            dfs(0, c, pac_visit)            # dfs from top row for pacific
            dfs(rows - 1, c, atl_visit)     # dfs from last row for atlantic

        for r in range(rows):
            dfs(r, 0, pac_visit)            # dfs from left most col for pacific
            dfs(r, cols - 1, atl_visit)     # dfs from right most col for atlantic

        result = []
        for r in range(rows):
            for c in range(cols):
                if (r,c) in pac_visit and (r,c) in atl_visit:
                    result.append([r,c])

        return result


def main():
    heights = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
    print("output : {}".format(Solution().pacificAtlantic(heights)))

if __name__ == "__main__":
    main()
