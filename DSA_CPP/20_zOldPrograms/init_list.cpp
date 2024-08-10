#include <iostream>
using namespace std;
 

class Type
{
	int x;
public:
	Type()
	{
		cout << "Type Dft Ctor\n";
	}
	Type(int &arg)
	{
		x = arg;
		cout << "Type Pmtz Ctor\n";
	}
	~Type()
	{
		cout << "Type Dft Dtor\n";
	}

	int &GetX()
	{
		return x;
	}

	Type(Type& arg)
	{
		x = arg.GetX();
		cout << "copy ctor\n";
	}
	Type & operator = (Type &arg )
	{
		x = arg.GetX();
		cout << "assigmt copy operator\n";
		return *this;
	}
};

// Without Initializer List
class MyClass {
    Type variable;
public:
    MyClass(Type a):variable(a) {  // Assume that Type is an already
                     // declared class and it has appropriate 
                     // constructors and operators
      //variable = a;
    }
};

int main()
{
	int x = 10;
	Type t1(x);
	Type t2 = t1;
	cout << "**********************\n";
	MyClass m1(t1);
	cout << "**********************\n";
	return 0;
}