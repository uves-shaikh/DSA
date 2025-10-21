#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the insert position (index) of a target in a sorted array.
 *
 * This function performs a binary search to find:
 *  - If the target exists → returns its index.
 *  - Otherwise → returns the index where it should be inserted
 *    to maintain the sorted order.
 *
 * Example:
 * ```
 * Input: nums = [1, 3, 5, 6], target = 5
 * Output: 2
 *
 * Input: nums = [1, 3, 5, 6], target = 2
 * Output: 1
 * ```
 *
 * @param nums Sorted array of integers.
 * @param target Value to search or insert.
 * @return Index position where the target is or should be inserted.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int elementIndex = n; // default insert position (end of array)

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= target)
        {
            // Potential insert position found
            elementIndex = mid;
            high = mid - 1;
        }
        else
        {
            // Search right half
            low = mid + 1;
        }
    }

    return elementIndex;
}

int main()
{
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    int result = searchInsert(arr, target);

    cout << "\nTarget should be at position (0-indexed): " << result << endl;

    return 0;
}
