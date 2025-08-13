#include <iostream>
using namespace std;

// Function to sort tasks by duration using bubble sort
void sortTasksByDuration(int start[], int finish[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            int dur1 = finish[j] - start[j];
            int dur2 = finish[j+1] - start[j+1];
            if (dur1 > dur2) {
                // Swap start times
                int temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;

                // Swap finish times
                temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;
            }
        }
    }
}

int main() {
    int start[] = {2, 1, 4};
    int finish[] = {5, 2, 6};
    int n = sizeof(start)/sizeof(start[0]);

    sortTasksByDuration(start, finish, n);

    for (int i = 0; i < n; i++) {
        cout << "(" << start[i] << ", " << finish[i] << ") ";
    }
    cout << endl;

    return 0;
}
