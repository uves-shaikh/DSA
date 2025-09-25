#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Brute-force approach to count subarrays whose sum equals k.
 *
 * @param arr Input array (passed by value, can be reference for efficiency).
 * @param n Size of the array.
 * @param k Target sum.
 * @return Count of subarrays with sum equal to k.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
int countSubarraysWithSumKBruteForce(vector<int> &arr, int n, int k)
{
    int count = 0;

    for (int start = 0; start < n; start++)
    {
        int currentSum = 0;
        for (int end = start; end < n; end++)
        {
            currentSum += arr[end];

            if (currentSum == k)
            {
                count++;
                break; // Stops at first valid subarray starting at 'start'
            }
            else if (currentSum > k)
            {
                break; // Assumes all positive numbers (early exit)
            }
        }
    }
    return count;
}

/**
 * @brief Prefix sum + hashmap approach to count subarrays with sum k.
 *
 * @param nums Reference to input array.
 * @param k Target sum.
 * @return Count of subarrays with sum equal to k.
 *
 * Handles negative numbers as well.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int countSubarraysWithSumKHashmap(vector<int> &nums, int k)
{
    int count = 0;
    long long prefixSum = 0;
    unordered_map<long long, int> prefixSumFreq; // stores frequency of prefix sums

    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];

        // If prefix sum itself equals k, increment count
        if (prefixSum == k)
            count++;

        // If (prefixSum - k) exists, add its frequency to count
        if (prefixSumFreq.find(prefixSum - k) != prefixSumFreq.end())
        {
            count += prefixSumFreq[prefixSum - k];
        }

        // Increment frequency of current prefix sum
        prefixSumFreq[prefixSum]++;
    }

    return count;
}

/**
 * @brief Sliding window approach for positive integers to count subarrays with sum k.
 *
 * @param arr Input array.
 * @param n Size of the array.
 * @param k Target sum.
 * @return Count of subarrays with sum equal to k.
 *
 * Note: Only works when all numbers in the array are non-negative.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int countSubarraysWithSumKSlidingWindow(vector<int> &arr, int n, long long k)
{
    int count = 0;
    long long currentSum = 0;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        currentSum += arr[right];

        // Shrink window from left while sum > k
        while (currentSum > k && left <= right)
        {
            currentSum -= arr[left];
            left++;
        }

        if (currentSum == k)
            count++;
    }

    return count;
}

int main()
{
    int n, targetSum;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    vector<int> inputArray(n);
    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> inputArray[i];
    }

    cout << "Enter the target sum (k): ";
    cin >> targetSum;

    // Example usage: choose one approach
    // int count = countSubarraysWithSumKBruteForce(inputArray, n, targetSum);
    // int count = countSubarraysWithSumKSlidingWindow(inputArray, n, targetSum);
    int count = countSubarraysWithSumKHashmap(inputArray, targetSum);

    cout << "Number of subarrays with sum " << targetSum << " is: " << count << endl;

    return 0;
}
