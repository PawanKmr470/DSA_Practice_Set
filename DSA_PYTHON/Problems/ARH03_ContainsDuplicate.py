# REF : https://leetcode.com/problems/contains-duplicate/
# NOTES :
#       DS used : Set()
#       If element is duplicate then it will be present in hash set.

# T: O(n)
# S: O(n)

class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        hashset = set()
        for i in nums:
            if i in hashset:
                return True
            hashset.add(i)
        return False

def main():
    print("output : {}".format(Solution().containsDuplicate([1,2,3,1])))

if __name__ == "__main__":
    main()