#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

// REF : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
// NOTES :
//       serialize - create unique string from tree
//       deserialize - create tree from the unique string
//       [123nullnull45] this can be interpreted as [1,23,null,null,45] or [12,3,null,null,45] etc
//       Hence delimiter is required.
//       Simple way to deserialize is use queue fromed with words from the string excluding delimiter
//       then create tree.
//       Use same traversal in both serialize & deserialize (preorder/inorder/postorder)
//       Improved approach in second solution using sstream class
//       Basically any traversal to make it into string & same traversal to make tree from string
//       Helpful links -
//          https://www.scaler.com/topics/split-string-in-cpp/
//          https://favtutor.com/blogs/split-string-cpp

//       Try Iterative methods...

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string result = "";
        shelper(root, result);
        return result;
    }

    void shelper(TreeNode* node, string& s) {
        if (node == NULL) {
            s += "N,";
            return;
        }

        s = s + to_string(node->val) + ",";
        shelper(node->left, s);
        shelper(node->right, s);
        return;
    }

    // string serialize(TreeNode* root) {
    //     if(!root) {
    //         return "NULL,";
    //     }
    //     return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    // }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string word = "";
        
        for(char &ch : data) {
            if (ch == ',') {
                q.push(word);
                word = "";
            }
            else
                word += ch;
        }

        if (word.size())
            q.push(word);

        return dhelper(q);
    }

    TreeNode* dhelper(queue<string>& q) {
        string s = q.front(); q.pop();
        if (s == "N")
            return NULL;

        TreeNode* node = new TreeNode(stoi(s));
        node->left = dhelper(q);
        node->right = dhelper(q);

        return node;
    }
};


// Optimized by using stringstream class 
// istringstream and ostringstream works with space separated.
// how it works with delimiters ?
// Same complexity

class Codec1 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        // Create an output string stream to store serialized data
        ostringstream temp;
        shelper(root, temp);

        // Convert the output string stream to a string and return
        return temp.str();
    }

    void shelper(TreeNode* node, ostringstream& s) {
        if (node == NULL) {
            s << "N ";                              // <<---- Space is added
            return;
        }

        s << node->val << " ";
        shelper(node->left, s);
        shelper(node->right, s);
        return;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Create an input string stream to read serialized data
        istringstream temp(data);

        return dhelper(temp);
    }

    TreeNode* dhelper(istringstream& s) {

        string word = "";
        // Read the next value from the input string stream
        s >> word;

        if (word == "N")                           // <<---- Space is NOT added
            return NULL;

        TreeNode* node = new TreeNode(stoi(word));
        node->left = dhelper(s);
        node->right = dhelper(s);

        return node;
    }
};