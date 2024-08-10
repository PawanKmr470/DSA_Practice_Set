# REF : https://leetcode.com/problems/top-k-frequent-elements/description/
# NOTES :
#       1st Approach : frequency Hashmap and sort it but O(nlogn)
#       2nd Approach : Max Heap of size k (push/pop is O(log n))
#           2 ways ->
#           a) Add all element in list (Max Heap) and heapify the list which is O(n).
#               then pop k elements that's the answer O(k * logn)
#               Overall O(n + klogn)
#           b) Keep adding element in Max Heap but keep it's size limited to k
#               that means add/push O(n * logk) and pop (n-k) if size goes beyond k
#               that's O( (n-k)logk )
#               Overall O( nlogk + (n-k)logk ) ~ O( (n-k)logk )
#       3rd Approach : Bucket Sort
#           where array index is frequency count and values is a list of those elements
#           which occur index times.
#           Overall T: O(n) & S: O(n) space is of len of input array len
#           [1,1,1,2,2,3] here bucket len will be 6 because an element can repeat max 6 times.

# T: O(n)
# S: O(n)

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        count = {}
        freq = [[] for i in range(len(nums) + 1)]

        for n in nums:
            count[n] = 1 + count.get(n, 0)
        for n, c in count.items():
            freq[c].append(n)

        res = []
        for i in range(len(freq) - 1, -1, -1):
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res
        return res  # This line is not required as per contraints given

def main():
    print("output : {}".format(Solution().topKFrequent([1,1,1,2,2,3], 2)))
    print("output : {}".format(Solution().topKFrequent([1], 1)))

if __name__ == "__main__":
    main()