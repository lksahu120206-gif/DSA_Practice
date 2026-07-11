#include <iostream>
#include <vector>
#include <limits> // Required for clearing input streams

using namespace std;

int main() {
    // 1. Double check that fast I/O synchronization is completely deleted/commented out
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // 2. Clear any lingering broken flags or garbage bytes left inside your terminal's input stream
    cin.clear();
    
    int n = 0;
    cout << "Enter the size of the array: ";
    
    // Read the array size
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid input. Please enter a positive integer for size: ";
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad characters
    }

    // Allocate safe runtime memory heap vector
    vector<int> arr(n);

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i << "]: ";
        while (!(cin >> arr[i])) {
            cout << "Invalid number. Re-enter Element [" << i << "]: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Process the array calculations
    long long totalSum = 0; 
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    cout << "\n====================================\n";
    cout << "The cumulative sum of the array is: " << totalSum << "\n";
    cout << "====================================\n";
    
    return 0;
}