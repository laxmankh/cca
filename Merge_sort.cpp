#include <iostream>
using namespace std;
#include <vector>

// Merge two sorted subarrays into a single sorted subarray
void merge( vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays to store the two halves
     vector<int> leftHalf(n1);
     vector<int> rightHalf(n2);

    // Copy data to temporary arrays leftHalf[] and rightHalf[]
    for (int i = 0; i < n1; i++)
        leftHalf[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightHalf[i] = arr[middle + 1 + i];

    // Merge the two arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftHalf[i] <= rightHalf[j]) {
            arr[k] = leftHalf[i];
            i++;
        } else {
            arr[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftHalf[], if any
    while (i < n1) {
        arr[k] = leftHalf[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightHalf[], if any
    while (j < n2) {
        arr[k] = rightHalf[j];
        j++;
        k++;
    }
}

// Recursive function to perform Merge Sort on the array
void mergeSort( vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
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
    for (int num : arr) {
        cout << num << " ";
    }

    // Call mergeSort
    mergeSort(arr, 0, arr.size() - 1);

    cout << "\nSorted array: ";
    for (int num : arr) {
         cout << num << " ";
    }

    return 0;
}


#include <iostream>
using namespace std;
#include <vector>

// Merge two sorted subarrays into a single sorted subarray
void merge( int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays to store the two halves
    //  vector<int> leftHalf(n1);
    //  vector<int> rightHalf(n2);
    int *leftHalf = new int[n1];
    int *rightHalf = new int[n2];

    // Copy data to temporary arrays leftHalf[] and rightHalf[]
    for (int i = 0; i < n1; i++)
        leftHalf[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightHalf[i] = arr[middle + 1 + i];

    // Merge the two arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftHalf[i] <= rightHalf[j]) {
            arr[k++] = leftHalf[i++];

        } else {
            arr[k++] = rightHalf[j++];
            
        }
    }

    // Copy the remaining elements of leftHalf[], if any
    while (i < n1) {
        arr[k++] = leftHalf[i++];

    }

    // Copy the remaining elements of rightHalf[], if any
    while (j < n2) {
        arr[k++] = rightHalf[j++];

    }
}

// Recursive function to perform Merge Sort on the array
void mergeSort( int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
    int arr[50];
    int size,num;
    cout<<"Enter the size of array:";
    cin>>size;
    cout<<"Enter the array elements\n";
    for(int i=0;i<size;i++)
    {
       cin>>arr[i];
    }


    // Call mergeSort
    mergeSort(arr, 0, size- 1);

    cout << "\nSorted array: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}