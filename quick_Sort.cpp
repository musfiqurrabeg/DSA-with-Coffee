#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int index = low - 1, pivot = arr[high];

    for(int i=low; i<high; i++) {
        if(arr[i] <= pivot){ // Ascending Order Condition
            index++;
            swap(arr[i], arr[index]);
        }
    }

    index++;
    swap(arr[high], arr[index]);
    return index;
}


void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


int main() {

    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);

    for(int value: arr) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}