#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// NOTES :
//      In BST, left < root < right
//      This is InOrder traversal. Get InOrder array and return kth element.
//      Check the Iterative method. Same logic.

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sort_list;
        InOrder(root, sort_list);
        return sort_list[k-1];
    }

    void InOrder(TreeNode* node, vector<int>& sort_list) {
        if (node == nullptr) return;

        InOrder(node->left, sort_list);
        sort_list.push_back(node->val);
        InOrder(node->right, sort_list);
    }
};