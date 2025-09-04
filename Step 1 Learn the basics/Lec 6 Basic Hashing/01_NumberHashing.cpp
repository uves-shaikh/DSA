#include <bits/stdc++.h>
using namespace std;

int main()
{
    /**
     * Problem: Count frequency of elements and answer queries
     *
     * Two approaches demonstrated:
     *  1. Hashing with array (works when values are small & non-negative).
     *  2. Hashing with map (works for any integer range).
     */

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

    // Approach 1: Number hashing using array
    // Works only if numbers are in a known small range [0..maxVal]
    // Example: here maxVal = 1000 (adjust as per problem)
    const int MAX_VAL = 1000;
    vector<int> hash(MAX_VAL + 1, 0);

    for (int num : arr)
    {
        if (num >= 0 && num <= MAX_VAL)
            hash[num]++;
    }

    // Approach 2: Number hashing using ordered map
    // Works for any integer (positive or negative)
    map<int, int> freqMap;
    for (int num : arr)
    {
        freqMap[num]++;
    }

    int q;
    cout << "\nEnter number to find frequency: ";
    cin >> q;

    // Array-based lookup (safe only if q is in [0..MAX_VAL])
    if (q >= 0 && q <= MAX_VAL)
        cout << "Array Hash → " << q << " found " << hash[q] << " times\n";
    else
        cout << "Array Hash → " << q << " is out of predefined range\n";

    // Map-based lookup (works for all integers)
    cout << "Map Hash   → " << q << " found " << freqMap[q] << " times\n";

    return 0;
}
