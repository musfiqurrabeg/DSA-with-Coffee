#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to sort array by frequency
vector<int> sortByFrequency(vector<int> arr) {
    unordered_map<int, int> freq;
    vector<int> result;

    // Step 1: Count frequency
    for (int num : arr) {
        freq[num]++;
    }

    // Step 2: Pick elements until map is empty
    while (!freq.empty()) {
        int maxFreq = 0;
        int candidate = 0;

        // Find element with max frequency (and smallest value if tie)
        for (auto &p : freq) {
            if (p.second > maxFreq || (p.second == maxFreq && p.first < candidate)) {
                maxFreq = p.second;
                candidate = p.first;
            }
        }

        // Add it maxFreq times to result
        for (int i = 0; i < maxFreq; i++) {
            result.push_back(candidate);
        }

        // Remove from map
        freq.erase(candidate);
    }

    return result;
}

int main() {
    vector<int> a = {4, 3, 1, 6, 1, 3, 4, 4};

    vector<int> sortedArr = sortByFrequency(a);

    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
