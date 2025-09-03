#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp;
    int i = start;
    int j = mid + 1;

    // Merge in Ascending Order
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++
        } else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    // // Merge in descending order
    // while(i <= mid && j <= end) {
    //     if(arr[i] >= arr[j]) {   // ✅ Descending
    //         temp.push_back(arr[i]);
    //         i++;
    //     } else {
    //         temp.push_back(arr[j]);
    //         j++;
    //     }
    // }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int index = 0; index < temp.size(); index++) {
        arr[index + start] = temp[index];
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    
    if(start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid); // left half
        mergeSort(arr, mid + 1, end); //right half
        merge(arr, start, mid, end);
    }
    
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    mergeSort(arr, 0, arr.size() - 1);

    for(int value : arr) {
        cout << value << " ";
    }
    cout << endl;
    
    return 0;
}