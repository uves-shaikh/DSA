#include <bits/stdc++.h>
using namespace std;

/**
 * Function: insertionSort
 * -----------------------
 * Sorts the array using Insertion Sort algorithm.
 *
 * Idea:
 *   - Treat first element as sorted.
 *   - Pick each element and insert it into the correct position in the sorted part.
 *
 * Time Complexity:
 *   - Best: O(n)   (already sorted)
 *   - Worst: O(n^2) (reverse sorted)
 *   - Average: O(n^2)
 * Space Complexity: O(1) (in-place sorting)
 *
 * @param arr - input array (vector<int>)
 * @param n   - size of the array
 */
void insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++) // Start from 2nd element
    {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at its correct position
        arr[j + 1] = key;
    }
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

    insertionSort(arr, n);

    cout << "Array after sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
