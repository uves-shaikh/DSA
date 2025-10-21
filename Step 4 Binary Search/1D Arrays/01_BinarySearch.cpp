#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Performs Binary Search recursively on a sorted array.
 *
 * This function divides the search range recursively until the target element
 * is found or the range becomes invalid.
 *
 * Example:
 * ```
 * Input: nums = [1, 3, 5, 7, 9], target = 5
 * Output: 2  (0-based index)
 * ```
 *
 * @param nums Reference to a sorted vector of integers.
 * @param target The value to search for.
 * @param low Starting index of the current search range.
 * @param high Ending index of the current search range.
 * @return Index of the target if found, otherwise -1.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) (due to recursive stack)
 */
int binarySearchRecursive(vector<int> &nums, int target, int low, int high)
{
    if (low > high)
        return -1; // Base case: element not found

    int mid = low + (high - low) / 2; // Prevents potential overflow

    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return binarySearchRecursive(nums, target, mid + 1, high);
    else
        return binarySearchRecursive(nums, target, low, mid - 1);
}

/**
 * @brief Performs Binary Search iteratively on a sorted array.
 *
 * This approach eliminates recursive calls and uses a simple loop
 * to repeatedly divide the search interval.
 *
 * Example:
 * ```
 * Input: nums = [2, 4, 6, 8, 10], target = 8
 * Output: 3  (0-based index)
 * ```
 *
 * @param nums Reference to a sorted vector of integers.
 * @param target The value to search for.
 * @return Index of the target if found, otherwise -1.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int binarySearchIterative(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Element not found
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

    cout << "Enter target: ";
    cin >> target;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (sorted):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Chhose Method
    // int index = binarySearchRecursive(arr, target, 0, n - 1);
    int index = binarySearchIterative(arr, target);

    cout << "\n[Iterative] Element found at index: " << index << endl;

    return 0;
}
