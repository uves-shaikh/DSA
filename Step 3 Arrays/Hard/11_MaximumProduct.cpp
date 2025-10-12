#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the maximum product subarray in a given integer array.
 *
 * This function uses a **prefix and suffix product** approach to handle negative numbers and zeros.
 * - The prefix product is calculated from the left.
 * - The suffix product is calculated from the right.
 * - Whenever a product becomes zero, it's reset to 1 (as a new subarray start).
 *
 * Example:
 * ```
 * Input: [-2, 3, -4]
 * Output: 24
 * ```
 *
 * @param arr Reference to the input array of integers.
 * @param n Size of the array.
 * @return The maximum product of any contiguous subarray.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maximumProduct(vector<int> &arr, int n)
{
    int ans = INT_MIN;
    int prefix = 1, suffix = 1;

    for (int i = 0; i < n; i++)
    {
        // Reset product if zero encountered
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;

        prefix *= arr[i];         // prefix product from left
        suffix *= arr[n - i - 1]; // suffix product from right

        ans = max(ans, max(prefix, suffix)); // track maximum
    }

    return ans;
}

/**
 * @brief Driver function to compute and display the maximum product subarray.
 *
 * Handles user input, validates array size, and displays the final result.
 */
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

    int result = maximumProduct(arr, n);

    cout << "\nMaximum Product Subarray: " << result << endl;

    return 0;
}
