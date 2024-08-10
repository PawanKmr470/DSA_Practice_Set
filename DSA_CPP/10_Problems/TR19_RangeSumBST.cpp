#include <iostream>
using namespace std;

//  REF : https://leetcode.com/problems/range-sum-of-bst/description/
//  NOTES :
//        if current node value is in the range then add that node with left & right tree call.
//        And if node val < low then right subtree might have bigger value than low and
//        if node val > high then left subtree might have smaller value than high.

//  O(T) : O(n) 
//  O(S) : O(h) In the worst case, the space complexity is proportional to the height of the tree.

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL)
            return 0;
        if (root->val > high)
            return rangeSumBST(root->left, low, high);
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        else
            return root->val + 
                    rangeSumBST(root->left, low, high) +
                    rangeSumBST(root->right, low, high);
    }
};