# REF : https://leetcode.com/problems/valid-palindrome/description/
# NOTES :
#       1st Approach - reverse the string & compare it
#       2nd Approach - take 2 pointers & move inwards as going outwards would require
#                      to find the middle element which is cumbersum due to non-alphanumeric chars.

# T: O(n)
# S: O(n)
class Solution:
    def isPalindrome(self, s: str) -> bool:
        temp = ""
        for ch in s:
            if not ch.isalnum():
                continue
            temp += ch.lower()

        return temp == temp[::-1]

# T: O(n)
# S: O(n)
class Solution2:
    def isPalindrome(self, s: str) -> bool:
        # filter creates object with those elements for which lambda function returns true
        # it skips rest.
        alphanums = filter(lambda x: x.isalnum(), s)

        # map applies lambda function to all the elements of given list
        lowercase_s = map(lambda x: x.lower(), alphanums)

        lowercase_s = list(lowercase_s)
        return lowercase_s == lowercase_s[::-1]

# T: O(n)
# S: O(1)
class Solution3:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            while not s[l].isalnum() and l < r:
                l += 1
            while not s[r].isalnum() and l < r:
                r -= 1

            if s[l].lower() != s[r].lower():
                return False

            l += 1
            r -= 1

        return True


def main():
    s = "A man, a plan, a canal: Panama"
    print("output : {}".format(Solution().isPalindrome(s)))
    print("output : {}".format(Solution2().isPalindrome(s)))
    print("output : {}".format(Solution3().isPalindrome(s)))

if __name__ == "__main__":
    main()