#include<iostream>
#include<vector>
#include<climits>
using namespace std;

double findMedian(vector<int>& arr) {
    int n = arr.size();
    
    if (n == 0) {
        return 0;
    }

    // Manual bubble sort
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    if (n % 2 != 0)         // odd
        return arr[n / 2];
    else                    // even
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    
}

int main() {
    vector<int> a1 = {5, 2, 1, 4, 7};
    vector<int> a2 = {11, 9, 17, 15};

    cout << "Median of a1: " << findMedian(a1) << endl;
    cout << "Median of a2: " << findMedian(a2) << endl;
    
    return 0;
}