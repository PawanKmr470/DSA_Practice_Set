#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    // Map to store children nodes
    std::unordered_map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode() : is_end_of_word(false) {} // Constructor initializing is_end_of_word
};

class Trie {
private:
    TrieNode* root; // Pointer to the root node

public:
    Trie() {
        root = new TrieNode(); // Initialize the root node
    }

    ~Trie() {
        // Destructor to free memory
        clear(root);
    }

    void clear(TrieNode* node) {
        for (auto& pair : node->children) {
            clear(pair.second); // Recursively clear children
        }
        delete node; // Delete the current node
    }

    // Function to insert a word into the Trie
    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode(); // Create new node if not present
            }
            current = current->children[ch]; // Move to the next node
        }
        current->is_end_of_word = true; // Mark the end of the word
    }

    // Function to search for a word in the Trie
    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false; // Character not found
            }
            current = current->children[ch]; // Move to the next node
        }
        return current->is_end_of_word; // Check if it's an end of a valid word
    }
};

int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("hello");
    trie.insert("hi");
    trie.insert("trie");
    trie.insert("tried");

    // Search for words in the Trie
    std::cout << "Search for 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 'hi': " << (trie.search("hi") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 'trie': " << (trie.search("trie") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 'tried': " << (trie.search("tried") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 'trial': " << (trie.search("trial") ? "Found" : "Not Found") << std::endl;

    return 0;
}
