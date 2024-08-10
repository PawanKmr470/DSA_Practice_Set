#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
    this->data = data;
    this->next = NULL;
    }
    ~Node(){};
};

class LinkedList
{
private:
    Node* head;
public:
    LinkedList(){ head = NULL; }
    ~LinkedList(){};
    void InsertNode(int);
    void DeleteNode(int);
    void PrintList();
};

void LinkedList::InsertNode(int data)
{
    Node* cur;
    Node* NewNode = new Node(data);
    if (head == NULL)
    {
        head = NewNode;
        return;
    }

    cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = NewNode;
    return;
}

void LinkedList::DeleteNode(int val)
{
    Node* cur = head;
    Node* prev = NULL;

    if (head == NULL)
    {
        return;
    }

    while (cur != NULL)
    {
        if (cur->data == val)
        {
            if (prev == NULL)
            {
                head = cur->next;
                delete cur;
                break;
            }
            prev->next = cur->next;
            delete cur;
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    return;
}

void LinkedList::PrintList()
{
    Node* cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    LinkedList mylist;
    mylist.InsertNode(1);
    mylist.InsertNode(2);
    mylist.InsertNode(3);
    mylist.InsertNode(4);
    mylist.InsertNode(5);
    mylist.PrintList();
    mylist.DeleteNode(1);
    mylist.PrintList();
    return 0;
}