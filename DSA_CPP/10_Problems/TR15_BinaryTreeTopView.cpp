#include <iostream>
#include <queue>
#include <map>
using namespace std;

// REF : NA
// NOTES :
//      BFS with queue having pair<node, level> and ordered map having pair<level, node>
//      if given level is not present in the map then add it otherwise skip it.

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
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;

        map<int, int> mp;               // level, node
        queue<pair<TreeNode*, int>> q;  // node, level
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front(); q.pop();
            TreeNode* node = it.first;
            int level = it.second;

            if (mp.find(level) == mp.end())
                mp[level] = node->val;

            if (node->left)
                q.push({node->left, level - 1});
            if (node->right)
                q.push({node->right, level + 1});
        }

        for (auto& it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};