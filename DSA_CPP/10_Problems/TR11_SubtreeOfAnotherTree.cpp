#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/subtree-of-another-tree/
// NOTES :
//      First we need to have a function to compare two trees if they are equal.
//      Need to start comparing with both the root (with a compare function)
//      If roots mismatch then recursively go left & right for comparision.

// T: O(n^2)
// S: O(n^2)

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        if (subRoot == nullptr) return true;

        if (sameTree(root, subRoot))
            return true;

        // Oneliner for below
        // return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        if (isSubtree(root->left, subRoot))
            return true;
        if (isSubtree(root->right, subRoot))
            return true;

        return false;
    }

    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        if (root && subRoot && root->val == subRoot->val)
            return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
        return false;
    }
};