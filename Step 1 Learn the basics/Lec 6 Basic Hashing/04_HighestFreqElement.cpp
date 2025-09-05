#include <bits/stdc++.h>
using namespace std;

/**
 * Function: highestFrequencyElement
 * ---------------------------------
 * Returns the element with the highest frequency in the array.
 * If multiple elements have the same maximum frequency,
 * the one that appears first in the array is chosen.
 *
 * @param arr - vector of integers
 * @return int - element with highest frequency (first occurrence tie-break)
 */
int highestFrequencyElement(vector<int> &arr)
{
    unordered_map<int, int> freqMap;         // element -> frequency
    unordered_map<int, int> firstOccurrence; // element -> first index

    // Step 1: Build frequency and first-occurrence maps
    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        freqMap[num]++;
        if (firstOccurrence.find(num) == firstOccurrence.end())
        {
            firstOccurrence[num] = i; // store index of first appearance
        }
    }

    int maxFreq = 0;
    int ansElement = arr[0]; // default answer → first element

    // Step 2: Traverse in array order for natural tie-breaking
    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        int freq = freqMap[num];

        if (freq > maxFreq)
        {
            maxFreq = freq;
            ansElement = num;
        }
        // Tie case: since we traverse in array order,
        // the first occurrence is naturally chosen.
    }

    return ansElement;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // number of test cases
    while (T--)
    {
        int N;
        cin >> N; // size of array
        vector<int> arr(N);

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        cout << highestFrequencyElement(arr) << "\n";
    }

    return 0;
}
