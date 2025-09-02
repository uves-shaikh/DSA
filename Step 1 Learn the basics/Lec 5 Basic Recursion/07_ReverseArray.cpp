#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively reverses an array in place.
 *
 * @param arr   The array to reverse.
 * @param left  Index of the current left element.
 * @param right Index of the current right element.
 *
 * Base case: Stop when left >= right (middle of array reached).
 * Recursive case: Swap arr[left] and arr[right], then move inward.
 *
 * Example:
 * Input:  [1, 2, 3, 4, 5]
 * Output: [5, 4, 3, 2, 1]
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursion stack)
 */
void reverseArray(int arr[], int left, int right)
{
    // Base case: stop when indices cross or meet
    if (left >= right)
        return;

    // Swap current pair
    swap(arr[left], arr[right]);

    // Recursive call for inner subarray
    reverseArray(arr, left + 1, right - 1);
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    // Validate array size
    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    // Using vector instead of VLA (C++ standard practice)
    vector<int> arr(n);

    // Input elements
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Print original array
    cout << "\nArray before reverse:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    // Reverse array using recursion
    reverseArray(arr.data(), 0, n - 1);

    // Print reversed array
    cout << "Array after reverse:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
