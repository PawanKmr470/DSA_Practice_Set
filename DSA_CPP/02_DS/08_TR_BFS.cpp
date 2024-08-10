#include <iostream>
#include <queue>
using namespace std;

class Node {
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

class BFS
{
private:
    Node* head;
public:
    BFS(){ head = NULL; }
    ~BFS(){};
    void InsertNode(int);
    void PrintLevelOrder();
    void PrintLevelOrderRec();
    void PrintLevel(Node*, int);
    int Height(Node*);
};

void BFS::InsertNode(int val) {
    Node* temp = new Node(val);
    Node* cur = head;
    if (head == NULL) {
        head = temp;
        return;
    }
    queue<Node*> q;
    q.push(cur);
    while (q.size())
    {
        cur = q.front();
        q.pop();

        if (cur->left) {
            q.push(cur->left);
        }
        else {
            cur->left = temp;
            break;
        }

        if (cur->right) {
            q.push(cur->right);
        }
        else {
            cur->right = temp;
            break;
        }
    }
    return;
}

void BFS::PrintLevelOrder() {
    Node* cur = head;
    if (cur == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur->left) {
            q.push(cur->left);
        }
        if (cur->right) {
            q.push(cur->right);
        }
        cout << cur->data << " ";
    }
    cout << endl;
    return;
}

int BFS::Height(Node* head) {
    if (!head) return 0;
    return 1 + max(Height(head->left), Height(head->right));
}

void BFS::PrintLevel(Node* head, int level) {
    if (!head) return;
    if (level == 1) {
        cout << head->data << " ";
    }
    else {
        PrintLevel(head->left, level - 1);
        PrintLevel(head->right, level - 1);
    }
}

void BFS::PrintLevelOrderRec() {
    int h = Height(head);
    for (int i = 1; i <= h; i++) {
        PrintLevel(head, i);
    }
    cout << endl;
    return;
}

int main() {
    BFS b;
    b.InsertNode(1);
    b.InsertNode(2);
    b.InsertNode(3);
    b.InsertNode(4);
    b.InsertNode(5);
    b.InsertNode(6);
    b.InsertNode(7);
    b.PrintLevelOrder();
    b.PrintLevelOrderRec();
    return 0;
}
