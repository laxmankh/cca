#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Jump search function
int jumpSearch(const vector<int>& arr, int key) {
    int n = arr.size();
    
    // Define the jump size (sqrt of array length)
    int jump = sqrt(n);
    
    // Initialize the starting and ending indices for the current block
    int start = 0;
    int end = jump;

    // Jump through blocks
    while (end < n && arr[end] < key) {
        start = end;
        end += jump;
    }

    // Linear search in the current block
    for (int i = start; i <= min(end, n - 1); ++i) {
        if (arr[i] == key) {
            return i; // Element found
        }
    }

    return -1; // Element not found
}

int main() {
    // Example usage
    vector<int> sortedArray = {1, 4, 8, 13, 20, 28, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int index = jumpSearch(sortedArray, key);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
