#include <iostream>
using namespace std;

class Test {
public:
    // Test() { cout << "default ctor" << endl; }
    Test() = default;
    Test(int x) { cout << "param ctor" << endl; }
};

int main() {
    Test t1;
    Test t2(10);
    return 0;
}