#include <bits/stdc++.h>
using namespace std;

/**
 * Partition function for QuickSort
 *
 * Rearranges elements in the range [low..high] around a pivot such that:
 * - Elements <= pivot are moved to the left
 * - Elements > pivot are moved to the right
 *
 * @param arr  Reference to array
 * @param low  Starting index of subarray
 * @param high Ending index of subarray
 * @return     Final position of the pivot
 */
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // Choose first element as pivot
    int i = low;
    int j = high;

    // Move i forward and j backward until they cross
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    // Place pivot in correct position
    swap(arr[low], arr[j]);
    return j;
}

/**
 * QuickSort algorithm (recursive)
 *
 * @param arr  Reference to array
 * @param low  Starting index
 * @param high Ending index
 */
void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high) // Base case: 1 or 0 elements
        return;

    int pivotIndex = partition(arr, low, high);
    quickSort(arr, low, pivotIndex - 1);  // Sort left partition
    quickSort(arr, pivotIndex + 1, high); // Sort right partition
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

    quickSort(arr, 0, n - 1);

    cout << "Array after sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
