#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node () {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node (int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class doublyLL {
private:
    Node *head;
public:
    doublyLL () { head = nullptr; }
    ~doublyLL () {};

    void insertAtBegin(int val) {
        Node *temp = new Node(val);
        if (head != nullptr) {
            head->prev = temp;
            temp->next = head;
            // And temp's prev already has nullptr
        }
        head = temp;
    }

    void printDLL() {
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

        Node *cur = head;
        Node *temp;
        while (cur != nullptr) {
            temp = cur->prev;           // take backup of prev (not next's bcz prev will be required)
            cur->prev = cur->next;      // update prev pointer
            cur->next = temp;           // update next pointer
            cur = cur->prev;            // goto next node
        }
        // cur is null but temp still has previous node's address
        // previous node's prev pointer will point to the last node
        // why prev pointer bcz links are already reversed.

        if (temp != nullptr)    // temp will be null for 1 element case
            head = temp->prev;  // If 1 element is there, above while loop will run 1 time and
                                // will swap NULLs and this if condition won't be required.
                                // Understand this head = temp->prev

        // while (cur != nullptr) {
        //     temp = cur->next;
        //     cur->next = cur->prev;
        //     cur->prev = temp;
        //     cur = cur->prev;
        // }
        // Need to perform head = last node as cur has gone NULL
        // and temp will also have NULL.
        // with this approach, don't have previous node info
        // So temp = cur->prev would have worked
    }

    void reverseRec() {
        if (head == nullptr) return;
        Node *node = __reverse(head);
        node->next = nullptr;
    }

    Node *__reverse(Node *node) {
        if (node->next == nullptr) {
            head = node;
            head->prev = nullptr;           // Added line 1
            return node;
        }
        Node *temp = __reverse(node->next);
        temp->next = node;
        node->prev = temp;                  // Added line 2
        return node;
    }
};

int main() {
    doublyLL d;
    d.reverse();
    d.printDLL();
    d.insertAtBegin(1);
    d.reverse();
    d.printDLL();
    d.insertAtBegin(2);
    d.insertAtBegin(3);
    d.insertAtBegin(4);
    d.printDLL();
    d.reverse();
    d.printDLL();
    d.reverseRec();
    d.printDLL();
}