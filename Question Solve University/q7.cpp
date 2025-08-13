#include <iostream>
#include <vector>
using namespace std;

// Function to find longest consecutive subsequence after sorting
int longestConsecutiveSubsequence(vector<int> arr) {
    // Step 1: Sort (Bubble sort for simplicity, can use std::sort)
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Step 2: Find longest consecutive sequence
    int longest = 1, currentLen = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1] + 1) {
            currentLen++;
        } 
        else if (arr[i] != arr[i - 1]) { // skip duplicates
            currentLen = 1;
        }
        if (currentLen > longest) {
            longest = currentLen;
        }
    }

    return longest;
}

int main() {
    vector<int> a1 = {1, 9, 3, 10, 4, 20, 2};
    vector<int> a2 = {3, 1};

    cout << longestConsecutiveSubsequence(a1) << endl; // Output: 4
    cout << longestConsecutiveSubsequence(a2) << endl; // Output: 1

    return 0;
}
