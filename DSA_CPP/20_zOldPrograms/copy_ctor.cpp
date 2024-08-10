#include<iostream>
using namespace std;
 
class Point
{
private:
    int x, y;
public:
    Point(int x1, int y1) { x = x1; y = y1; }
 
    // Copy constructor
    Point(Point &p2) {x = p2.x; y = p2.y; cout << "copy ctor called" << endl;}
 
    int getX()            {  return x; }
    int getY()            {  return y; }
	void printxy(Point P) {cout << "x : " << P.x << "\ny : " << P.y << endl;}
};
 
int main()
{
    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here
    p2.printxy(p1);
    // Let us access values assigned by constructors
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY() << endl;
    cout << "p2.x = " << p2.getX() << ", p2.y = " << p2.getY() << endl;
 
    return 0;
}