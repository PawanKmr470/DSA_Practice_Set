# REF : https://leetcode.com/problems/find-all-anagrams-in-a-string/
# NOTES :
#       Sliding window technique.
#       Window is of anagram string's length. Create hashmap of
#       frequencies of each character and update hashmap as left and right
#       pointer is moving.

# T: O(n)
# S: O(k) where k = 26 due to a-z

class Solution:
    def findAnagrams(self, s: str, p: str) -> list[int]:
        if len(s) < len(p): return []

        s_count, p_count = {}, {}
        for i in range(len(p)):     # making both hashmaps equal to start
            p_count[p[i]] = 1 + p_count.get(p[i], 0)
            s_count[s[i]] = 1 + s_count.get(s[i], 0)

        res = [0] if p_count == s_count else []
        l = 0
        for r in range(len(p), len(s)):
            s_count[s[r]] = s_count.get(s[r], 0) + 1
            s_count[s[l]] = s_count[s[l]] - 1

            if s_count[s[l]] == 0:
                s_count.pop(s[l])

            l += 1

            if s_count == p_count:
                res.append(l)

        return res


def main():
    print("output : {}".format(Solution().findAnagrams("cbaebabacd", "abc")))

if __name__ == "__main__":
    main()