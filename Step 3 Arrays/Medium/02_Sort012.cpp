#include <bits/stdc++.h>
using namespace std;

/*
 * Function: sortArrayWithBetter
 * ------------------------------
 * Sorts an array containing only 0s, 1s, and 2s
 * using the counting approach.
 *
 * Time Complexity: O(n) + O(n) = O(n)
 * Space Complexity: O(1)
 */
void sortArrayWithBetter(vector<int> &arr, int n)
{
    int countZero = 0, countOne = 0, countTwo = 0;

    // Count the number of 0s, 1s, and 2s
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            countZero++;
        else if (arr[i] == 1)
            countOne++;
        else
            countTwo++;
    }

    // Fill the array based on counts
    for (int i = 0; i < countZero; i++)
        arr[i] = 0;

    for (int i = countZero; i < countZero + countOne; i++)
        arr[i] = 1;

    for (int i = countZero + countOne; i < n; i++)
        arr[i] = 2;
}

/*
 * Function: sortArrayWithOptimal
 * -------------------------------
 * Sorts an array containing only 0s, 1s, and 2s
 * using the Dutch National Flag algorithm (3-way partitioning).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void sortArrayWithOptimal(vector<int> &arr, int n)
{
    int low = 0;      // boundary for 0s
    int mid = 0;      // current element
    int high = n - 1; // boundary for 2s

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else // arr[mid] == 2
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
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
        cout << "Enter element " << i + 1 << " (must be 0, 1, or 2): ";
        cin >> arr[i];
    }

    // Choose which approach to run:
    // sortArrayWithBetter(arr, n);
    sortArrayWithOptimal(arr, n);

    cout << "Array after sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
