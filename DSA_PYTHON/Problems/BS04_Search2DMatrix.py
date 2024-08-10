# REF : https://leetcode.com/problems/search-a-2d-matrix/
# NOTES :
#       Binary search in ROWS then Binary search in column

# T: O(logm * logn)
# S: O(1)
class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        ROWS = len(matrix)
        COLS = len(matrix[0])

        mid = None
        start = 0
        end = ROWS - 1

        while start <= end:
            mid = start + (end - start) // 2
            if target < matrix[mid][0]:
                end = mid - 1
            elif target > matrix[mid][-1]:
                start = mid + 1
            else:
                break

        if start > end:
            return False

        # now mid variable has row in which the element is present
        found_row = mid

        left = 0
        right = COLS - 1
        while left <= right:
            mid = left + (right - left) // 2
            if target == matrix[found_row][mid]:
                return True
            if target < matrix[found_row][mid]:
                right = mid - 1
            else:
                left = mid + 1

        return False

def main():
    matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    target = 3
    print("output : {}".format(Solution().searchMatrix(matrix, target)))

if __name__ == "__main__":
    main()