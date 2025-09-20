#include <bits/stdc++.h>
using namespace std;

// ------------------- Brute Force Approach -------------------
/*
 * Function: findLongestSubArrayWithSumKBruteForce
 * ------------------------------------------------
 * Finds the longest subarray with sum = k using brute force.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
int findLongestSubArrayWithSumKBruteForce(vector<int> arr, int n, int k)
{
    int maxLength = 0;
    for (int start = 0; start < n; start++)
    {
        int currentSum = 0;
        for (int end = start; end < n; end++)
        {
            currentSum += arr[end];
            if (currentSum == k)
            {
                maxLength = max(maxLength, end - start + 1);
                break; // since adding more elements will exceed sum
            }
            else if (currentSum > k)
            {
                break;
            }
        }
    }
    return maxLength;
}

// ------------------- Better Approach -------------------
/*
 * Function: findLongestSubArrayWithSumKBetter
 * --------------------------------------------
 * Uses prefix sum + hashmap to store earliest index of each sum.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int findLongestSubArrayWithSumKBetter(vector<int> &nums, int k)
{
    int maxLength = 0;
    int n = nums.size();
    map<long long, int> prefixSumMap;
    long long currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum += nums[i];

        if (currentSum == k)
        {
            maxLength = max(maxLength, i + 1);
        }

        long long remainder = currentSum - k;
        if (prefixSumMap.find(remainder) != prefixSumMap.end())
        {
            int length = i - prefixSumMap[remainder];
            maxLength = max(maxLength, length);
        }

        // store only first occurrence
        if (prefixSumMap.find(currentSum) == prefixSumMap.end())
        {
            prefixSumMap[currentSum] = i;
        }
    }

    return maxLength;
}

// ------------------- Optimal Approach (Only for Positive Numbers) -------------------
/*
 * Function: findLongestSubArrayWithSumKOptimal
 * ---------------------------------------------
 * Sliding window approach (works only when all elements are non-negative).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int findLongestSubArrayWithSumKOptimal(vector<int> arr, int n, long long k)
{
    int maxLength = 0, left = 0, right = 0;
    long long currentSum = arr[0];

    while (right < n)
    {
        while (left <= right && currentSum > k)
        {
            currentSum -= arr[left];
            left++;
        }
        if (currentSum == k)
        {
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
        if (right < n)
            currentSum += arr[right];
    }

    return maxLength;
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

    // Choose which approach you want to test:
    int longestLength = findLongestSubArrayWithSumKOptimal(inputArray, n, targetSum);
    // int longestLength = findLongestSubArrayWithSumKBruteForce(inputArray, n, targetSum);
    // int longestLength = findLongestSubArrayWithSumKBetter(inputArray, targetSum);

    cout << "The length of the longest subarray with sum " << targetSum << " is: " << longestLength << endl;

    return 0;
}
