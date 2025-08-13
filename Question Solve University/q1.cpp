#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    // Check for invalid k
    if (k <= 0 || k > arr.size()) {
        return INT_MAX;
    }

    int ans = 0;
    vector<int> temp = arr;

    for (int i = 0; i < k; i++) {
        int minIndex = -1;
        int minValue = INT_MAX;

        // Find the smallest element
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] < minValue) {
                minValue = temp[j];
                minIndex = j;
            }
        }

        // Store the current smallest
        ans = minValue;
        if (minIndex != -1) {
            temp[minIndex] = INT_MAX;
        }
    }

    return ans; // kth smallest element
}

int main() {
    vector<int> a1 = {6, 5, 1, 3, 4};
    vector<int> a2 = {7, 9, 1, 8, 2};
    
    int k1 = 2;
    int k2 = 4;

    cout << k1 << "-th smallest value: " << kthSmallest(a1, k1) << endl;
    cout << k2 << "-th smallest value: " << kthSmallest(a2, k2) << endl;
    
    return 0;
}