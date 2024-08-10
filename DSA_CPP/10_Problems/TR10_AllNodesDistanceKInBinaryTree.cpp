#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// REF : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// NOTES : 
//      Steps for this solution -
//      1st Solution -
//      	Find node address if not given (Optional)
//      	Create node : parent Hashmap (DFS)
//      	Apply BFS with visited set        (BFS)
//      2nd Solution -
//      	Convert this tree to graph
//      	DFS with visit set till depth k

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// T: O(n)
// S: O(n)
class Solution {
public:

    // For creating node : parent Hashmap
    void dfs(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (node == nullptr) return;

        if (node->left) mp[node->left] = node;
        if (node->right) mp[node->right] = node;

        dfs(node->left, mp);
        dfs(node->right, mp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentHash;
        dfs(root, parentHash);

        vector<int> result;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        // Need to start BFS from the target node
        // NOTE : Usually while(len--)/for loop is not required in bfs
        //        Only put here because we want to identify each level
        
        q.push(target);
        while (!q.empty()) {
            int len = q.size();
            while (len--) {                             // for loop also fine
                TreeNode* node = q.front(); q.pop();
                visited[node] = true;

                // At k==0 level, all nodes will be added to the result
                if (k==0) result.push_back(node->val);

                if (parentHash.find(node) != parentHash.end() &&
                    visited[parentHash[node]] == false)
                    q.push(parentHash[node]);

                if (node->left && visited[node->left] == false)
                    q.push(node->left);

                if (node->right && visited[node->right] == false)
                    q.push(node->right);
            }
            k--;
            if (k < 0) break;
        }

        return result;
    }
};

// T: O(n)
// S: O(n)
class Solution {
public:

    // Converting Tree into Graph
    // directed acyclic graph to undirected acyclic graph
    void dfs(TreeNode* node, unordered_map<TreeNode*, vector<TreeNode*>>& g) {
        if (node == nullptr) return;

        if (node->left) {
            g[node].push_back(node->left);
            g[node->left].push_back(node);
        }
        if (node->right) {
            g[node].push_back(node->right);
            g[node->right].push_back(node);
        }

        dfs(node->left, g);
        dfs(node->right, g);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        dfs(root, graph);

        vector<int> result;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        // Need to start BFS from the target node
        q.push(target);
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                TreeNode* node = q.front(); q.pop();
                visited[node] = true;

                // At k==0 level, all nodes will be added to the result
                if (k==0) result.push_back(node->val);

                for (TreeNode* nei : graph[node])
                    if (visited[nei] == false)
                        q.push(nei);
            }
            k--;
            if (k < 0) break;
        }

        return result;
    }
};