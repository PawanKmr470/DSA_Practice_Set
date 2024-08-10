#include <iostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// typedef struct _Node {
//     int data;
//     _Node *left;
//     _Node *right;
// } Node, *pNode;
// works but everytime left, right = NULL will be performed which
// class implementation avoids.

// Node *temp = new Node;   // with struct
// temp->data = val;
// temp->left = NULL;
// temp->right = NULL;
// root = temp;

class Node {
    public:
    int data;
    Node *left, *right;

    // default ctor
    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    // Parameterized ctor
    Node(int val) {     // if val was data name then
        data = val;     // this->data = data;
        left = NULL;
        right = NULL;
    }
};

class DFS {
    private:
        Node *root;
    public:
        DFS() { root = NULL; }
        ~DFS() {};

        void insertNonRec(int val) {
            if (root == NULL) {
                root = new Node(val);
                return;
            }
            Node *cur = root;
            while (cur) {
                if (val < cur->data) {
                    if (cur->left == NULL) {
                        cur->left = new Node(val);
                        return;
                    }
                    cur = cur->left;
                }
                else {
                    if (cur->right == NULL) {
                        cur->right = new Node(val);
                        return;
                    }
                    cur = cur->right;
                }
            }
        }

        void insertRec(int val) {
            root = _insertRec(root, val);
            return;
        }

        Node* _insertRec(Node* node, int val) {
            if (node == NULL) {
                return new Node(val);
            }

            if (val < node->data) {
                node->left = _insertRec(node->left, val);
            }
            else {
                node->right = _insertRec(node->right, val);
            }
            return node;
        }

        // PRE ORDER
        void printPreOrder_Rec() {
            _printPreOrder_Rec(root);
            cout << endl;
        }

        void _printPreOrder_Rec(Node *root) {
            if (root == NULL) { return; }
            cout << root->data << " ";
            _printPreOrder_Rec(root->left);
            _printPreOrder_Rec(root->right);
        }

        void printPreOrder_Itr() {
            if (root == NULL) { return; }

            stack<Node*> st;                    // BFS is same code except Queue is used and
            st.push(root);
            while (!st.empty()) {
                Node* cur = st.top();
                st.pop();
                cout << cur->data << " ";

                if (cur->right) {               // We push right node first becuase we want to pop left first.
                    st.push(cur->right);        // In BFS, first left then right
                }
                if (cur->left) {
                    st.push(cur->left);
                }
            }
            cout << endl;
        }

        // IN ORDER
        void printInOrder_Rec() {
            _printInOrder_Rec(root);
            cout << endl;
        }

        void _printInOrder_Rec(Node* node) {
            if (node == NULL) { return; }
            _printInOrder_Rec(node->left);
            cout << node->data << " ";
            _printInOrder_Rec(node->right);
        }

        void printInOrder_Itr() {
            if (root == NULL) { return; }

            stack<Node*> st;
            Node* cur = root;
            while ((!st.empty()) || cur != NULL) {      // cur != NULL is extended 
                if (cur != NULL) {
                    st.push(cur);
                    cur = cur->left;
                }
                else {
                    cur = st.top();
                    st.pop();
                    cout << cur->data << " ";
                    cur = cur->right;
                }
            }
            cout << endl;
        }

        // POST ORDER
        void printPostOrder_Rec() {
            _printPostOrder_Rec(root);
            cout << endl;
        }

        void _printPostOrder_Rec(Node* node) {
            if (node == NULL) { return; }
            _printPostOrder_Rec(node->left);
            _printPostOrder_Rec(node->right);
            cout << node->data << " ";
        }

        // post order iterative - multiple solutions
        // Simple ones - Two stacks, stack + hashset (visited set),
        //                  Parent hashmap <child_node, parent_node>
        // difficult ones - One stack, Morris Traversal (no stack)

        // Using visited hashset
        void printPostOrder_Itr1() {
            if (root == NULL) { return; }

            unordered_set<Node*> visited;
            Node* cur = root;
            while ((cur != NULL) && (visited.find(cur) == visited.end())) {
                if ((cur->left != NULL) && visited.find(cur->left) == visited.end()) {
                    cur = cur->left;
                }
                else if ((cur->right != NULL) && visited.find(cur->right) == visited.end()) {
                    cur = cur->right;
                }
                else {
                    cout << cur->data << " ";
                    visited.insert(cur);
                    cur = root;     // due to this worst time complexity - O(n^2)
                }
            }
            cout << endl;
        }

        // Using parent hashmap
        void printPostOrder_Itr2() {
            if (root == NULL) { return; }
            
            unordered_map<Node*, Node*> pMap;
            // pMap.insert(make_pair(root, nullptr));
            pMap.insert(pair<Node*, Node*>(root, NULL));
            Node* cur = root;
            while (cur != NULL) {
                if ((cur->left != NULL) && (pMap.find(cur->left) == pMap.end())) {
                    pMap.insert(make_pair(cur->left, cur));
                    cur = cur->left;
                }
                else if ((cur->right != NULL) && (pMap.find(cur->right) == pMap.end())) {
                    pMap.insert(make_pair(cur->right, cur));
                    cur = cur->right;
                }
                else {
                    cout << cur->data << " ";
                    cur = pMap.find(cur)->second;
                }
            }
            cout << endl;
        }

        // Using two stacks
        void printPostOrder_Itr3() {
            if (root == NULL) { return; }

            stack<Node*> s1, s2;
            s1.push(root);
            Node* cur;

            while (!s1.empty()) {
                cur = s1.top();
                s1.pop();                       // Pop from stack 1
                s2.push(cur);                   // Push into stack 2

                if (cur->left != NULL) {        // Rest logic is similar to PreOrder *************
                    s1.push(cur->left);         // Except stack 2 is printed after this while loop
                }                               // And that is the answer
                if (cur->right != NULL) {       // In PreOrder - first RIGHT then LEFT
                    s1.push(cur->right);        // In PostOrder  - first LEFT then RIGHT 
                }                               // In LevelOrder - first LEFT then RIGHT
            }

            // print the second stack from the top
            while (!s2.empty()) {
                cur = s2.top();
                s2.pop();
                cout << cur->data << " ";
            }
            cout << endl;
        }
};

int main() {

    DFS d;
    d.insertNonRec(50);
    d.insertNonRec(60);
    d.insertNonRec(40);
    d.insertNonRec(45);
    d.insertNonRec(30);
    d.insertNonRec(65);
    d.insertNonRec(55);

    cout << "Pre Order Rec : ";
    d.printPreOrder_Rec();
    cout << "Pre Order Itr : ";
    d.printPreOrder_Itr();
    cout << "In Order Rec : ";

    d.printInOrder_Rec();
    cout << "In Order Itr : ";
    d.printInOrder_Itr();
    cout << "Post Order Rec : ";
    
    d.printPostOrder_Rec();
    cout << "Post Order Itr1 : ";
    d.printPostOrder_Itr1();
    cout << "Post Order Itr2 : ";
    d.printPostOrder_Itr2();
    cout << "Post Order Itr3 : ";
    d.printPostOrder_Itr3();
    return 0;
}