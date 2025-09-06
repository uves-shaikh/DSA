#include <bits/stdc++.h>
using namespace std;

/**
 * Function: bubbleSort
 * --------------------
 * Sorts the array using Bubble Sort algorithm.
 *
 * Optimization:
 *  - Stops early if no swaps are made in a full pass (already sorted).
 *
 * Time Complexity:
 *   - Best: O(n)  (already sorted, early stop)
 *   - Worst: O(n^2)
 *   - Average: O(n^2)
 * Space Complexity: O(1) (in-place sorting)
 *
 * @param arr - input array (vector<int>)
 * @param n   - size of the array
 */
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++) // n-1 passes at most
    {
        bool didSwap = false; // track if any swap happened

        // inner loop runs until (n-i-1), last i elements already sorted
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }

        // if no swaps, array is sorted → break early
        if (!didSwap)
            break;
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

    bubbleSort(arr, n);

    cout << "Array after sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
