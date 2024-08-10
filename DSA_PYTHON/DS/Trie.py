# REF : https://leetcode.com/problems/implement-trie-prefix-tree/
# NOTES :
#       Also known as Prefix Tree
#       Each trie node object has dict {'a': &obja, 'b': &objb,...}
#       letter is key in dict and value is address of next trie node

# T: O(m), m is key length. And SEARCHING for a key in balanced tree - O(m * logn)
# S: O(m)

class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        cur = self.root
        for i in word:
            if i not in cur.children:
                cur.children[i] = TrieNode()
            cur = cur.children[i]
        cur.endOfWord = True

    def search(self, word):
        cur = self.root
        for i in word:
            if i not in cur.children:
                return False
            cur = cur.children[i]
        return cur.endOfWord

    def startswith(self, prefix):
        cur = self.root
        for i in prefix:
            if i not in cur.children:
                return False
            cur = cur.children[i]
        return True


def main():
    t = Trie()
    t.insert("apple")
    t.insert("ape")
    print("search : {}".format(t.search("apple")))
    print("search : {}".format(t.search("ape")))
    print("search : {}".format(t.search("grapes")))
    print("search : {}".format(t.startswith("api")))

if __name__ == "__main__":
    main()