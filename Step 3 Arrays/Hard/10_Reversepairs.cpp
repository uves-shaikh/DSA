#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Merges two sorted halves of an array.
 *
 * This helper function merges two sorted subarrays `[low...mid]` and `[mid+1...high]`
 * into a single sorted segment. It is used as part of the Merge Sort algorithm.
 *
 * @param arr Reference to the input array.
 * @param low Starting index of the first subarray.
 * @param mid Middle index where the array is divided.
 * @param high Ending index of the second subarray.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> sortedArray;
    int left = low, right = mid + 1;

    // Merge two sorted halves
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            sortedArray.push_back(arr[left++]);
        else
            sortedArray.push_back(arr[right++]);
    }

    // Copy remaining elements
    while (left <= mid)
        sortedArray.push_back(arr[left++]);
    while (right <= high)
        sortedArray.push_back(arr[right++]);

    // Write back to original array
    for (int i = low; i <= high; i++)
        arr[i] = sortedArray[i - low];
}

/**
 * @brief Counts the number of reverse pairs in a given subarray.
 *
 * A reverse pair is defined as a pair `(i, j)` where:
 * ```
 * i < j and arr[i] > 2 * arr[j]
 * ```
 * This function counts such pairs across the two sorted halves `[low...mid]` and `[mid+1...high]`.
 *
 * @param arr Reference to the input array.
 * @param low Starting index of the first half.
 * @param mid Middle index dividing the two halves.
 * @param high Ending index of the second half.
 * @return The number of reverse pairs between the two halves.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int countReversePairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid + 1;

    // Count valid reverse pairs
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && (long long)arr[i] > 2LL * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }

    return cnt;
}

/**
 * @brief Performs merge sort while counting reverse pairs.
 *
 * This recursive function sorts the array and simultaneously counts
 * the total number of reverse pairs using the modified merge step.
 *
 * @param arr Reference to the input array.
 * @param low Starting index of the current segment.
 * @param high Ending index of the current segment.
 * @return Total number of reverse pairs in the segment.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
int mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;
    int cnt = 0;

    // Recursive calls for both halves
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);

    // Count cross-pairs and merge
    cnt += countReversePairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return cnt;
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

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    long long result = mergeSort(arr, 0, n - 1);

    cout << "\nTotal Number of Reverse Pairs: " << result << endl;

    return 0;
}
