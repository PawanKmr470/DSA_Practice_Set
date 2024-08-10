#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/path-sum/description/
// NOTES :
//       While doing DFS, keep on summing nodes.
//       If at leaf node (means it's left & right childs are NULL) sum == targetSum
//       return true (return from the recursion logic)
//       function returns ture if either of left or right subtree tree returns true else false
// T: O(n)
// S: O(h)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return helper(root, sum, targetSum);
    }

    bool helper(TreeNode* node, int sum, int& targetSum) {
        if (node == NULL) {
            return false;
        }

        sum += node->val;
        if (node->left == NULL && node->right == NULL && sum == targetSum)
            return true;

        bool lb = helper(node->left, sum, targetSum);
        bool rb = helper(node->right, sum, targetSum);

        if (lb || rb)
            return true;
        else
            return false;
    }
};