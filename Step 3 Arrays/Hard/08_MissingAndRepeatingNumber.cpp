#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the missing and repeating numbers using Hashing (extra space approach).
 *
 * Given an array of size `n` containing numbers from `1` to `n`, where:
 * - One number is missing
 * - One number is repeated
 *
 * This approach uses a frequency array to count occurrences.
 *
 * Example:
 * ```
 * Input:  [3, 1, 2, 5, 3]
 * Output: Missing = 4, Repeating = 3
 * ```
 *
 * @param arr Reference to the input array.
 * @param n Size of the array.
 * @return A pair of integers {missing, repeating}.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
pair<int, int> missingAndRepeating_Hash(vector<int> &arr, int n)
{
    vector<int> hashArray(n + 1, 0);
    int missing = -1, repeating = -1;

    // Step 1: Count frequency of each element
    for (int i = 0; i < n; i++)
        hashArray[arr[i]]++;

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

/**
 * @brief Finds the missing and repeating numbers using Mathematical Equations (optimized approach).
 *
 * Uses two key relations:
 * - Difference of sums → (x - y)
 * - Difference of squared sums → (x² - y²)
 *
 * Solving these gives:
 * ```
 * x = (val1 + val2) / 2
 * y = x - val1
 * ```
 * where:
 * - x = repeating number
 * - y = missing number
 *
 * Example:
 * ```
 * Input:  [3, 1, 2, 5, 3]
 * Output: Missing = 4, Repeating = 3
 * ```
 *
 * @param arr Reference to the input array.
 * @param n Size of the array.
 * @return A pair of integers {missing, repeating}.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
pair<int, int> missingAndRepeating_Math(vector<int> &arr, int n)
{
    long long sumOfN = (1LL * n * (n + 1)) / 2;
    long long sumOfSquaredN = (1LL * n * (n + 1) * (2LL * n + 1)) / 6;

    long long sum = 0, squaredSum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        squaredSum += 1LL * arr[i] * arr[i];
    }

    long long val1 = sum - sumOfN;               // x - y
    long long val2 = squaredSum - sumOfSquaredN; // x² - y²
    val2 = val2 / val1;                          // (x + y)

    long long x = (val1 + val2) / 2; // repeating
    long long y = x - val1;          // missing

    return {(int)y, (int)x};
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

    // Choose Method
    pair<int, int> result = missingAndRepeating_Math(arr, n);
    // pair<int, int> result = missingAndRepeating_Hash(arr, n);
    cout << "Missing: " << result.first << "\nRepeating: " << result.second << endl;

    return 0;
}
