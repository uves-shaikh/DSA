#include <bits/stdc++.h>
using namespace std;

/*
 * Function: isTwoSumExistBruteApproach
 * -------------------------------------
 * Checks if any two numbers in the array sum up to the target.
 * Brute Force approach → O(n^2)
 */
bool isTwoSumExistBruteApproach(const vector<int> &arr, int n, int target)
{
    for (int i = 0; i < n; i++) // Start from index 0
    {
        for (int j = i + 1; j < n; j++) // j starts from i+1 to avoid self-pair
        {
            if (arr[i] + arr[j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

/*
 * Function: twoSum
 * -----------------
 * Returns all index pairs (i, j) such that arr[i] + arr[j] == target.
 * Better approach using hashmap → O(n)
 */
vector<pair<int, int>> twoSum(vector<int> &arr, int n, int target)
{
    map<int, int> mpp; // stores number → index
    vector<pair<int, int>> result;

    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int complement = target - current;

        if (mpp.find(complement) != mpp.end())
        {
            result.push_back({i, mpp[complement]});
        }

        // store current element index for later use
        mpp[current] = i;
    }

    return result;
}

/*
 * Function: twoSumIndexBruteApproach
 * -----------------------------------
 * Returns first pair of indices (i, j) where arr[i] + arr[j] == target.
 */
vector<int> twoSumIndexBruteApproach(const vector<int> &arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // return invalid indices if no pair found
}

/*
 * Function: isTwoSumExistBetterApproach
 * --------------------------------------
 * Checks existence using hashmap. O(n)
 */
bool isTwoSumExistBetterApproach(const vector<int> &arr, int n, int target)
{
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int complement = target - current;

        if (mpp.find(complement) != mpp.end())
        {
            return true;
        }

        mpp[current] = i; // store index of current element
    }

    return false;
}

/*
 * Function: twoSumIndexBetterApproach
 * ------------------------------------
 * Returns indices (i, j) using hashmap. O(n)
 */
vector<int> twoSumIndexBetterApproach(const vector<int> &arr, int n, int target)
{
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int complement = target - current;

        if (mpp.find(complement) != mpp.end())
        {
            return {i, mpp[complement]};
        }

        mpp[current] = i;
    }

    return {-1, -1};
}

int main()
{
    int n, target;
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

    cout << "Enter target: ";
    cin >> target;

    // Example usage:
    cout << "\nUsing Brute Force Existence Check: ";
    cout << (isTwoSumExistBruteApproach(arr, n, target) ? "Pair exists" : "No pair found") << endl;

    cout << "Using Better Existence Check: ";
    cout << (isTwoSumExistBetterApproach(arr, n, target) ? "Pair exists" : "No pair found") << endl;

    cout << "\nFirst Pair Indices (Brute): ";
    vector<int> bruteIndex = twoSumIndexBruteApproach(arr, n, target);
    cout << bruteIndex[0] << " " << bruteIndex[1] << endl;

    cout << "First Pair Indices (Better): ";
    vector<int> betterIndex = twoSumIndexBetterApproach(arr, n, target);
    cout << betterIndex[0] << " " << betterIndex[1] << endl;

    cout << "\nAll Pairs (Better):" << endl;
    vector<pair<int, int>> allPairs = twoSum(arr, n, target);
    for (auto &p : allPairs)
    {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
