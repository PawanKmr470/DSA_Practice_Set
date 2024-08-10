# REF : https://leetcode.com/problems/group-shifted-strings/description/
# NOTES :
#       circular Hashmap + modulus

# T: O(m*n)
# S: O(m*n)
import collections
class Solution:
    def groupStrings(self, strings: list[str]) -> list[list[str]]:
        def chardiff(s):
            ans = []
            prev_ch = None
            for ch in s:
                if not prev_ch:
                    prev_ch = ch
                    continue
                key = (ord(ch) - ord(prev_ch) + 26) % 26
                ans.append(key)
                prev_ch = ch
            return tuple(ans)

        hashmap = collections.defaultdict(list)
        for s in strings:
            chdiff = chardiff(s)
            hashmap[chdiff].append(s)

        return list(hashmap.values())

# T: O(m*n)
# S: O(m*n)
class Solution2:
    def groupStrings(self, strings: list[str]) -> list[list[str]]:
        hashmap = collections.defaultdict(list)
        for s in strings:
            key = ()
            for i in range(len(s) - 1):
                circular_difference = ( (ord(s[i+1]) - ord(s[i])) + 26 ) % 26
                key += (circular_difference,)   # making it string will give collision
            hashmap[key].append(s)              # ["abc"] & ["al"] both will give "11"
                                                # so tuple is best choice here
        return list(hashmap.values())

def main():
    print("output : {}".format(Solution().groupStrings(["abc","bcd","acef","xyz","az","ba","a","z"])))
    print("output : {}".format(Solution2().groupStrings(["abc","bcd","acef","xyz","az","ba","a","z"])))

if __name__ == "__main__":
    main()