#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Merges two sorted arrays in-place using the simple swap + sort approach.
 *
 * Logic:
 * - Compare largest elements from `nums1` and smallest from `nums2`.
 * - Swap if out of order, then sort both arrays.
 *
 * @param nums1 First sorted array (size m)
 * @param m Number of elements in nums1
 * @param nums2 Second sorted array (size n)
 * @param n Number of elements in nums2
 *
 * Time Complexity: O((m + n) log(m + n)) due to sorting after swaps.
 * Space Complexity: O(1)
 */
void mergeSwapSort(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = m - 1;
    int right = 0;

    // Swap elements that are out of order
    while (left >= 0 && right < n)
    {
        if (nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }
        else
            break;
    }

    // Sort both arrays again
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

/**
 * @brief Swaps elements if the element in nums1 is greater than nums2.
 */
void swapIfGreater(vector<int> &nums1, vector<int> &nums2, int idx1, int idx2)
{
    if (nums1[idx1] > nums2[idx2])
    {
        swap(nums1[idx1], nums2[idx2]);
    }
}

/**
 * @brief Merges two sorted arrays without extra space using the Gap method.
 *
 * Logic:
 * - Use a variable `gap = ceil((n + m) / 2)`.
 * - Compare elements at distance `gap` apart.
 * - Reduce gap until it becomes 1.
 *
 * @param nums1 First sorted array (size n)
 * @param n Number of elements in nums1
 * @param nums2 Second sorted array (size m)
 * @param m Number of elements in nums2
 *
 * Time Complexity: O((n + m) * log(n + m))
 * Space Complexity: O(1)
 */
void mergeWithGap(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < len)
        {
            if (left < n && right >= n)
            {
                swapIfGreater(nums1, nums2, left, right - n);
            }
            else if (left >= n)
            {
                swapIfGreater(nums2, nums2, left - n, right - n);
            }
            else
            {
                swapIfGreater(nums1, nums1, left, right);
            }
            left++;
            right++;
        }

        if (gap == 1)
            break;

        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    int n, m;
    cout << "Enter the size of the first array: ";
    cin >> n;

    cout << "Enter the size of the second array: ";
    cin >> m;

    if (n <= 0 && m <= 0)
    {
        cout << "Array sizes must be positive." << endl;
        return 1;
    }

    vector<int> arr1(n), arr2(m);

    cout << "Enter " << n << " elements for array 1:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr1[i];
    }

    cout << "Enter " << m << " elements for array 2:\n";
    for (int i = 0; i < m; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr2[i];
    }

    // Choose approach:
    // mergeSwapSort(arr1, n, arr2, m);
    mergeWithGap(arr1, n, arr2, m);

    cout << "\nAfter merging:\n";
    cout << "Array 1: ";
    for (int val : arr1)
        cout << val << " ";

    cout << "\nArray 2: ";
    for (int val : arr2)
        cout << val << " ";

    cout << endl;

    return 0;
}
