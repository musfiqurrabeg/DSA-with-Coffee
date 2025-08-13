#include <iostream>
#include <vector>
using namespace std;

vector<string> sortLength(vector<string>& arr) {
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].length() > arr[j].length()) {
                swap(arr[i], arr[j]);
            }
        }
    }
    
    return arr;
}

int main() {
    vector<string> words = {"apple", "bat", "carrot", "dog"};
    vector<string> sortedWords = sortLength(words);

    for (const string& word : sortedWords) {
        cout << word << " ";
    }
    return 0;
}