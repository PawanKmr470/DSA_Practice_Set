#include <iostream>
using namespace std;

// so the idea is first update the next & prev pointer of the newly
// created node because they are not pointing anywhere

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

class doublyCircular {
private:
    Node *head;
public:
    doublyCircular() { head = nullptr; }
    ~doublyCircular() {};

    void insertBegin(int val) {
        Node *temp = new Node(val);

        if (head == nullptr) {
            temp->next = temp;
            temp->prev = temp;
            head = temp;
            return;
        }

        temp->next = head;          // first temp's next
        temp->prev = head->prev;    // then temp's prev
        head->prev->next = temp;    // update last node to point new first node
        head->prev = temp;          // update old first node's prev to point new first node
        head = temp;                // at last update head pointer
    }

    void printLL() {
        if (head == nullptr) return;

        Node *cur = head;
        while (cur->next != head) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << cur->data << " ";
        cout << endl;
    }

    void insertEnd(int val) {
        Node *temp = new Node(val);

        if (head == nullptr) {
            temp->next = temp;
            temp->prev = temp;
            head = temp;
            return;
        }

        temp->next = head;          // first temp's next
        temp->prev = head->prev;    // then temp's prev
        head->prev->next = temp;    // last node's next should be this temp node and
        head->prev = temp;          // first node's prev should be this temp node
    }
};

int main() {
    doublyCircular l;
    // l.insertEnd(0);
    l.insertBegin(1);
    l.insertBegin(2);
    l.insertBegin(3);
    l.insertBegin(4);
    l.insertEnd(5);
    l.printLL();
}