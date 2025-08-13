#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortAbs (vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i]) > abs(arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main() {
    vector<int> a = {15, 7, 2, 12, 13};
    

    for(int value : sortAbs(a)) {
        cout << value << " ";
    }
}