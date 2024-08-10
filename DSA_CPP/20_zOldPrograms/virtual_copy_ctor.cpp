#include <iostream>
using namespace std;

class Animal
{
protected:
	int itsAge;
public:
	Animal():itsAge(1)
	{
		cout << "Animal constructor...\n";
	}
	virtual ~Animal()
	{
		cout << "Animal destructor...\n";
	}
	int GetAge()const
	{
		return itsAge;
	}
	Animal (const Animal & rhs):itsAge(rhs.GetAge())
	{
		cout << "Animal Copy Constructor...\n";
	}
	virtual void Speak() const
	{
		cout << "Animal speak!\n";
	}
	virtual Animal* Clone()
	{
		cout << "Animal obj creation\n";
		return new Animal(*this);
	}
};


class Dog : public Animal
{
public:
	Dog()
	{
		cout << "Dog constructor...\n"; 
	}
	virtual ~Dog()
	{
		cout << "Dog destructor...\n"; 
	}
	Dog (const Dog & rhs) : Animal(rhs)
	{
		cout << "Dog copy constructor...\n";
	}
	void Speak()const
	{
		cout << "Woof!\n"; 
	}
	virtual Animal* Clone()
	{
		cout << "Dog obj creation\n";
		return new Dog(*this);
	}
};

class Cat : public Animal {
public:
	Cat()
	{
		cout << "Cat constructor...\n"; 
	}
	virtual ~Cat()
	{
		cout << "Cat destructor...\n"; 
	}
	Cat (const Cat &rhs): Animal(rhs)
	{
		cout << "Cat copy constructor...\n";
	}
	void Speak()const
	{
		cout << "Meow!\n"; 
	}
	virtual Animal* Clone()
	{
		cout << "Cat obj creation\n";
		return new Cat(*this);
	}
};

int main()
{
	Animal *theArray[3];
	Animal* ptr;
	int choice,i;

	theArray[0] = new Dog;
	theArray[1] = new Cat;
	theArray[2] = new Animal;

	Animal *OtherArray[3];
	cout << "\n************************\n";
	for (i=0;i<3;i++)
	{
		//theArray[i]->Speak();
		OtherArray[i] = theArray[i]->Clone();
	}
	cout << "\n************************\n";
	for (i=0;i<3;i++)
	{
		OtherArray[i]->Speak();
	}
	return 0;
}