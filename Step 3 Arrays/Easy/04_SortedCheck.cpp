#include <bits/stdc++.h>
using namespace std;

/**
 * Utility function to check if an array is sorted in non-decreasing order.
 *
 * @param nums The input array
 * @return     True if sorted, otherwise false
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool isSorted(const vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            return false;
    }
    return true;
}

/**
 * Brute-force approach to check if array is sorted and rotated.
 * - Rotate the array one by one and check if it becomes sorted.
 *
 * @param nums The input array
 * @return     True if the array is sorted and rotated, otherwise false
 *
 * Time Complexity: O(n^2) (n rotations × O(n) sorted check)
 * Space Complexity: O(n) for rotated copies
 */
bool isSortedAndRotatedBrute(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> rotated = nums;

    // Try all rotations
    for (int r = 0; r < n; r++)
    {
        if (isSorted(rotated))
            return true;

        // Rotate left by 1
        rotate(rotated.begin(), rotated.begin() + 1, rotated.end());
    }

    return false;
}

/**
 * Optimal approach to check if array is sorted and rotated.
 * - Count number of "drops" (nums[i] > nums[i+1])
 * - If drops > 1, it's not sorted & rotated
 *
 * @param nums The input array
 * @return     True if the array is sorted and rotated, otherwise false
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool isSortedAndRotatedOptimal(const vector<int> &nums)
{
    int n = nums.size();
    int count = 0; // counts drops

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i + 1) % n])
        {
            count++;
        }

        if (count > 1)
            return false;
    }

    return true;
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

    bool bruteResult = isSortedAndRotatedBrute(arr);
    bool optimalResult = isSortedAndRotatedOptimal(arr);

    cout << boolalpha;
    cout << "Brute-force result: " << bruteResult << endl;
    cout << "Optimal result: " << optimalResult << endl;

    return 0;
}
