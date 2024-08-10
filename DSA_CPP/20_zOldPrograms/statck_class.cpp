
#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
};

class stack
{
	node* start;
public:
	stack(node* st=NULL):start(st){}
	void push(int data);
	void pop();
	void display();
};

void stack::display()
{
	if (NULL == start)
	{
		cout<<"stack is empty.Nothing to display."<<endl;
		return;
	}

	node* ptr = start;
	cout<<"\nstack :";
	while(NULL != ptr)
	{
		cout<<"\t"<<ptr->data;
		ptr = ptr->next;
	}
	cout<<"\n";
}

void stack::push(int data)
{
	node* temp;
	temp = new node;
	temp->data = data;
	temp->next = start;
	start = temp;
}

void stack::pop()
{
	if (NULL == start)
	{
		cout<<"stack is empty.Nothing to delete."<<endl;
		return;
	}

	node* temp = start;
	start = temp->next;
	delete temp;
	temp = NULL;
}

int main()
{
	stack st(NULL);

	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);

	st.display();

	st.pop();
	st.display();

	return 0;
}

