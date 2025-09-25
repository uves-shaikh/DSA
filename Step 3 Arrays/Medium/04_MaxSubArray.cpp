#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the maximum sum of any contiguous subarray (Kadane's Algorithm).
 *
 * @param nums Reference to the input array of integers.
 * @return The maximum subarray sum.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int findMaxSubArraySum(vector<int> &nums)
{
    int currentSum = 0;   // Tracks sum of current subarray
    int maxSum = INT_MIN; // Stores maximum sum found so far

    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];            // Extend current subarray
        maxSum = max(maxSum, currentSum); // Update maximum if needed

        // Reset currentSum if it becomes negative, since starting fresh
        // is better than continuing with a negative prefix
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    return maxSum;
}

/**
 * @brief Finds the start and end indices of the maximum sum subarray.
 *
 * @param nums Reference to the input array of integers.
 * @return A vector containing two integers: {startIndex, endIndex}.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
vector<int> findMaxSubArrayIndices(vector<int> &nums)
{
    int currentSum = 0, maxSum = INT_MIN;
    int start = 0, tempStart = 0, end = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];

        // If current subarray gives a better sum, update result indices
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        // Reset subarray if sum drops below 0
        if (currentSum < 0)
        {
            currentSum = 0;
            tempStart = i + 1; // mark next index as a potential new start
        }
    }

    return {start, end};
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

    // Uncomment below to get maximum sum
    // int maxSum = findMaxSubArraySum(arr);
    // cout << "Maximum subarray sum: " << maxSum << endl;

    // Find start and end indices of max subarray
    vector<int> result = findMaxSubArrayIndices(arr);

    cout << "Start and end indices of maximum subarray: ";
    for (int idx : result)
        cout << idx << " ";
    cout << endl;

    return 0;
}
