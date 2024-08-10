#include <iostream>
using namespace std;

/*
Preorder, Inorder, Postorder => are the DFS algos of tree.
BFS using Queue
DFS using Stack
*/


class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~Node(){};
};

class DFS
{
private:
    Node* head;
public:
    DFS() { head = NULL; }
    ~DFS(){};

    void Insert(int);
    Node* Insert(Node*, int);
    void InsertRec(int);

    void PrintPreOrder();
    void PrintPreOrder(Node*);

    void PrintInOrder();
    void PrintInOrder(Node*);

    void PrintPostOrder();
    void PrintPostOrder(Node*);
};

Node* DFS::Insert(Node* node, int val){
    if (node == NULL){
        return new Node(val);
    }
    if (val < node->data){
        node->left = Insert(node->left, val);
    }
    else {
        node->right = Insert(node->right, val);
    }
    return node;
}

void DFS::Insert(int val){
    head = Insert(head, val);
    return;
}

// It's a BST insertion

void DFS::InsertRec(int val){
    if (head == NULL){
        head = new Node(val);
        return;
    }
    Node* cur = head;
    while (cur)
    {
        if (val < cur->data){
            if (cur->left == NULL){
                cur->left = new Node(val);
                return;
            }
            cur = cur->left;
        }
        else{
            if (cur->right == NULL){
                cur->right = new Node(val);
                return;
            }
            cur = cur->right;
        }
    }  
}

void DFS::PrintInOrder(Node* root){
    if (root == NULL){ return; }
    PrintInOrder(root->left);
    cout << root->data << " ";
    PrintInOrder(root->right);
}

void DFS::PrintInOrder(){
    PrintInOrder(head);
    cout << endl;
    return;
}

void DFS::PrintPreOrder(Node* root){
    if (root == NULL){ return; }
    cout << root->data << " ";
    PrintPreOrder(root->left);
    PrintPreOrder(root->right);
}

void DFS::PrintPreOrder(){
    PrintPreOrder(head);
    cout << endl;
    return;
}

void DFS::PrintPostOrder(Node* root){
    if (root == NULL){ return; }
    PrintPostOrder(root->left);
    PrintPostOrder(root->right);
    cout << root->data << " ";
}

void DFS::PrintPostOrder(){
    PrintPostOrder(head);
    cout << endl;
    return;
}

int main(){
    DFS d;
    d.InsertRec(50);
    d.InsertRec(60);
    d.InsertRec(40);
    d.InsertRec(45);
    d.InsertRec(30);
    d.InsertRec(65);
    d.InsertRec(55);
    cout << "Pre Order  : ";
    d.PrintPreOrder();
    cout << "In Order   : ";
    d.PrintInOrder();
    cout << "Post Order : ";
    d.PrintPostOrder();
    return 0;
}