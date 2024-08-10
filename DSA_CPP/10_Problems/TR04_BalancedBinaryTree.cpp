#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/balanced-binary-tree/solution/
// NOTES :
//     1 way - calculate the heights of left and right subtrees and compare the result
//             need to implement height function. Total O(n^2). Top down approach
//     2 way - go to the leaves and while rolling back compare heights and return
//             return -1 if not balanced else return height of subtrees
// T: O(n^2)
// S: O(H^2) for balanced tree OR O(n^2) for skew tree case

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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int lh = height(root->left);    // time consuming
        int rh = height(root->right);
        if (abs(lh - rh) > 1)
            return false;

        return isBalanced(root->left) and isBalanced(root->right);
    }

    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;
        
        return 1 + max(height(node->left), height(node->right));
    }
};

// O(T) : O(n)
// O(S) : O(h)
class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        return height(root) != -1;
    }

    int height(TreeNode* node) {
        if (node == nullptr)                // line 1
            return 0;

        int lh = height(node->left);        // line 2
        if (lh == -1) return -1;                // line 6
        
        int rh = height(node->right);       // line 3
        if (rh == -1) return -1;                // line 7

        if (abs(lh - rh) > 1)               // line 4
            return -1;

        return 1 + max(lh, rh);             // line 5
    }
};