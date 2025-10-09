#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Counts the number of subarrays having a given XOR value.
 *
 * This function finds how many subarrays of the given array
 * have a bitwise XOR equal to the target value `x`.
 *
 * The approach is based on using the prefix XOR concept:
 * - Let `prefix[i]` be the XOR of elements from index 0 to i.
 * - For each prefix, we find how many previous prefixes satisfy:
 *       prefix[i] ^ prefix[j - 1] = x
 *   → which implies prefix[j - 1] = prefix[i] ^ x
 *
 * A hash map (`prefixSumFreq`) keeps track of the frequency of all
 * previously seen prefix XORs for O(1) lookup.
 *
 * @param arr The input array of integers.
 * @param x The target XOR value to find in subarrays.
 * @return The total count of subarrays whose XOR equals x.
 *
 * Time Complexity: O(n) — Single traversal of the array.
 * Space Complexity: O(n) — Hash map to store prefix XOR frequencies.
 */
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    unordered_map<int, int> prefixSumFreq;
    prefixSumFreq[0] = 1; // Base case: XOR 0 occurs once initially.

    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum ^= arr[i];

        int required = prefixSum ^ x;

        if (prefixSumFreq.find(required) != prefixSumFreq.end())
        {
            count += prefixSumFreq[required];
        }

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

    cout << "Enter the target XOR: ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int count = subarraysXor(arr, k);

    cout << "\nNumber of subarrays with XOR " << k << ": " << count << endl;

    return 0;
}
