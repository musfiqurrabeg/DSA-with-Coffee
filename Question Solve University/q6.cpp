#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortOddEven(vector<int>& arr) {
    vector<int> odd, even;
    int evenIndex = 0, oddIndex = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            even.push_back(arr[i]);
        } else {
            odd.push_back(arr[i]);
        }
    }

    // // Sort even indexed elements ascending
    // sort(even.begin(), even.end());

    // // Sort odd indexed elements descending
    // sort(odd.begin(), odd.end(), greater<int>());

    // Sort even elements ascending
    for (int i = 0; i < (even.size()); i++) {
        for (int j = i + 1; j < (even.size()); j++) {
            if (even[i] > even[j]) {
                swap(even[i], even[j]);
            }
        }
    }

    // Sort odd elements descending
    for (int i = 0; i < (odd.size()); i++) {
        for (int j = i + 1; j < (odd.size()); j++) {
            if (odd[i] < odd[j]) {
                swap(odd[i], odd[j]);
            }
        }
    }

    
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            arr[i] = even[evenIndex++];
        } else {
            arr[i] = odd[oddIndex++];
        }
    }


}

int main() {

    vector<int> a = {16,17,4,18,1,20,5,12};
    sortOddEven(a);
    
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
    
    vector<int> b = {4,3,2,1};
    sortOddEven(b);

    for (int x : b) {
        cout << x << " ";
    }

    return 0;
}