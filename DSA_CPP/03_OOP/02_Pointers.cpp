#include <iostream>
using namespace std;

int main() {
    int *ptr1 = new int(10);    // initialize allocated mem with value 10
    cout << ptr1 << " -> " << *ptr1 << endl;

    int *myptr = new int(10);
    // int *gptr = myptr;
    // int *ggptr = gptr;   // it doesn't work this way. ggptr is same as gptr
    int **gptr = &myptr;
    int ***sgptr = &gptr;
    int ****ssgptr = &sgptr; // correct way.
                             // Pointer should be of appropriate base type

    cout << "************* Memo ***************" << endl;
    char names[][5] = {"paul", "john"};
    for (int i=0; i<2; i++) {
        cout << names[i] << " ";
    }
    cout << endl;

    char *name_ptr[2];                          // TO REMEMBER : array of pointers
    for (int i=0; i<2; i++) {
        name_ptr[i] = names[i];
    }

    for (int i=0; i<2; i++) {
        // cout << name_ptr[i] << endl;
        cout << *(name_ptr + i) << " ";
    }
    cout << endl;


    // Note to rememeber :
    // array size by it's name (arr) gives the size of whole array but
    // it's a pointer to 1st First Dimension / 1st Block / 1st Level
    // &arr is a pointer to whole array
    // This is how it works

    cout << endl;
    cout << "************ int arrays **********" << endl;

    // 1D array by array name
    int arr[5] = {10,20,30,40,50};
    
    cout << "pointer size : " << sizeof(int *) << endl;   // on this machine, int ptr size => 8 bytes
    cout << "integer size : " << sizeof(int) << endl;   // int size => 4 bytes

    cout << "size of arr  : " << sizeof(arr) << endl;           // 20 bytes
    cout << "size of &arr : " << sizeof(&arr) << endl;          // 8 bytes
    cout << "typeid.name  : " << typeid(arr).name() << endl;    // A5_i
    cout << "typeid.name  : " << typeid(&arr).name() << endl;   // PA5_i

    cout << "addr of arr      : " << arr << endl;        // addr of it's first element
    cout << "addr of arr + 1  : " << arr + 1 << endl;    // skips by 4 bytes (int size)
    cout << "addr of &arr     : " << &arr << endl;       // also addr of first element AND &arr == 'int (*)[5]' (pointer to an array of 5 items)
    cout << "addr of &arr + 1 : " << &arr + 1 << endl;   // skips by size of array 20 bytes

    // to check the same
    cout << "bytes diff1 : " << (char *)(arr + 1) - (char *)arr << endl;    // 4 bytes
    cout << "bytes diff2 : " << (char *)(&arr + 1) - (char *)&arr << endl;  // 20 bytes

    for (int i=0; i<5; i++) {
        // cout << arr[i] << " ";       // baisc method
        cout << *(arr + i) << " ";      // using arr name, arr + 1 is incremented by the size of it's base type
    }
    cout << endl;


    cout << endl;
    cout << "********** array with pointer *****" << endl;
    // 1D array with pointer
    int *ptr = arr;         // arr is the addr of first element, so int *ptr can take it.
    
    // int *ptr2 = &arr;    // ERROR : cannot convert 'int (*)[5]' to 'int*'
    // int **ptr2 = &arr;   // ERROR : cannot convert 'int (*)[5]' to 'int**'
    int (*ptr2)[5] = &arr;  // Correct way - pointer to int array
                            // &arr is the addr of WHOLE array (tough it's same addr as arr),
                            // so int (*ptr2)[5] will take it not simple int *ptr2

    cout << "addr of ptr      : " << ptr << endl;
    cout << "addr of ptr + 1  : " << ptr + 1 << endl;   // skips by 4 bytes
    cout << "addr of ptr2     : " << ptr2 << endl;
    cout << "addr of ptr2 + 1 : " << ptr2 + 1 << endl;  // skips by 20 bytes (by whole array size)

    cout << "bytes diff3 : " << (char *)(ptr + 1) - (char *)ptr << endl;    // 4 bytes
    cout << "bytes diff4 : " << (char *)(ptr2 + 1) - (char *)&arr << endl;  // 20 bytes

    cout << "size of ptr   : " << sizeof(ptr) << endl;      // 8 bytes, ptr a pointer only
    cout << "size of ptr2  : " << sizeof(ptr2) << endl;     // 8 bytes, ptr2 is only pointer
    cout << "size of *ptr2 : " << sizeof(*ptr2) << endl;    // *ptr2 -> arr

    for (int i=0; i<5; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    for (int i=0; i<5; i++) {
        cout << *(*ptr2 + i) << " ";
    }
    cout << endl;



    cout << endl;
    cout << "************ 2D arrays ***********" << endl;

    // 2D array
    int arr2[2][3] = {
        {10,20,30},
        {100,200,300}
    };
    
    cout << "size of arr2  : " << sizeof(arr2) << endl;     // 24 bytes (whole array size)
    cout << "size of &arr2 : " << sizeof(&arr2) << endl;    // 8 bytes (size of pointer)

    cout << "addr of arr2      : " << arr2 << endl;        // addr of FIRST ROW (in fact is also the addr of first element)
    cout << "addr of arr2 + 1  : " << arr2 + 1 << endl;    // skips by 12 bytes (row size) to second row
    cout << "addr of &arr2     : " << &arr2 << endl;       // addr of WHOLE 2D array (also addr of first element) AND &arr => 'int (*)[5]'
    cout << "addr of &arr2 + 1 : " << &arr2 + 1 << endl;   // skips by size of 2d array 24 bytes

    cout << "bytes diff5 : " << (char *)(arr2 + 1) - (char *)arr2 << endl;      // 12 bytes
    cout << "bytes diff6 : " << (char *)(&arr2 + 1) - (char *)&arr2 << endl;    // 24 bytes

    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            // cout << arr2[i][j] << " ";
            cout << *(*(arr2 + i) + j) << " ";
            // arr2 + 1 will jump to addr of second WHOLE row               => $$ IMPORTANT $$
            // *(arr2 + 1) will give first element's addr of second row
            // *(arr2 + 1) + 1 will give second element's addr of second row
            // *(*(arr2 + 1) + 1) will give actual second element of second row
        }
        cout << endl;
    }

    cout << endl;
    cout << "******** 2D array pointer ********" << endl;

    // int **ptr3 = arr2;  // ERROR : cannot convert 'int (*)[3]' to 'int**'
    // int (*ptr3)[2] = arr2;  // ERROR : cannot convert 'int (*)[3]' to 'int (*)[2]'
    // int (*ptr3)[cols]
    int (*ptr3)[3] = arr2;
    int (*ptr4)[2][3] = &arr2;  // pointer to a matrix of 2x3

    cout << "addr of ptr3      : " << ptr3 << endl;
    cout << "addr of ptr3 + 1  : " << ptr3 + 1 << endl;     // by row size (12 bytes)
    cout << "addr of ptr4      : " << ptr4 << endl;
    cout << "addr of ptr4 + 1  : " << ptr4 + 1 << endl;     // by whole array size (24 bytes)

    cout << "size of ptr3  : " << sizeof(ptr3) << endl;     // pointer size (8 bytes)
    cout << "size of *ptr3 : " << sizeof(*ptr3) << endl;    // row size (12 bytes)
    cout << "size of ptr4  : " << sizeof(ptr4) << endl;     // pointer size (8 bytes)
    cout << "size of *ptr4 : " << sizeof(*ptr4) << endl;    // whole array size (24 bytes)

    cout << "bytes diff7 : " << (char *)(ptr3 + 1) - (char *)ptr3 << endl;  // row size (12 bytes)
    cout << "bytes diff8 : " << (char *)(ptr4 + 1) - (char *)ptr4 << endl;  // whole array size (24 bytes)

    // using ptr3
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            cout << *( *(ptr3 + i) + j ) << " ";
            // theory is same as remark : $$ IMPORTANT $$
        }
        cout << endl;
    }

    // using ptr4
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            cout << *( *(*ptr4 + i) + j ) << " ";
        }
        cout << endl;
    }
    
    


    cout << endl;
    cout << "************ 3D arrays ***********" << endl;

    // 3D array
    int arr3[2][3][4] = {
        {
            {10,11,12,13},
            {20,21,22,23},
            {30,31,32,33},
        },
        {
            {100,110,120,130},
            {200,210,220,230},
            {300,310,320,330},
        }
    };

    cout << "size of arr3    : " << sizeof(arr3) << endl;       // 96 bytes (whole array size)
    cout << "size of *arr3   : " << sizeof(*arr3) << endl;      // 48 bytes (first matrix size)
    cout << "size of **arr3  : " << sizeof(**arr3) << endl;     // 16 bytes (size of first row of first matrix)
    cout << "size of ***arr3 : " << sizeof(***arr3) << endl;    // 4 bytes (size of first element)
    cout << "size of &arr3   : " << sizeof(&arr3) << endl;      // 8 bytes (size of pointer)

    cout << "addr of arr3      : " << arr3 << endl;        // addr of FIRST 3x4 matrix (in fact is also the addr of first element)
    cout << "addr of arr3 + 1  : " << arr3 + 1 << endl;    // skips by 48 bytes (first matrix size) to second matrix
    cout << "addr of &arr3     : " << &arr3 << endl;       // addr of WHOLE 3D array (also addr of first element)
    cout << "addr of &arr3 + 1 : " << &arr3 + 1 << endl;   // skips by size of 3D array 96 bytes

    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<4; k++) {
                // cout << arr3[i][j][k] << " ";    // basic method
                cout << *( *( *(arr3 + i) + j ) + k) << " ";
            }
            cout << endl;
            // cout << arr2[i][j] << " ";
            // cout << *(*(arr2 + i) + j) << " ";
            // arr2 + 1 will jump to addr of second WHOLE row               => $$ IMPORTANT $$
            // *(arr2 + 1) will give first element's addr of first row
            // *(arr2 + 1) + 1 will give second element's addr of first row
            // *(*(arr2 + 1) + 1) will give actual second element of second row
        }
        cout << endl;
    }

    cout << endl;
    cout << "******** 3D array pointer ********" << endl;

    // int arr3[2][3][4] = {
    //     {
    //         {10,11,12,13},
    //         {20,21,22,23},
    //         {30,31,32,33},
    //     },
    //     {
    //         {100,110,120,130},
    //         {200,210,220,230},
    //         {300,310,320,330},
    //     }
    // };

    // int (*ptrx)[4] = arr3;  // cannot convert 'int (*)[3][4]' to 'int (*)[4]'
    // int (*ptrx)[][4] = arr3;    // also works
    int (*ptrx)[3][4] = arr3;

    // int (*ptry)[][3][4] = &arr3;    // also works
    int (*ptry)[2][3][4] = &arr3;

    cout << "addr of ptrx      : " << ptrx << endl;
    cout << "addr of ptrx + 1  : " << ptrx + 1 << endl;     // by first matrix size (48 bytes)
    cout << "addr of ptry      : " << ptry << endl;
    cout << "addr of ptry + 1  : " << ptry + 1 << endl;     // by whole array size (96 bytes)

    cout << "size of ptrx    : " << sizeof(ptrx) << endl;       // pointer size (8 bytes)
    cout << "size of *ptrx   : " << sizeof(*ptrx) << endl;      // 48 bytes (size of first matrix)
    cout << "size of **ptrx  : " << sizeof(**ptrx) << endl;     // 16 bytes (size of first row of first matrix)
    cout << "size of ***ptrx : " << sizeof(***ptrx) << endl;    // 4 bytes (size of first element)


    cout << "size of ptry  : " << sizeof(ptry) << endl;         // pointer size (8 bytes)
    cout << "size of *ptry : " << sizeof(*ptry) << endl;        // 96 bytes
    cout << "size of **ptry : " << sizeof(**ptry) << endl;      // 48 bytes
    cout << "size of ***ptry : " << sizeof(***ptry) << endl;    // 16 bytes
    cout << "size of ****ptry : " << sizeof(****ptry) << endl;  // 4 bytes

    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<4; k++) {
                cout << *( *( *(ptrx + i) + j ) + k ) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<4; k++) {
                cout << *( *( *(*ptry + i) + j ) + k ) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }




    cout << endl;
    cout << "******** array of pointers ********" << endl;

    // Simple analogy -
    // int x;      // variable x of type int
    // int x[3];   // variables x[0], x[1], x[2] of type int
    // int *p;     // pointer/variable p of type int *
    // int *p[3];  // pointers p[0], p[1], p[2] of type int *
    //             // In common words, Array of Pointers

    // allocate 2D array using Array of Pointers
    int *xptr[3];
    int *yptr = xptr[0];
    int **zptr = xptr;
    int* (*Aptr)[3] = &xptr;    // :) because Aptr is a pointer to whole array of pointers

    // <dataType> * <pointer name> = new <dataType> [<size>] (init value);
    // Dynamic 2D Array of Pointers -
    // <dataType> **<Pointer name> = new <dataType> *[<size>]; 
    int *i = new int;
    int *j = new int();     // initialize with zero
    int *k = new int[5];    // array of 5 integers
    int *l = new int[5]();
    int **m = new int *[5];

    delete i;
    delete j;
    delete[] k;
    delete[] l;
    // delete[] m; // This can work but when each element of array contains addr of dynamically
                // allocated 1D array of ints then a for loop is required as mentioned right below.
    for (int i=0; i<5; i++) {
        delete[] m[i];
    }

    // This is a simple case
    int temp_count = 100;
    int *pn = new int[3];

    for (int i=0; i<5; i++) {
        pn[i] = temp_count++;
    }

    for (int i=0; i<5; i++) {
        cout << pn[i] << " ";
    }

    delete[] pn;
    cout << endl;
    cout << endl;

    cout << "******** 2D matrix allocation ********" << endl;
    int m = 3, n = 4, c = 0;
    cout << "******** 2D matrix using single ptr ********" << endl;

    // Allocation
    int *point1 = new int[m * n];

    // Assigning
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(arr + (i*n) + j) = ++c;
        }
    }

    // Accessing
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(arr + (i*n) + j) << " ";
        }
        cout << endl;
    }

    // Deallocation
    delete[] point1;    // As it was a single allocation

    cout << "******** 2D matrix using array of ptrs ********" << endl;

    // Allocation
    // we will do "new int[n]" for each row which will return a pointer
    // to hold these row pointers we will need another array of pointers
    // new int *[m]

    int **point2 = new int *[m];
    for (int i = 0; i < m; i++) {
        point2[i] = new int[n];
    }

    // Assigning
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            point2[i][j] = ++c;
        }
    }

    // Accessing
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << point2[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocation
    for (int i = 0; i < m; i++) {
        delete[] point2[i];         // For each row
    }
    delete[] point2;                // For array of pointers

    cout << "******** 3D matrix allocation ********" << endl;
    int x = 2;  // No of 2D arrays.
    int y = 3;  // No of rows of each 2D array.
    int z = 4;  // No of columns of each 2D array.
    cout << "******** 3D mtx using single ptr ********" << endl;

    int count = 0;
    int *mtx = new int[x*y*z];

    // assigning values
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                // *(((mtx + i) + j) + k)  = ++count;   // this won't work
                *(mtx + (i * y * z) + (j * z) + k) = ++count;
            }
        }
    }

    // accessing values
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                // cout << *(((mtx + i) + j) + k) << " ";   // this won't work
                cout << *(mtx + (i * y * z) + (j * z) + k) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;

    cout << "******** 3D mtx using triple ptr ********" << endl;
    // https://www.geeksforgeeks.org/how-to-dynamically-allocate-a-3d-array-in-c/
    // https://media.geeksforgeeks.org/wp-content/uploads/20201117142445/3D.JPG
    
    // mptr is a pointer of type int ***
    // and it's pointing to an array of pointers of type int**
    // where each element (i.e. pointer of int ** type) will hold 
    // array of pointers and each of this pointer will hold address of an array of int data.
    // int ***mptr -> [int **, int **]
    // int ** -> [int *, int *, int *]
    // int * -> [int, int, int, int]

    count = 0;
    int ***mptr = new int **[x];

    // Allocation
    for (int i = 0; i < x; i++) {
        mptr[i] = new int *[y];
        for (int j = 0; j < y; j++) {
            mptr[i][j] = new int [z];
        }
    }

    // Assignment
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                mptr[i][j][k] = ++count;
            }
        }
    }

    // Accessing
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << mptr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Deallocation
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] mptr[i][j];
        }
        delete[] mptr[i];
    }
    delete[] mptr;

}