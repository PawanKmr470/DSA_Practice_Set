#include <iostream>
using namespace std;

// # REF : https://leetcode.com/problems/invert-binary-tree/
// # NOTES :
// #       Just preorder traversal and swap the elements
// #       Actually any order traversal works
// O(T) : O(n)
// O(S) : O(h) Height of the tree if stack is considered.
//              This represents the maximum depth of the recursive call stack.
//              Best case  : O(log n) for balanced tree
//              Worst case : O(n) for skewed tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Swapping elements & calling method recursively.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Creating callstack, going to the leaf nodes
// and swapping while returning.
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        invertTree(root->left);
        invertTree(root->right);

        swap(root->left, root->right);

        return root;
    }
};