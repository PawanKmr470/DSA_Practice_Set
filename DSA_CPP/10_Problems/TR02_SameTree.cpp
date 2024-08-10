#include <iostream>
#include <string>
using namespace std;

// REF : https://leetcode.com/problems/same-tree/
// NOTES :
//     Base condition - If both p, q are null then they are same -> True
//     While traversing any of the node is None then return False
//     Check if the node value is not same then return False
//     call recursively to left right for both
// T: O(n)
// S: O(h) Tree height

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        
        if (p == nullptr || q == nullptr)
            return false;

        return p->val == q->val &&
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right);
    }
};

int main() {
    return 0;
}