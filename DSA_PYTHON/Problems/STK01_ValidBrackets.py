# REF : https://leetcode.com/problems/valid-parentheses/
# NOTES :
#       Hashmap + stack

# T: O(n)
# S: O(n)

from collections import deque

class Solution:
    def isValid(self, expn: str) -> bool:
        s = deque()
        hashmap = {'[':']', '{':'}', '(':')'}
        rev_hashmap = {']': '[', '}': '{', ')': '('}
        for i in range(len(expn)):
            if expn[i] in hashmap.keys():
                s.append(expn[i])
                continue
            if expn[i] in hashmap.values():
                if s and rev_hashmap[expn[i]] == s[-1]:
                    try:
                        s.pop()
                    except:
                        return False
                else:
                    return False

        return False if len(s) else True

    def isValid2(self, expn: str) -> bool:
        s = deque()
        hashmap = {']': '[', '}': '{', ')': '('}
        for i in range(len(expn)):
            if expn[i] in hashmap:
                if s:
                    if s.pop() != hashmap[expn[i]]:
                        return False
                else:
                    return False
            else:
                s.append(expn[i])

        return False if len(s) else True


if __name__ == "__main__":
    print(Solution().isValid("(]"))
    print(Solution().isValid2("(()()[{()}])"))
