#include <iostream>
using namespace std;


class Base
{
protected:
	int i;
public:
	Base(int a = 0) { i = a; }
	virtual void display()
	{ cout << "I am Base class object, i = " << i << endl; }
};

class Derived : public Base
{
	int j;
public:
	Derived(int a, int b) : Base(a) { j = b; }
	virtual void display()
	{ cout << "I am Derived class object, i = "
			<< i << ", j = " << j << endl;  }
};


int main()
{
	Base b(33);
	Derived d(45, 54);
	Base obj;

	obj = b;
	obj.display();	// works fine

	obj = d;		// problem comes here in next line of code.
	obj.display();	// Object Slicing, the member j of d is sliced off

	// Solution to this problem is to use references or pointers to the base class.

	Base &obj2 = d;
	obj2.display();

	Base *pB = &d;
	pB->display();

	return 0;
}