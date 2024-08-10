#include <iostream>
using namespace std;

// REF : https://www.geeksforgeeks.org/selection-sort/
// NOTES :
//      Find the max in first pass, put it at the last place (swap it).
//      Find the second max now in second pass, put it at second last place & continue.
//      OR Do the reverse. Find the min and put it at the first place (swap it) & continue.
//      And loop conditions will change as per these logics.
//      Visualization - https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/visualize/

// O(T) : O(n^2) Avg case
// O(S) : O(1)

void selectionSort(int arr[], int N) {
    int min;
    for (int i = 0; i < N - 1; i++) {
        
        min = i;                            // Take backup of min index
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
            swap(arr[min], arr[i]);         // swap it
    }
}

int main() {
    int arr[] = {4,9,6,3,2,7};
    int N = sizeof(arr)/sizeof(arr[0]);
    
    selectionSort(arr, N);
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}