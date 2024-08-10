#include <iostream>
using namespace std;

// struct Node {
//     int data;
//     Node *next;
//     Node *prev;
// };

typedef struct node {
    int data;
    node *next;
    node *prev;
} Node, *pNode;

class DoublyLL
{
private:
    Node *head;
public:
    DoublyLL() { head = NULL; }
    ~DoublyLL() {};

    void InsertAtBegin(int val) {
        Node *temp = new Node;
        temp->data = val;
        temp->prev = NULL;

        temp->next = head;
        if (head != NULL) {
            head->prev = temp;
        }
        head = temp;
        return;
    }

    void Display() {
        if (head == NULL) { return; }
        Node *cur = head;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void InsertAtEnd(int val) {
        Node *temp = new Node;
        temp->data = val;
        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            return;
        }

        Node *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
        temp->prev = cur;
        return;
    }

    void InsertAtIndex(int val, int index) {
        Node *temp = new Node;
        temp->data = val;
        temp->prev = NULL;
        temp->next = NULL;

        if (index <= 0) {
            cout << "List is empty" << endl;
            return;
        }

        if (index == 1) {
            temp->next = head;
            if (head != NULL) {
                head->prev = temp;
            }
            head = temp;
            return;
        }

        // pre node pointer is not required. It's DLL
        Node *cur = head;
        while (index > 1) {
            if (cur != NULL) {
                cur = cur->next;
            }
            else {
                cout << "Invalid position" << endl;
                return;
            }
            index--;
        }

        if (cur != NULL) {
            // KEY POINT : first update next temp's next & prev because they were null
            // then we can update those next & prev whose next & prev has been backed into temp's
            // next & prev
            temp->next = cur;           // temp to cur node link
            temp->prev = cur->prev;     // temp to pre node link
            cur->prev->next = temp;     // pre node to temp link
            cur->prev = temp;           // cur node to temp link
        }
        else {
            cout << "Invalid position" << endl;
        }
        return;
    }

    void DeleteAtIndex(int index) {
        if (index <= 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp;
        if (index == 1) {
            temp = head->next;
            if (head->next != NULL) {
                head->next->prev = NULL;
            }
            delete head;
            head = temp;
            return;
        }

        Node *cur = head;
        while (index > 1) {
            if (cur != NULL) {
                cur = cur->next;
            }
            else {
                cout << "Invalid position" << endl;
                return;
            }
            index--;
        }

        if (cur != NULL) {                      // if condition requirement : when 1 element is there and index == 2
            cur->prev->next = cur->next;
            if (cur->next != NULL) {            // when 2 elements in list and index == 2 type case
                cur->next->prev = cur->prev;
            }
            delete cur;
        }
        else {
            cout << "Invalid position" << endl;
        }
        
        return;
    }

    // void DeleteWithValue(int val);
    // void Reverse();
    // void ReverseRecursive();
};

int main() {
    DoublyLL d;
    // d.InsertAtBegin(1);
    // d.InsertAtBegin(2);
    // d.InsertAtBegin(3);

    d.InsertAtEnd(1);
    d.InsertAtEnd(2);
    d.InsertAtEnd(3);
    d.InsertAtEnd(4);
    d.InsertAtEnd(5);
    d.Display();
    // d.InsertAtIndex(100, 3);
    // d.DeleteAtIndex(1);
    d.Display();
}


