#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node() {
            data = 0;
            next = nullptr;
            prev = nullptr;
        }
        Node(int val) {
            data = val;
            next = nullptr;
            prev = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() { head = nullptr; }
        ~LinkedList() {};

        void insertBegin(int val) {
            Node* temp = new Node(val);
            if (head != nullptr) {
                head->prev = temp;
                temp->next = head;
            }
            head = temp;
        }

        void printSLL() {
            if (head == nullptr) {
                cout << "Linked list is empty." << endl;
                return;
            }
            Node* cur = head;
            while(cur != nullptr) {
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << endl;
        }

        void reverse() {
            if (head == nullptr)
                return;
            
            Node* cur = head;
            Node* temp = nullptr;
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

            while (cur != nullptr) {
                temp = cur->prev;
                cur->prev = cur->next;
                cur->next = temp;
                cur = cur->prev;
            }
            if (temp != nullptr)
                head = temp->prev;
        }

        void reverseRec() {
            if (head == nullptr)
                return;
            
            Node* node = __reverseRec(head);
            node->next = nullptr;
            return;
        }
        Node* __reverseRec(Node* node) {
            if (node->next == nullptr) {
                head = node;
                head->prev = nullptr;
                return node;
            }

            Node* temp = __reverseRec(node->next);
            temp->next = node;
            node->prev = temp;
            return node;
        }
};

int main() {
    LinkedList l;
    l.insertBegin(5);
    l.insertBegin(10);
    l.insertBegin(15);
    l.insertBegin(20);
    l.insertBegin(25);
    l.printSLL();
    l.reverse();
    l.printSLL();
    l.reverseRec();
    l.printSLL();
    return 0;
}