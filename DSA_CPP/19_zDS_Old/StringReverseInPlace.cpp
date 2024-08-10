#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char *StringReverse(char *ptr) {
    int i = 0;
    int j = strlen(ptr) - 1;
    char temp;
    for (; i < j; i++,j--) {
        temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
    }
    return ptr;
}

int main() {
    char str[] = "hello";
    int n = strlen(str);

    char *p = new char[n + 1];  // + 1 for NULL
    strcpy(p, str);
    char *q = StringReverse(p);
    cout << q << endl;
    q = NULL;   // after use assign NULL otherwise it can point to
                // de-allocated memory later in the code -> dangling ptr
}