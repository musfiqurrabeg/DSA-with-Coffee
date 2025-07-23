#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n){
    for (int i = 0; i < n; i++) {
        int minimum = arr[i], position = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < minimum) {
                minimum = arr[j];
                position = j;
            }
        }
        swap(arr[i], arr[position]);
    }
}

void BubbleSort(int arr[], int n) {
    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < i; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// void InsertionSort(int arr[], int n){
//     for (int i = 1; i < n; i++){
//         for (int j = i+1; arr[j] < arr[j-1]; j--){
//             swap(arr[j], arr[j-1]);
//         }
//     }
// }

void InsertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        for (int j = i+1; j > 0 && arr[j] < arr[j-1]; j--){
            swap(arr[j], arr[j-1]);
        }
    }
}

int main() {
    
    int arr[10] = {3, 3, 5, 0, 9, 1, 7, 0, 0, 5};
    // SelectionSort(arr, 10);
    // BubbleSort(arr, 10);
    InsertionSort(arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}