#include <iostream>
using namespace std;

void fun(int &ref) {
    cout << "Normal ref" << endl;
}

void fun(int &&ref) {
    cout << "r-value ref" << endl;
}

int main() {
    int i = 10;
    // int &j = i;      // perfectly valid case
    // int &j = 20;     // not allowed. const int &j = 20; is allowed.
                        // we can create ref to a variable but not to a temporary.
    int &&j = 20;       // valid case as j is an r-value ref
    j++;
    cout << j << endl;

    fun(i);
    fun(100);   // compiler automatically identifies which overloaded function
                // to call for r-value ref argument.
}