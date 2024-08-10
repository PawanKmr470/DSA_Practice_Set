#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/merge-two-binary-trees/
// NOTES :
//       preorder traversal
// T: O(n + m)
// S: O(nH + mH) if balanced or O(n + m) if skew

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;

        int n1 = 0;
        if (root1)
            n1 = root1->val;

        int n2 = 0;
        if (root2)
            n2 = root2->val;
        
        TreeNode* root = new TreeNode(n1 + n2);

        // Left child cases
        if (root1 && root2)
            root->left = mergeTrees(root1->left, root2->left);
        if (root1 == nullptr && root2)
            root->left = mergeTrees(nullptr, root2->left);
        if (root1 && root2 == nullptr)
            root->left = mergeTrees(root1->left, nullptr);

        // Right child cases
        if (root1 && root2)
            root->right = mergeTrees(root1->right, root2->right);
        if (root1 == nullptr && root2)
            root->right = mergeTrees(nullptr, root2->right);
        if (root1 && root2 == nullptr)
            root->right = mergeTrees(root1->right, nullptr);
        
        return root;
    }
};

// T: O(n + m)
// S: O(1)

class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        root1->val += root2->val;

        // Left child cases
        if (root1 && root2)
            root1->left = mergeTrees(root1->left, root2->left);
        if (root1 == nullptr && root2)
            root1->left = mergeTrees(nullptr, root2->left);
        if (root1 && root2 == nullptr)
            root1->left = mergeTrees(root1->left, nullptr);

        // Right child cases
        if (root1 && root2)
            root1->right = mergeTrees(root1->right, root2->right);
        if (root1 == nullptr && root2)
            root1->right = mergeTrees(nullptr, root2->right);
        if (root1 && root2 == nullptr)
            root1->right = mergeTrees(root1->right, nullptr);

        return root1;
    }
};

// T: O(n + m)
// S: O(1)
// Need to draw it why if condition with root2 is there ??

class Solution3 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        root1->val += root2->val;

        if (root2->left)
            root1->left = mergeTrees(root1->left, root2->left);
        if (root2->right)
            root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
    }
};

// T: O(n + m)
// S: O(1)

class Solution4 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if (!root1 && !root2) return nullptr;
        if (!root1) return root2;
        if (!root2) return root1;

        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
    }
};