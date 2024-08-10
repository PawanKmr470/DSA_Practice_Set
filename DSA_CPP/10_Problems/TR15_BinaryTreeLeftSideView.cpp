#include <iostream>
#include <queue>
using namespace std;

// REF : NA
// NOTES :
//      BFS with queue where queue's first element is required at each level
//      Another way - DFS (PreOrder) Root Left Right
//      Consider result's len is number of levels in the BT.
//      Add the node's val into result if node's level is > the len(result) otherwise skip
//      https://www.youtube.com/watch?v=IZ1asDkWg34

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
// S: O(D) Diameter of the tree
// BFS Approach
class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            TreeNode* node;
            for (int i=0; i < len; i++) {   
                node = q.front(); q.pop();

                if (i == 0) result.push_back(node->val);    // Add first element of the level

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return result;
    }
};

// T: O(n)
// S: O(n)
// DFS Approach
class Solution2 {
public:
    vector<int> leftSideView(TreeNode* root) {
        vector<int> result;
        preOrder(root, 1, result);
        return result;
    }

    void preOrder(TreeNode* node, int level, vector<int>& result) {
        if (!node) return;

        if (result.size() < level)
            result.push_back(node->val);

        preOrder(node->left, level + 1, result);    // left first
        preOrder(node->right, level + 1, result);
    }
};