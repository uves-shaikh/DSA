#include <bits/stdc++.h>
using namespace std;

int main()
{
    /**
     * Problem:
     *  - Count frequencies of all elements in an array
     *  - Find the element with maximum frequency
     *  - Find the element with minimum frequency
     *
     * Approach:
     *  - Use unordered_map<int,int> to store frequency counts (O(1) average lookup).
     *  - Iterate through map to determine max and min frequency elements.
     */

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1; // exit with error
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Step 1: Build frequency map
    unordered_map<int, int> freqMap;
    for (int num : arr)
    {
        freqMap[num]++;
    }

    // Step 2: Track max & min frequency
    int maxFreq = 0, minFreq = INT_MAX;
    int maxElement = arr[0], minElement = arr[0];

    for (auto &entry : freqMap)
    {
        int element = entry.first;
        int freq = entry.second;

        if (freq > maxFreq)
        {
            maxFreq = freq;
            maxElement = element;
        }

        if (freq < minFreq)
        {
            minFreq = freq;
            minElement = element;
        }
    }

    // Step 3: Output result
    cout << "\nResults:\n";
    cout << maxElement << " has maximum frequency: " << maxFreq << endl;
    cout << minElement << " has minimum frequency: " << minFreq << endl;

    return 0;
}
