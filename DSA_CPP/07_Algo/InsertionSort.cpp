#include <iostream>
using namespace std;

// REF : https://www.scaler.com/topics/insertion-sort-in-cpp/
// NOTES :
//      For element at ith position, keep comparing with ith - 1 till 0th position.
//      wherever it fits swap with it.
//      Visualization - https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/visualize/

// O(T) : O(n^2) Avg case
// O(S) : O(1)

void insertionSort(int arr[], int N) {
    int j, key;

    for (int i = 1; i < N; i++) {
        key = arr[i];                                   // take back up before swapping
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];                        // shift element right
        }
        arr[j + 1] = key;                               // now swap it
    }
}

int main() {
    int arr[] = {4,9,6,3,2,7};
    int N = sizeof(arr)/sizeof(arr[0]);
    
    insertionSort(arr, N);
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}