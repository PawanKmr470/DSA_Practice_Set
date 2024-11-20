#include <iostream>
using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node() {
//         data = 0;
//         next = nullptr;
//     }
//     Node(int val) {
//         data = val;
//         next = nullptr;
//     }
// };

class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class singlyLL {
private:
    Node *head;
public:
    singlyLL() { head = nullptr; }
    ~singlyLL() {};                     // Deallocate whole list here

    void insertAtBegin(int val) {
        Node *temp = new Node(val);
        if (head != nullptr)
            temp->next = head;
        head = temp;
    }

    void printSLL() {
        if (head == nullptr) return;
        Node *cur = head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void reverse() {
        if (head == nullptr) return;

        // 3 Poiners
        Node *cur = head;
        Node *prev = nullptr;
        Node *temp;
        while (cur->next != nullptr) {
            temp = cur->next;           // take backup of next node
            cur->next = prev;           // make reverse link
            prev = cur;                 // update pre pointer first (bcz cur pointer will be update to it's next)
            cur = temp;                 // update cur pointer to it's next
        }
        cur->next = prev;   // a manual step
        head = cur;         // a manual step

        // Better to run loop till NULL
        // while(cur) {
        //     temp = cur->next;
        //     cur->next = prev;
        //     prev = cur;
        //     cur = temp;
        // }
        // head = prev;
    }

    void reverseRec() {
        if (head == nullptr) return;
        Node *node = __reverse(head);
        node->next = nullptr;
    }

    Node *__reverse(Node *node) {
        if (node->next == nullptr) {
            head = node;
            return node;
        }
        Node *temp = __reverse(node->next);
        temp->next = node;
        return node;
    }
};


int main() {
    singlyLL l;
    l.insertAtBegin(1);
    l.insertAtBegin(2);
    l.insertAtBegin(3);
    l.insertAtBegin(4);
    l.printSLL();
    l.reverse();
    l.printSLL();
    l.reverseRec();
    l.printSLL();
}