#include <iostream>
using namespace std;

// we can have ctor dtor in struct also to behave like class.

typedef struct node {
    int data;
    struct node* next;
} Node;

class SinglyLL
{
private:
    Node* head;
    // int size; could help index related methods
public:
    SinglyLL() { head = NULL; }
    ~SinglyLL() {};

    void InsertAtBegin(int val) {
        Node* tmp = new Node;
        tmp->data = val;
        tmp->next = head;
        head = tmp;
    }

    void InsertAtEnd(int val) {
        Node* tmp = new Node;
        tmp->data = val;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            return;
        }

        Node* cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = tmp;
    }

    void Print() {
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void DeleteFromBegin() {
        if (head == NULL) { return; }

        Node* temp = head->next;
        delete head;
        head = temp;
    }

    void DeleteFromEnd() {
        if (head == NULL) { return; }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        
        Node *cur = head;
        while (cur->next->next != NULL) {
            cur = cur->next;
        }
        delete cur->next;
        cur->next = NULL;
        return;
    }

    void InsertAtIndex(int val, int index) {

        if (index <= 0) {
            cout << "Invalid position" << endl;
        }

        Node *temp = new Node;
        temp->data = val;
        temp->next = NULL;

        // two ways : 1 - maintain prev node
        //            2 - or just be at index - 1 position (used here)
        // need to handle index == 1 case separately

        if (index == 1) {
            temp->next = head;
            head = temp;
            return;
        }

        // if index == 2 then need to stay at head which is prev node
        Node *cur = head;
        while (index - 1 > 1) {
            if (cur->next != NULL) {
                cur = cur->next;
            }
            else {
                cout << "Invalid position" << endl;
                return;
            }
            index--;
        }

        // cur->next is NULL means we reached at last node but prev node was expected
        // and prev node's next is not NULL
        if (cur->next != NULL) {
            temp->next = cur->next;
            cur->next = temp;
        }
        else {
            cout << "Invalid position" << endl;
        }
        return;
    }

    void DeleteAtIndex(int index) {
        if (head == NULL) {
            cout << "List is empty" << endl;
        }

        if (index <= 0) {
            cout << "Invalid position" << endl;
        }

        Node *cur = head;
        if (index == 1) {
            cur = head->next;
            delete head;
            head = cur;
            return;
        }

        while (index - 1 > 1) {
            if (cur->next != NULL) {
                cur = cur->next;
            }
            else {
                cout << "Invalid position" << endl;
                return;
            }
            index--;
        }

        if (cur->next != NULL) {
            Node *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        else {
            cout << "Invalid position" << endl;
        }
        
        return;
    }

    void InsertAtIndex_using_prev(int val, int index) {

        if (index <= 0) {
            cout << "Invalid position" << endl;
        }

        Node *temp = new Node;
        temp->data = val;
        temp->next = NULL;

        if (index == 1) {
            temp->next = head;
            head = temp;
            return;
        }

        Node *pre = head;
        Node *cur = head;
        while (index > 1) {
            if (cur != NULL) {
                pre = cur;
                cur = cur->next;
            }
            else {
                cout << "Invalid position" << endl;
                return;
            }
            index--;
        }

        // this if condition comes when there is only one element in LL and index is 2
        if (cur != NULL) {
            temp->next = pre->next;
            pre->next = temp;
        }
        else {
            cout << "Invalid position" << endl;
        }
        return;
    }

    void DeleteAtIndex_using_prev(int index) {
        if (head == NULL) {
            cout << "List is empty" << endl;
        }

        if (index <= 0) {
            cout << "Invalid position" << endl;
        }

        Node *temp = head;
        if (index == 1) {
            temp = head->next;
            delete head;
            head = temp;
            return;
        }

        Node *pre = head;
        Node *cur = head;
        while (index > 1) {
            if (cur != NULL) {
                pre = cur;
                cur = cur->next;
            }
            else {
                cout << "Invalid position" << endl;
                return;
            }
            index--;
        }

        if (cur != NULL) {
            pre->next = cur->next;
            delete cur;
        }
        else {
            cout << "Invalid position" << endl;
        }
        return;
    }

    void InsertAtIndex_using_dummy(int val, int index) {

        if (index <= 0) {
            cout << "Invalid position" << endl;
        }

        Node *dummy = new Node;
        dummy->next = head;

        Node *temp = new Node;
        temp->data = val;
        temp->next = NULL;

        Node *pre = dummy;
        Node *cur = head;

        int i = index;
        while (index > 1) {
            if (cur != NULL) {
                pre = cur;
                cur = cur->next;
            }
            else {
                cout << "Invalid position" << endl;
                return;
            }
            index--;
        }

        // due to dummy node condition before while loop is removed i.e. edge condition for index == 1
        // This if condition will anyways will be required despite of dummy Node
        // this if condition comes when there is only one element in LL and index is 2
        if (cur != NULL) {
            temp->next = pre->next;
            if (i == 1) {      // This edge case need to be handled. Dummy node here is not that much useful
                               // because we are not method's return value is void
                head = temp;   // head = temp; should be there for index == 1
            }
            else {
                pre->next = temp;
            }
        }
        else {
            cout << "Invalid position" << endl;
        }
        return;
    }

    void DeleteAtIndex_using_dummy(int index) {
        if (head == NULL) {
            cout << "List is empty" << endl;
        }

        if (index <= 0) {
            cout << "Invalid position" << endl;
        }

        Node *dummy = new Node;
        dummy->next = head;

        Node *pre = dummy;
        Node *cur = head;

        int i = index;
        while (index > 1) {
            if (cur != NULL) {
                pre = cur;
                cur = cur->next;
            }
            else {
                cout << "Invalid position" << endl;
                return;
            }
            index--;
        }

        if (cur != NULL) {
            if (i == 1) {
                head = cur->next;
            }
            else {
                pre->next = cur->next;
            }
            delete cur;
        }
        else {
            cout << "Invalid position" << endl;
        }
        return;
    }

    void Reverse() {
        Node *pre = NULL;
        Node *cur = head;
        Node *temp;
        while (cur->next != NULL) {
            temp = cur->next;       // take backup of next node
            cur->next = pre;        // make reverse link
            pre = cur;              // update pre pointer
            cur = temp;             // update cur pointer
        }
        cur->next = pre;
        head = cur;
        return;
    }

    void Reverse_Recursive() {
        Node *node = __Reverse(head);
        node->next = NULL;          // Handle head = NULL case
        return;
    }

    Node *__Reverse(Node *node) {
        if (node->next == NULL) {
            head = node;            // update head in base case
            return node;            // return current node
        }
        Node *temp = __Reverse(node->next);     // Stack unwinding is used to update the next pointers
        temp->next = node;                      // update prev's next pointer to point cur node
        return node;                            // return cur node
    }

};


int main()
{
    SinglyLL a;
    a.InsertAtBegin(1);
    a.InsertAtBegin(2);
    a.InsertAtBegin(3);
    a.Print();

    SinglyLL b;
    b.InsertAtEnd(1);
    b.InsertAtEnd(2);
    b.InsertAtEnd(3);
    b.InsertAtEnd(4);
    b.InsertAtEnd(5);
    // b.DeleteFromBegin();
    // b.DeleteFromEnd();
    // b.DeleteFromEnd();
    // b.DeleteFromEnd();
    // b.DeleteFromEnd();
    b.Print();
    // b.InsertAtIndex(300, 2);
    // b.DeleteAtIndex(2);
    // b.InsertAtIndex_using_prev(400, 2);
    // b.DeleteAtIndex_using_prev(6);
    // b.InsertAtIndex_using_dummy(500, 1);
    // b.DeleteAtIndex_using_dummy(3);
    // b.Print();
    b.Reverse();
    b.Print();
    b.Reverse_Recursive();
    b.Print();
    return 0;
}