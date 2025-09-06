#include <bits/stdc++.h>
using namespace std;

/**
 * Recursive Insertion Sort
 *
 * @param arr  Reference to the vector to be sorted
 * @param n    Total size of the array
 * @param idx  Current index being processed
 *
 * This function places arr[idx] into its correct position
 * among the already sorted subarray arr[0..idx-1].
 */
void insertionRecursiveSort(vector<int> &arr, int n, int idx)
{
    // Base case: If all elements are processed
    if (idx == n)
        return;

    // Place arr[idx] in the correct position in the sorted subarray [0..idx-1]
    int j = idx;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        swap(arr[j - 1], arr[j]);
        j--;
    }

    // Recursive call for the next index
    insertionRecursiveSort(arr, n, idx + 1);
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

    cout << "Array before sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    insertionRecursiveSort(arr, n, 0);

    cout << "Array after sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
