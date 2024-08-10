#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/binary-tree-maximum-path-sum/
// NOTES :
//       Run DFS & while rolling back calculate max sum so far and store it in a max_sum variable.
//       max_sum will be -> max including this current node OR excluding this current node
//       (i.e. max_sum so far) -> max(maxSum, node.val + left_max + right_max)
//       while returning, it will return including current node val + max so far
//       (i.e. max(left_max,right_max)
//       Concept similar to Diameter of Binary Tree.

// T: O(n)
// S: O(n)

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

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }

    int dfs(TreeNode* node, int& max_sum) {
        if (node == nullptr) return 0;

        int left_max = dfs(node->left, max_sum);
        int right_max = dfs(node->right, max_sum);

        // We use max(gain_from_left_subtree, 0) because we want to consider 
        // the gain only if it is positive. If it is negative, 
        // we ignore it or consider it as zero.
        left_max = max(left_max, 0);
        right_max = max(right_max, 0);

        max_sum = max(max_sum, node->val + left_max + right_max);

        return node->val + max(left_max, right_max);
    }
};