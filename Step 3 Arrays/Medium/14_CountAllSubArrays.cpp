#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Counts all subarrays whose sum equals k.
 *
 * Uses prefix sum and an unordered_map to store
 * how many times each prefix sum has occurred.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 *
 * @param arr Input array
 * @param k Target sum
 * @return int Count of subarrays with sum == k
 */
int countSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> prefixSumFreq; // prefix_sum -> count of occurrences
    prefixSumFreq[0] = 1;                  // base case: prefix sum = 0 appears once

    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        // We need prefixSum - k to have appeared before
        int required = prefixSum - k;

        if (prefixSumFreq.find(required) != prefixSumFreq.end())
        {
            count += prefixSumFreq[required];
        }

        // Record the current prefix sum
        prefixSumFreq[prefixSum]++;
    }

    return count;
}

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    cout << "Enter the target sum: ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int count = countSubarraysWithGivenSum(arr, k);

    cout << "\nNumber of subarrays with sum " << k << ": " << count << endl;

    return 0;
}
