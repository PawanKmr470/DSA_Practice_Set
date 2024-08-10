#include <iostream>
#include <unordered_map>
using namespace std;

// REF : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// NOTES :
//      PreOrder list's first element is the root.
//      same root's position in InOrder list will tell all elements going into
//      left subtree & right subtree.
//      Create hashmap for Inorder list because everytime we would need to find out
//      that root node in the list.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = helper(preorder, 0, preorder.size()-1,
                                inorder, 0, inorder.size()-1, mp);
        return root;
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int,int>& mp) {

        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int mid = mp[root->val];
        int numsLeft = mid - inStart;

        root->left = helper(preorder, preStart + 1, preStart + numsLeft,
                            inorder, inStart, mid - 1, mp);

        root->right = helper(preorder, preStart + numsLeft + 1, preEnd,
                            inorder, mid + 1, inEnd, mp);

        return root;
    }
};