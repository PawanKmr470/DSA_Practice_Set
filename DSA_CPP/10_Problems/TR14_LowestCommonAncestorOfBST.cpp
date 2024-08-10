#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
// NOTES :
//       Common ancestor - closest parent/grand parent which is connecting the given nodes p and q
//       we are not checking q is where and q is where, instead we are checking that
//       on what conditions this parent/grand parent will be on left or right or they are at left/right
//       from the current node i.e. split condition
//       In Short : if pq both are left then cur node is not ancestor.
//                  if pq both are right then cur node is not ancestor.
//                  if one is on left and other is on right (p & q),
//                  then cur node is the common ancestor (answer).

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
// S: O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (!cur) {
            if (p->val > cur->val && q->val > cur->val)
                cur = cur->right;
            else if (p->val < cur->val && q->val < cur->val)
                cur = cur->left;
            else
                return cur;
        }
        return nullptr;
    }
};