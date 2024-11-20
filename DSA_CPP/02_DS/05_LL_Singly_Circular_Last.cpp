#include <iostream>
using namespace std;

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
    Node *last;
public:
    singlyCircular() { last = nullptr; }
    ~singlyCircular() {};

    void insertBegin(int val) {
        Node *temp = new Node(val);

        if (last == nullptr) {
            temp->next = temp;
            last = temp;
            return;
        }
                                    // last node's next will give the address of start node
        temp->next = last->next;    // temp->next should point to start and start is last->next
        last->next = temp;          // last node should point to newly added node at the start
    }

    void printLL() {
        if (last == nullptr) return;

        Node *cur = last->next;             // just head is now last->next. Rest is same.
        while (cur->next != last->next) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << cur->data << " ";
        cout << endl;
    }

    void insertEnd(int val) {
        Node *temp = new Node(val);

        if (last == nullptr) {
            temp->next = temp;
            last = temp;
            return;
        }

        temp->next = last->next;    // temp should point where last node is pointing
        last->next = temp;          // add temp node after the last node
        last = temp;                // update the 'last' pointer to point last node    >>>> ONLY THIS LINE IS DIFFERENT FROM insertBegin() rest is same.
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