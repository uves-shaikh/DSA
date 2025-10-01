#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Linear search to check if an element exists in the array.
 *
 * @param elements Input array
 * @param n Size of array
 * @param x Target element
 * @return true if found, false otherwise
 *
 * Time Complexity: O(n)
 */
bool linearSearch(vector<int> &elements, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (elements[i] == x)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Brute force method to find longest consecutive sequence.
 *        For each element, linearly checks if next numbers exist.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
int longestConsecutiveBrute(vector<int> &elements, int n)
{
    int maxLength = 1;

    for (int i = 0; i < n; i++)
    {
        int currentLength = 1;
        int currentNum = elements[i];

        // Keep checking next consecutive numbers
        while (linearSearch(elements, n, currentNum + 1))
        {
            currentNum++;
            currentLength++;
            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
}

/**
 * @brief Better approach: Sort the array and count consecutive streaks.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(1) (ignoring sorting cost)
 */
int longestConsecutiveSorted(vector<int> &arr, int n)
{
    if (n == 0)
        return 0;

    sort(arr.begin(), arr.end());
    int maxLength = 1;
    int currentLength = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            currentLength++;
        }
        else if (arr[i] != arr[i - 1]) // ignore duplicates
        {
            currentLength = 1;
        }
        maxLength = max(maxLength, currentLength);
    }

    return maxLength;
}

/**
 * @brief Optimal approach: Use hash set to find sequence starts
 *        and expand consecutively.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int longestConsecutiveOptimal(vector<int> &arr, int n)
{
    if (n == 0)
        return 0;

    unordered_set<int> st(arr.begin(), arr.end());
    int maxLength = 1;

    for (auto num : st)
    {
        // Check if num is the start of a sequence
        if (st.find(num - 1) == st.end())
        {
            int currentNum = num;
            int currentLength = 1;

            while (st.find(currentNum + 1) != st.end())
            {
                currentNum++;
                currentLength++;
            }

            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Size must be positive." << endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Choose the approach to test
    // int ans = longestConsecutiveBrute(arr, n);
    // int ans = longestConsecutiveSorted(arr, n);
    int ans = longestConsecutiveOptimal(arr, n);

    cout << "\nLength of the longest consecutive sequence: " << ans << endl;

    return 0;
}
