/*If the we consider the pivot is the last element of array:*/
#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot element in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find the pivot element such that element smaller than the pivot
        // are on the left and elements greater than the pivot are on the right
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{
    vector<int> arr;
    int size,num;
    cout<<"Enter the size of array:";
    cin>>size;
    cout<<"Enter the array elements\n";
    for(int i=0;i<size;i++)
    {
        cout<<"element_"<<i<<":";
        cin>>num;
        arr.push_back(num);
    }
    cout << "Original array: ";
    for (auto num : arr) {
        cout << num << " ";
    }

    // Call QuickSort
    quickSort(arr, 0, arr.size() - 1);

    cout << "\nSorted array: ";
    for (auto num : arr) {
         cout << num << " ";
    }

    return 0;
}