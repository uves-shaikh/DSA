#include <bits/stdc++.h>
using namespace std;

/**
 * Merge two sorted halves of arr[low..mid] and arr[mid+1..high]
 */
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> sortedArray;
    int left = low, right = mid + 1;

    // Merge both halves
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            sortedArray.push_back(arr[left++]);
        }
        else
        {
            sortedArray.push_back(arr[right++]);
        }
    }

    // Copy remaining elements
    while (left <= mid)
        sortedArray.push_back(arr[left++]);
    while (right <= high)
        sortedArray.push_back(arr[right++]);

    // Copy back into original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = sortedArray[i - low];
    }
}

/**
 * Recursive Merge Sort function
 */
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return; // Base case: 0 or 1 element

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);      // Sort left half
    mergeSort(arr, mid + 1, high); // Sort right half
    merge(arr, low, mid, high);    // Merge sorted halves
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nArray before sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Array after sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
