# REF : https://leetcode.com/problems/encode-and-decode-strings/
# NOTES :
#       Format of encoded string : <string_len> <delimiter> <string>
#       Example : 5#Hello 3#cat 5#Don#1

# T: O(n)
# S: O(n)

class Codec:
    def encode(self, strs: list[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        res = ""
        for s in strs:
            res = res + str(len(s)) + "#" + s
        return res

    def decode(self, s: str) -> list[str]:
        """Decodes a single string to a list of strings.
        """
        res, i = [], 0
        while i < len(s):
            j = i
            while s[j] != "#":
                j += 1
            word_len = int(s[i:j])
            res.append(s[j+1 : j+1 + word_len])
            i = j+1 + word_len

        return res

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))


def main():
    pass

if __name__ == "__main__":
    main()