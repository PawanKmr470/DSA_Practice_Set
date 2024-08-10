#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// NOTES :
//      Apply DFS and in each call if node val is > than it's ascendants
//      then update the max_val with node->val and increase the count.

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

// T: O(n)
// S: O(n)
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, root->val, count);
        return count;
    }

    void dfs(TreeNode* node, int max_val, int& count) {
        if (!node)
            return;

        if (node->val >= max_val) {
            count++;
            max_val = node->val;
        }

        if (node->left)
            dfs(node->left, max_val, count);

        if (node->right)
            dfs(node->right, max_val, count);
    }
};