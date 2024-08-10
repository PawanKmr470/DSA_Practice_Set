#include <iostream>
#include <queue>
using namespace std;

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

class BFS {
    private:
        Node* root;
    public:
        BFS() { root = NULL; }
        ~BFS() {};

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

        void printLevelOrder_Itr() {
            if (root == NULL) { return; }

            queue<Node*> q;
            q.push(root);
            Node* cur;
            while (!q.empty()) {
                cur = q.front(); q.pop();
                cout << cur->data << " ";

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            cout << endl;
        }

        // Recursive way requires height calculation, try.
};

int main() {

    BFS d;
    d.insertNonRec(50);
    d.insertNonRec(60);
    d.insertNonRec(40);
    d.insertNonRec(45);
    d.insertNonRec(30);
    d.insertNonRec(65);
    d.insertNonRec(55);

    cout << "Level Order Itr : ";
    d.printLevelOrder_Itr();
    
    return 0;
}