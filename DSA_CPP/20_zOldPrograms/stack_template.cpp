#include <iostream>
using namespace std;

template <typename T>
class node
{
public:
	T data;
	node* next;
};

template <typename T>
class stack
{
	node<T>* start;
public:
	stack(node<T>* st=NULL):start(st){}
	~stack(){ destroy(); }
	void push(T data);
	void pop();
	void display();
	void destroy();
};

template <typename T>
void stack<T>::destroy()
{
	node<T>* temp;
	while(NULL != start)
	{
		temp = start;
		start = start->next;
		delete temp;
		temp = NULL;
	}
}

template <typename T>
void stack<T>::display()
{
	if (NULL == start)
	{
		cout<<"stack is empty.Nothing to display."<<endl;
		return;
	}

	node<T>* ptr = start;
	cout<<"\nstack :";
	while(NULL != ptr)
	{
		cout<<"\t"<<ptr->data;
		ptr = ptr->next;
	}
	cout<<"\n";
}

template <typename T>
void stack<T>::push(T data)
{
	node<T>* temp;
	temp = new node<T>(); // can omit ()
	temp->data = data;
	temp->next = start;
	start = temp;
}

template <typename T>
void stack<T>::pop()
{
	if (NULL == start)
	{
		cout<<"stack is empty.Nothing to delete."<<endl;
		return;
	}

	node<T>* temp = start;
	start = temp->next;
	delete temp;
	temp = NULL;
}

int main()
{
	stack<int> st(NULL);

	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);

	st.display();

	st.pop();
	st.display();

	return 0;
}

// for queue implementation make pop operation from the last node !