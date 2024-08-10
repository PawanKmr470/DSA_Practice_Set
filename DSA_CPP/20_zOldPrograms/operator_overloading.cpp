#include <iostream>
using namespace std;


class Complex
{
	int real;
	int img;
public:
	Complex(int Re = 0, int Img = 0)//:real(Re),img(Img)
	{
		real = Re;
		img = Img;
		cout << "Ctor\n";
	}
	~Complex()
	{
		cout << "Dtor\n";
	}
	void PrintNumbers()
	{
		cout << "REAL      : " << real << "\nIMAGINARY : " << img << endl;
	}
	Complex operator + (const Complex & n)
	{
		Complex n3;
		n3.real = this->real + n.real;
		n3.img  = this->img  + n.img;
		return n3;
	}
};

int main()
{

	Complex n1(2,5);
	Complex n2 = n1; // This is preferred over n2 = n1 bcz if it optimizes performance by avoiding one extra call to ctor !
	//n2 = n1;
	n1.PrintNumbers();
	n2.PrintNumbers();
	Complex n3;
	n3 = n1 + n2;
	n3.PrintNumbers();
	return 0;
}