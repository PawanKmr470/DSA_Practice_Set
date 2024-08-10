#include <iostream>
using namespace std;

// REF : https://www.freecodecamp.org/news/quick-sort-algorithm-time-complexity-with-cpp-and-java-code/
// NOTES :
//      Pivot element is selected (solutions have taken the last element as pivot).
//      element < pivot --> left side
//      element > pivot --> right side
//      if first element is taken as pivot then we need to add +inf at the end
//      hence last element is preferred.
//      Visualization - https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/visualize/

// O(T) : O(nlogn) Avg case
// O(S) : O(1)

int partitionArr(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pos = partitionArr(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}

int main() {
    int arr[] = {4,9,6,3,2,7};
    int N = sizeof(arr)/sizeof(arr[0]);
    
    quickSort(arr, 0, N - 1);
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}