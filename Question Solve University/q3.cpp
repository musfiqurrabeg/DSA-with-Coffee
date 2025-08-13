#include <bits/stdc++.h>

using namespace std;

int smallDiff (vector<int>& arr) {
    // sort(arr.begin(), arr.end());
    // Manual Sorting
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int minDiff = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;

}

int main() {
    vector<int> a1 = {15, 7, 2, 12, 13};
    vector<int> a2 = {2, 13, 11, 19, 5};

    int result1 = smallDiff(a1);
    int result2 = smallDiff(a2);
    cout << "Smallest difference: " << result1 << endl;
    cout << "Smallest difference: " << result2 << endl;

    return 0;
}