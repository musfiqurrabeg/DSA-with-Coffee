#include <iostream>
using namespace std;


// Function to perform Selection Sort
// Type -1
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

// ami jani na kisu.

// Type - 2
void selectionSort(int arr[], int n){ // O(n^2) time complexity
    // To store index of the minimum element
    int minIndex;

    // Outer loop
    for (int i = 0; i < (n - 1); i++){
        minIndex = i;
        
        // Inner loop
        for(int j = (i + 1); j < n; j++){
            if(arr[j] < arr[minIndex]) {
                minIndex = j;       // Update minIndex if a smaller element is found
            }
        }
        // Swap the found minimum with the first element of the unsorted part
        swap(arr[i], arr[minIndex]);
    }
}




// Function to perform Bubble Sort
// Type - 1:
void BubbleSort(int arr[], int n) {
    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < i; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Type - 2: 
void bubbleSort(int arr[], int n){ // O(n^2) time complexity
    // Traverse through all array elements
    bool isSwap = false;                // Flag to check if any swapping happens in a full pass
    
    // Outer loop runs n-1 times
    for(int i  = 0; i < (n - 1); i++){
        // Inner loop
        for(int j = 0; j < (n - i  - 1); j++){
            if(arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // If no swapping occurred in this entire pass, the array is already sorted.
        if(!isSwap){
            return;
        }
    }
}




// Function to perform Insertion Sort
// Type - 1
void InsertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        for (int j = i+1; j > 0 && arr[j] < arr[j-1]; j--){
            swap(arr[j], arr[j-1]);
        }
    }
}

// Type - 2
void insertionSort(int arr[], int n){   // O(n^2) time complexity

    // Loop over the unsorted part of the array starting from index 1
    for (int i = 1; i < n; i++) {
        int curr = arr[i];              // Current element to be inserted
        int prev = i - 1;               // Index of the previous element

        // Shift all elements that are greater than curr to one position ahead
        while(prev >=0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];  // Shift element to the right
            prev--;                     // Move to the previous index
        }

        // Insert the current element at its correct position
        arr[prev + 1] = curr;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    SelectionSort(arr, 10);
    BubbleSort(arr, 10);
    InsertionSort(arr, 10);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    cout << endl;
    
    return 0;
}
