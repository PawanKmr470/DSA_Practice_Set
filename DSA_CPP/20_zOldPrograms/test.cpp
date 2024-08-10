#include <iostream>
using namespace std;

class A
{
	public:
	A(){cout << "Ctor of A" << endl;};
	~A()
	{
		cout << "Dtor of A" << endl;
	}
};

class B : public A
{
	/*private:
		A* ptr;*/
	public:
	B()
	{
		//ptr = new A();
		cout << "Ctor of B" << endl;
	};
	~B()
	{
		//delete ptr;
		cout << "Dtor of B" << endl;
	}
	
};


int main()
{
	A* b = new B();
	delete b;

	/*{
		B b;
	}*/
	getchar();
	return 0;
}