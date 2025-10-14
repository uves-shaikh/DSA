#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Merges two sorted halves of an array while counting inversions.
 *
 * An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].
 * During merging, when an element from the right half is smaller than
 * an element from the left half, it indicates that all remaining elements
 * in the left half will form inversions with that right element.
 *
 * Example:
 * ```
 * Left: [2, 3, 8]
 * Right: [6, 7]
 * Inversions: (8, 6), (8, 7)
 * ```
 *
 * @param arr Pointer to the array.
 * @param low Starting index of the subarray.
 * @param mid Middle index (end of left subarray).
 * @param high Ending index of the subarray.
 * @return The number of inversions found during merging.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
long long merge(long long *arr, int low, int mid, int high)
{
    vector<long long> sortedArray;
    long long cnt = 0;
    int left = low, right = mid + 1;

    // Merge both halves while counting inversions
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            sortedArray.push_back(arr[left++]);
        }
        else
        {
            sortedArray.push_back(arr[right++]);
            cnt += (mid - left + 1); // Count inversions
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

    return cnt;
}

/**
 * @brief Recursive Merge Sort function that counts inversions in an array.
 *
 * It divides the array into halves, recursively counts inversions in each half,
 * and merges them while counting cross-inversions.
 *
 * @param arr Pointer to the array.
 * @param low Starting index.
 * @param high Ending index.
 * @return Total number of inversions in the subarray arr[low..high].
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
long long mergeSort(long long *arr, int low, int high)
{
    long long cnt = 0;
    if (low >= high)
        return cnt; // Base case: single element

    int mid = low + (high - low) / 2;
    cnt += mergeSort(arr, low, mid);      // Count inversions in left half
    cnt += mergeSort(arr, mid + 1, high); // Count inversions in right half
    cnt += merge(arr, low, mid, high);    // Count cross inversions
    return cnt;
}

/**
 * @brief Returns the total number of inversions in an array.
 *
 * Wrapper function that calls merge sort.
 *
 * @param arr Pointer to the array.
 * @param n Size of the array.
 * @return Total inversion count.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    long long arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    long long result = getInversions(arr, n);

    cout << "\nTotal Number of Inversions: " << result << endl;

    return 0;
}
