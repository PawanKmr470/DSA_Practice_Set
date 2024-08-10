#include <iostream>
using namespace std;

// REF : https://www.geeksforgeeks.org/bubble-sort-in-cpp/
// NOTES :
//      Compare & swap (if required) two elements in each pass
//      https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/visualize/

// O(T) : O(n^2) Avg case
// O(S) : O(1)
void bubbleSort(int arr[], int N) {

    // To access elements loop runs till i < N
    // For swapping it will run till i < N -1

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);       // Keep swapping adjacent elements
            }
        }
    }
}

// Optimized
// O(T) : O(n^2) Avg case & O(n) for Best case (sorted array)
// O(S) : O(1)
void bubbleSort_Optimized(int arr[], int N) {

    bool swapped;

    for (int i = 0; i < N - 1; i++) {
        swapped = false;
        for (int j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            cout << "breaking loop..." << endl;
            break;
        }
    }
}

int main() {
    int arr[] = {4,9,6,3,2,7};
    int N = sizeof(arr)/sizeof(arr[0]);
    
    bubbleSort(arr, N);
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    // int arr1[] = {2,4,3,6,7,9};
    int arr1[] = {4,9,6,3,2,7};
    int N1 = sizeof(arr1)/sizeof(arr1[0]);
    
    bubbleSort_Optimized(arr1, N1);

    for (int i = 0; i < N1; i++) {
        cout << arr1[i] << " ";
    }

    cout << endl;
}