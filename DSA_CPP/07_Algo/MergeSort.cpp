#include <iostream>
using namespace std;

// REF : https://www.sanfoundry.com/cpp-program-implement-merge-sort/
// NOTES :
//      Divide & Conquer approach
//      Visualization - https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/visualize/

// O(T) : O(nlogn) Avg case
// O(S) : O(n) due to temp array

void mergeArr(int arr[], int low, int mid, int high) {
    int temp[high - low + 1];
    int k = 0;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {     // merge two arrays
        
        if (arr[i] < arr[j]) {          // compare elements of two different arrays
            temp[k] = arr[i];           // put the smaller one
            k++;
            i++;
        }
        else {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {                  // copy remaining elements of array 1
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high) {                  // copy remaining elements of array 2
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++)       // copy temp array back to orig array
    {
        arr[i] = temp[i-low];
    }
}

void mergeSort(int arr[], int low, int high) {

    if (low < high) {
        
        int mid = (low + high) / 2;
        
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        mergeArr(arr, low, mid, high);      // Merge sorted arrays into single array
                                            // we can copy from temp to orig array here also
                                            // But need to pass it becuase it's created inside mergeArr
    }
}

int main() {
    int arr[] = {4,9,6,3,2,7};
    int N = sizeof(arr)/sizeof(arr[0]);
    
    mergeSort(arr, 0, N - 1);
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}