#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// REF : https://leetcode.com/problems/binary-tree-maximum-path-sum/
// NOTES :
//       Apply DFS & while returning back find max and returning it with +1 for current node.

// T: O(n)
// S: O(h)

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
    int maxDepth(TreeNode* root) {

        if (root == nullptr) return 0;

        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);

        return 1 + max(left_max, right_max);

        // return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// T: O(n)
// S: O(h)
// DFS Iterative
// Notes :
//      After popping the element, compare the max lenght
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int result = 1;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});

        while (!s.empty()) {

            pair<TreeNode*, int> front = s.top();
            s.pop();

            result = max(result, front.second);

            if (front.first->left)
                s.push({front.first->left, front.second + 1});

            if (front.first->right)
                s.push({front.first->right, front.second + 1});
        }
        return result;
    }
};

// T: O(n)
// S: O(n)
// BFS Iterative
// Notes :
//      After visiting each level, increment the counter.
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int result = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            result++;
            int s = q.size();
            for (int i=0; i < s; i++) {         // directly using q.size() here gives wrong output
                TreeNode* node = q.front();     // because q lenght is getting changed during iteration.
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return result;
    }
};