#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the missing and repeating numbers in an array.
 *
 * Given an array of size `n` containing numbers from `1` to `n`, where:
 * - One number is missing
 * - One number is repeated
 *
 * This function uses a hash array to track frequencies of each element.
 *
 * Example:
 * ```
 * Input: [3, 1, 2, 5, 3]
 * Output: Missing = 4, Repeating = 3
 * ```
 *
 * @param arr Reference to the input array.
 * @param n Size of the array.
 * @return A pair of integers `{missing, repeating}`.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    vector<int> hashArray(n + 1, 0);
    int missing = -1, repeating = -1;

    // Step 1: Count frequency of each element
    for (int i = 0; i < n; i++)
    {
        hashArray[arr[i]]++;
    }

    // Step 2: Identify missing (0 count) and repeating (count = 2)
    for (int i = 1; i <= n; i++)
    {
        if (hashArray[i] == 0)
            missing = i;
        else if (hashArray[i] == 2)
            repeating = i;

        if (missing != -1 && repeating != -1)
            break;
    }

    return {missing, repeating};
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

    pair<int, int> result = missingAndRepeating(arr, n);

    cout << "\nMissing and Repeating Numbers:\n";
    cout << "Missing: " << result.first << "\nRepeating: " << result.second << endl;

    return 0;
}
