# REF : https://leetcode.com/problems/valid-anagram/
# NOTES :
#       Hash map of character & their count
#       dict.get() is exception safe
#       sorting can also be done but O(nlogn)

# T: O(n)
# S: O(n)

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        hash_s, hash_t = {}, {}
        for i in range(len(s)):
            hash_s[s[i]] = hash_s.get(s[i], 0) + 1
            hash_t[t[i]] = hash_t.get(t[i], 0) + 1

        for c in hash_s:
            if hash_s[c] != hash_t.get(c, 0):
                return False

        return True

class Solution2:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        hashmap = {}
        for i in range(len(s)):
            hashmap[s[i]] = hashmap.get(s[i], 0) + 1    # increment +1 for char in hashmap
            hashmap[t[i]] = hashmap.get(t[i], 0) - 1    # decrement -1 for char in hashmap

        for ele in hashmap.values():    # all values(counts or occurances of char) of hashmap will be zero
            if ele:                     # if both strings are anagram of each other otherwise some non-zero
                return False            # will be there
        return True

def main():
    print("output : {}".format(Solution().isAnagram("anagram", "nagaram")))
    print("output : {}".format(Solution2().isAnagram("anagram", "nagaram")))

if __name__ == "__main__":
    main()