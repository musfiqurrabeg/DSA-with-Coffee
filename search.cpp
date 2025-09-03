#include <iostream>
using namespace std;

// array of size n.
// find key in that array using linear search and binary search.

// Linear search on an array
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // key is Found
    }
    return -1; // key is Not found
}

// Binary search on a sorted array
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid; // Found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

// Recursive binary search
int binarySearchRecursive(int arr[], int low, int high, int key) {
    int mid = (low + high) / 2;
    if(arr[mid] == key) {
        return mid; // Found
    } else if (arr[mid] < key) {
        return binarySearchRecursive(arr, mid + 1, high, key);
    } else {
        return binarySearchRecursive(arr, low, mid - 1, key);
    }
}

int main() {
    int arr[] = {3}; // Sorted for binary search
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, choice;

    cout << "Enter element to search: ";
    cin >> key;

    int result;

    //result = linearSearch(arr, n, key);

    result = binarySearch(arr, n, key);


    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}