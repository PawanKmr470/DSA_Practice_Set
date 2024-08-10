#include <iostream>
#include <unordered_map>
using namespace std;

// REF : https://leetcode.com/problems/find-duplicate-subtrees/description/
// NOTES :
//      Brute force way will give O(n^3) as find substree n, compare with other subtrees n,
//      do for each node n => O(n^3)
//      Better approach with O(n^2) - serialize each subtree with string and 
//      compare for duplicate (using Hash Set)
//      serialize can be PreOrder, InOrder or PostOrder traversal
//      "serialize key" : [tree1, tree2] if tree1 & tree2 are duplicate
//          string      : list of nodes

// T: O(n^2)
// S: O(n^2) due to Hash set while ignoring the recursion stack

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, vector<TreeNode*>> hashSet;
        PreOrder(root, hashSet, result);
        return result;
    }

    string PreOrder(TreeNode* node, unordered_map<string, vector<TreeNode*>> &hashSet,
                    vector<TreeNode*> &result) {

        if (node == nullptr)
            return "null";
        
        // value, left subtree , right subtree
        string root_str = to_string(node->val);
        string left_str = PreOrder(node->left, hashSet, result);
        string right_str = PreOrder(node->right, hashSet, result);

        string s = root_str + "," + left_str + "," + right_str;     // , delimiter is required.

        if (hashSet[s].size() == 1)
            result.push_back(node);

        hashSet[s].push_back(node);
        return s;
    }
};