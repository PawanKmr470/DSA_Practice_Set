#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

Node *reverse(Node *node) {
    if (node == nullptr || node->next == nullptr)
        return node;

    Node *newHead = reverse(node->next);
    node->next->next = node;
    node->prev = node->next;
    node->next = nullptr;
    return newHead;
}

Node *reverseItr(Node *node) {
    if (node == nullptr)
        return node;

    Node *cur = node;
    Node *temp = nullptr;
    
    while (cur) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
    
    if (temp)
        return temp->prev;
    else
        return node;
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
    head->prev = nullptr;
    
    // head->next = new Node(10);
    // head->next->prev = head;
    
    // head->next->next = new Node(15);
    // head->next->next->prev = head->next;
    
    // head->next->next->next = new Node(20);
    // head->next->next->next->prev = head->next->next;

    //    head = reverse(head);
    head = reverseItr(head);
    print(head);
    return 0;
}
