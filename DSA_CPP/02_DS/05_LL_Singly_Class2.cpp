#include <iostream>
using namespace std;

// We can maintain "last" pointer as well to improve O(n) to O(1) for Delete from end.

class Node {
public:
    int data;
    Node *next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int val) {
        data = val;
        next = NULL;
    }
    ~Node() {};
};

class SinglyLL {
private:
    Node *head;
    Node *last;
public:
    SinglyLL() { head = NULL; }
    
    void InsertBegin(int val) {
        Node *temp = new Node(val);
        if (head == NULL) {
            head = temp;
            last = temp;
            return;
        }
        temp->next = head;
        head = temp;
        return;
    }
    
    void InsertEnd(int val) {
        Node *temp = new Node(val);
        if (head == NULL) {
            head = temp;
            last = temp;
            return;
        }
        last->next = temp;
        last = temp;
        return;
    }
    
    void Print(){
        if (head == NULL) {
            cout << "list is empty." << endl;
            return;
        }
        Node *cur = head;
        while(cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
        return;
    }

    void ReverseItr() {
        Node *cur = head;
        Node *prev = NULL;
        Node *temp = NULL;
        if (head == NULL)
            return;

        last = head;
        while(cur != NULL) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        head = prev;
        return;
    }
    
    void ReverseRec() {
        if(head == NULL) return;
        last = head;
        Node *node = helper(head);
        node->next = NULL;
        return;
    }

    Node *helper(Node *node) {
        if (node->next == NULL) {
            head = node;
            return node;
        }
        Node *temp = helper(node->next);
        temp->next = node;
        return node;
    }
};


int main() {
    SinglyLL s;
    s.InsertBegin(10);
    s.InsertBegin(20);
    s.InsertBegin(30);
    s.InsertEnd(40);
    s.Print();
    s.ReverseRec();
    s.Print();
    s.InsertBegin(5);
    s.InsertEnd(60);
    s.Print();
}
