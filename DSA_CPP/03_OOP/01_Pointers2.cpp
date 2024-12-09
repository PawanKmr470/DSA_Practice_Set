#include <iostream>
using namespace std;

int main() {

    // Basics
    int *p[3];      // array of pointers, can be represented as : int *( p[3] );
    int (*q)[3];    // pointer to an array of integers
    int* (*r)[3];   // pointer to an array of pointers

    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {10,20,30,40,50};
    int arr3[5] = {100,200,300,400,500};

    int *parr[3];
    parr[0] = arr1;
    parr[1] = arr2;
    parr[2] = arr3;

    int **pparr = parr;         // ptr to ptr to an array (First Level Pointer)
    int *(*ptr)[3] = &parr;     // ptr to array of ptrs (Block Pointer)

    // array name is a first level pointer which will point to an integer value
    // because array name + 1 will give second element BUT jut remember this only
    // sizeof(array name) will give the size of whole array. This is how compiler works.
    // Analogous to -
    int arr[5] = {1,2,3,4,5};
    int *ptr1 = arr;            // ptr to array (First Level Pointer)
    int (*ptr2)[5] = &arr;      // ptr to array of 5 ints (Block Pointer)

    cout << "*****************************" << endl;

    cout << "arr1 : " << arr1 << endl;
    cout << "arr2 : " << arr2 << endl;
    cout << "arr3 : " << arr3 << endl;
    cout << endl;

    cout << "parr[0] : " << parr[0] << endl;
    cout << "parr[1] : " << parr[1] << endl;
    cout << "parr[2] : " << parr[2] << endl;
    cout << endl;

    cout << "parr         : " << parr << " same range" << endl;
    cout << "parr + 1     : " << parr + 1 << endl;
    cout << "parr + 2     : " << parr + 2 << endl;
    cout << "*parr        : " << *parr << endl;
    cout << "*(parr + 1)  : " << *(parr + 1) << endl;
    cout << "*(parr + 2)  : " << *(parr + 2) << endl;
    cout << "**(parr + 2) : " << **(parr + 2) << endl;
    cout << endl;

    cout << "pparr         : " << pparr << " same range" << endl;
    cout << "pparr + 1     : " << pparr + 1 << endl;
    cout << "pparr + 2     : " << pparr + 2 << endl;
    cout << "*pparr        : " << *pparr << endl;
    cout << "*(pparr + 1)  : " << *(pparr + 1) << endl;
    cout << "*(pparr + 2)  : " << *(pparr + 2) << endl;
    cout << "**(pparr + 2) : " << **(pparr + 2) << endl;

    cout << "*****************************" << endl;

    // int **pparr = parr;
    // int *(*ptr)[3] = &parr;

    cout << "ptr     : " << ptr << endl;
    cout << "ptr + 1 : " << ptr + 1 << endl;
    // jump by size of parr array (array of ptrs) - 24 bytes
    // ptr is representing WHOLE parr array
    cout << "*****************************" << endl;
}
