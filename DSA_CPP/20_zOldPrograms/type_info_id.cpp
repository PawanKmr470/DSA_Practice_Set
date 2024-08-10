#include <iostream>
#include <typeinfo>
using namespace std;

class Employee { 
private:
	int id;
public:
	void show_id(){cout << "ID shown\n" << endl;}
};

class Programmer : public Employee {
public:
	void coding(){cout << "coding\n" << endl;}
};

int main() 
{
	Employee lee;
	Programmer park;

	Employee *pEmpA = &lee;
	Employee *pEmpB = &park;

	// check if two object is the same
	if(typeid(Programmer) == typeid(lee)) {
		Programmer *pProg = (Programmer *)&lee; 
		pProg->coding();
	}
	if(typeid(Programmer) == typeid(park)) {
		Programmer *pProg = (Programmer *)&park; 
		pProg->coding();
	}
	printf("Programmer typeid : %s\n",typeid(Programmer).name());
	printf("Employee   typeid : %s\n",typeid(Employee).name());
	pEmpA->show_id();
	pEmpB->show_id();

	int * a;
	int b; 

	a=0; b=0;
	if (typeid(a) != typeid(b))
	{
		cout << "a and b are of different types:\n";
		cout << "a is: " << typeid(a).name() << '\n';
		cout << "b is: " << typeid(b).name() << '\n';
	}

	getchar();
	return 0;
}