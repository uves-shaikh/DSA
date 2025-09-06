#include <bits/stdc++.h>
using namespace std;

/**
 * Function: selectionSort
 * -----------------------
 * Sorts the array using the Selection Sort algorithm.
 *
 * Time Complexity:
 *   - Best, Average, Worst: O(n^2)
 *   - Space: O(1) (in-place sorting)
 *
 * @param arr - vector of integers to be sorted
 * @param n   - size of the array
 */
void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++) // last element will already be sorted
    {
        int minIndex = i; // assume the minimum is at position i

        // find index of minimum element in the remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swap if a smaller element was found
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
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

    selectionSort(arr, n);

    cout << "Array after sorting: ";
    for (int num : arr)
        cout << num << " ";

    cout << endl;

    return 0;
}
