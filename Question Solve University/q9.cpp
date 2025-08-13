#include <iostream>
#include <vector>
using namespace std;

// Function to merge and sort arrays in non-decreasing order
vector<int> mergeAndSort(vector<int> a, vector<int> b) {
    vector<int> merged = a;

    // Append elements from b
    for (int x : b) {
        merged.push_back(x);
    }

    // Bubble sort
    for (int i = 0; i < merged.size() - 1; i++) {
        for (int j = 0; j < merged.size() - i - 1; j++) {
            if (merged[j] > merged[j + 1]) {
                int temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }

    return merged;
}

int main() {
    vector<int> a = {1, 16, 13, 14, 4};
    vector<int> b = {15, 12, 5, 3, 7};

    vector<int> result = mergeAndSort(a, b);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
