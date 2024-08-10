#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/diameter-of-binary-tree/
// NOTES :
//      while stack unwinding, calculate height of the node and just before that
//      keep storing the max result

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// T: O(n^2)
// S: O(n^2)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int left_dia = diameterOfBinaryTree(root->left);
        int right_dia = diameterOfBinaryTree(root->right);

        int cur = height(root->left) + height(root->right);

        return max(cur, max(left_dia, right_dia));
    }

    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};


// T: O(n)
// S: O(n)
class Solution1 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        height(root, result);
        return result;
    }

    int height(TreeNode* node, int& result) {
        if (node == nullptr) return 0;

        int lh = height(node->left, result);
        int rh = height(node->right, result);

        result = max(result, lh + rh);

        return 1 + max(lh, rh);
    }
};