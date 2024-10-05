#include <iostream>
using namespace std;

struct Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node *reverse(Node *node) {
    if (node == nullptr || node->next == nullptr)
        return node;

    Node *newHead = reverse(node->next);
    node->next->next = node;
    node->next = nullptr;
    return newHead;
}

Node *reverseItr(Node *node) {
    if (node == nullptr)
        return node;

    Node *cur = node;
    Node *temp = nullptr;
    Node *prev = nullptr;
    
    while (cur) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    
    return prev;
}


void print(Node *head) {
    if (head == nullptr)
        return;

    Node *cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = new Node(20);
    head = reverse(head);
    print(head);
    return 0;
}
