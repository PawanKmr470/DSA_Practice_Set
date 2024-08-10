#include <iostream>
using namespace std;

// Having last instead of head gives advantage of adding node at begining and
// at the end in constant time.

class Node {
public:
    int data;
    Node *next;

    Node () {
        data = 0;
        next = nullptr;
    }
    Node (int val) {
        data = val;
        next = nullptr;
    }
};

class singlyCircular {
private:
    Node *head;
public:
    singlyCircular() { head = nullptr; }
    ~singlyCircular() {};

    void insertBegin(int val) {
        Node *temp = new Node(val);

        if (head == nullptr) {
            head = temp;
            temp->next = head;      // temp->next = temp;   is also fine
            return;
        }

        Node *cur = head;               // Traversing to last node because we want to point
        while (cur->next != head) {     // last node to head
            cur = cur->next;
        }
        cur->next = temp;       // update last node then
        temp->next = head;      // update first node
        head = temp;            // make first node head

    }

    void printLL() {
        if (head == nullptr) return;

        Node *cur = head;
        while (cur->next != head) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << cur->data << " ";   // while loop will always skip last element
                                    // and for 1 element while loop won't run.
        cout << endl;
    }

    void insertEnd(int val) {
        Node *temp = new Node(val);

        if (head == nullptr) {
            temp->next = temp;
            head = temp;
            return;
        }

        Node *cur = head;
        while (cur->next != head) {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = head;
    }
};

int main() {
    singlyCircular l;
    l.insertBegin(1);
    l.insertBegin(2);
    l.insertBegin(3);
    l.insertBegin(4);
    l.insertEnd(5);
    l.printLL();
}