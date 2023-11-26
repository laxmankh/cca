#include <iostream>
#include <vector>
using namespace std;
struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(vector<int> &arr, int low, int high) {
    MinMax result, left, right;

    // If there is only one element in the sub-array, it is both the minimum and maximum.
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // If there are two elements in the sub-array, compare them and return the result.
    if (high == low + 1) {
        result.min = min(arr[low], arr[high]);
        result.max = max(arr[low], arr[high]);
        return result;
    }

    int mid = (low + high) / 2;

    // Recursively find the minimum and maximum in the left and right sub-arrays.
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Combine the results from the left and right sub-arrays.
    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);

    return result;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    int n = arr.size();
    MinMax ans = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << ans.min << endl;
    cout << "Maximum element: " << ans.max << endl;

    return 0;
}

/*#include<iostream>
#include<vector>
using namespace std;
struct min_max
{
    int min,max;
};
min_max findMinMax(vector<int>&arr,int low,int high)
{
    min_max result,left,right;
    if(low==high)
    {
        result.min=arr[low];
        result.max=arr[low];
    }
    if(low=high-1)
    {
        result.min=min(arr[low],arr[high]);
        result.max=max(arr[low],arr[high]);
    }
    int mid=low+high/2;
    left=findMinMax(arr,low,mid);
    right=findMinMax(arr,mid+1,high);

    result.min=min(left.min,right.min);
    result.max=max(right.max,left.max);

    return result;
}
int main()
{
    vector<int> arr;
    int size,num;
    cout<<"Enter the Size of Array:";
    cin>>size;
    cout<<"Enter the Elemenys in array:";
    for(int i=0;i<size;i++)
    {
        cin>>num;
        arr.push_back(num);
    }
    cout<<"Original Array:";
    for(auto num:arr)
    {
        cout<<num<<" ";
    }
    int n = arr.size();
    min_max result = findMinMax(arr, 0, n - 1);
    cout<<"The maximmum number:"<<result.max<<endl;
    cout<<"The minimum number:"<<result.min<<endl;
    return 0;
}*/
