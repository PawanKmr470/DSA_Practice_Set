# REF : https://www.geeksforgeeks.org/python-program-for-binary-search/
#       https://www.programiz.com/dsa/binary-search
# NOTES :

# T: O(log n)
# S: O(1) for iterative
# S: O(log n) for recursive

class Solution:
    def binarySearch(self, arr, x):
        return self.__binarySearch(arr, x)

    def __binarySearch(self, arr, x):

        low = 0
        high = len(arr) - 1

        while low <= high:

            mid = low + (high - low) // 2

            if arr[mid] == x:
                return mid

            elif arr[mid] < x:
                low = mid + 1

            else:
                high = mid - 1

        return -1

    def binarySearchRec(self, arr, x):
        return self.__binarySearchRec(arr, x, 0, len(arr) - 1)

    def __binarySearchRec(self, arr, x, low, high):

        if low <= high:

            mid = low + (high - low) // 2

            if arr[mid] == x:
                return mid

            elif arr[mid] < x:
                return self.__binarySearchRec(arr, x, mid + 1, high)
            else:
                return self.__binarySearchRec(arr, x, low, mid - 1)

        else:
            return -1


def main():
    arr = [ 2, 3, 4, 10, 40 ]
    x = 10
    print("Index : {}".format(Solution().binarySearch(arr, x)))
    print("Index : {}".format(Solution().binarySearchRec(arr, x)))

if __name__ == "__main__":
    main()