#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the upper bound index of a target using recursion.
 *
 * The upper bound is defined as the smallest index `i` such that nums[i] > target.
 * If no such element exists, returns nums.size().
 *
 * Example:
 * nums = [1, 3, 5, 7, 9], target = 5  → upper bound index = 3 (element 7)
 *
 * @param nums Reference to the sorted array.
 * @param target The target value.
 * @param low Lower index bound for the current recursive call.
 * @param high Upper index bound for the current recursive call.
 * @return The index of the upper bound, or nums.size() if not found.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)  (recursive call stack)
 */
int binarySearchWithRecursive(vector<int> &nums, int target, int low, int high)
{
    if (low > high)
        return nums.size(); // If not found, return n

    int mid = (low + high) / 2;

    if (nums[mid] > target)
    {
        // Candidate for upper bound — check if there's a smaller valid index
        return min(mid, binarySearchWithRecursive(nums, target, low, mid - 1));
    }
    else
    {
        // Continue searching in right half
        return binarySearchWithRecursive(nums, target, mid + 1, high);
    }
}

/**
 * @brief Finds the upper bound index of a target using iteration.
 *
 * The upper bound is defined as the smallest index `i` such that nums[i] > target.
 * If no such element exists, returns nums.size().
 *
 * Example:
 * nums = [1, 3, 5, 7, 9], target = 5  → upper bound index = 3 (element 7)
 *
 * @param nums Reference to the sorted array.
 * @param target The target value.
 * @return The index of the upper bound, or nums.size() if not found.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int binarySearchWithIterative(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int elementIndex = n; // Default to n if upper bound not found

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > target)
        {
            elementIndex = mid; // Possible answer
            high = mid - 1;     // Try to find smaller valid index
        }
        else
        {
            low = mid + 1; // Move right if nums[mid] <= target
        }
    }

    return elementIndex;
}

int main()
{
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter target: ";
    cin >> target;

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

    // Choose Method
    int index = binarySearchWithIterative(arr, target);
    // int index = binarySearchWithRecursive(arr, target, 0, n - 1);

    cout << "Upper bound index: " << index << endl;

    return 0;
}
