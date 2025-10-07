#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds all unique triplets in the array whose sum is zero (Brute Force approach).
 *
 * This method checks every possible triplet (i, j, k) in the array.
 * For each combination, it adds the triplet to a set if the sum is zero.
 * Sorting and using a set automatically handle duplicate triplets.
 *
 * @param n The size of the array.
 * @param arr The input array.
 * @return A vector containing all unique triplets that sum to zero.
 *
 * Time Complexity: O(n³) — Three nested loops.
 * Space Complexity: O(number of unique triplets).
 */
vector<vector<int>> tripletWithBrute(int n, vector<int> &arr)
{
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

/**
 * @brief Finds all unique triplets with sum = 0 using a HashSet approach (Better method).
 *
 * For each element in the array (arr[i]), this method uses a hash set to find two other
 * elements such that their sum equals -arr[i].
 * Each valid triplet is sorted and inserted into a set to avoid duplicates.
 *
 * @param n The size of the array.
 * @param arr The input array.
 * @return A vector containing all unique triplets that sum to zero.
 *
 * Time Complexity: O(n²) — Outer loop + inner loop with hash lookups.
 * Space Complexity: O(n) — Due to the hash set.
 */
vector<vector<int>> tripletWithBetter(int n, vector<int> &arr)
{
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            int ele = -(arr[i] + arr[j]);
            if (hashSet.find(ele) != hashSet.end())
            {
                vector<int> val = {arr[i], arr[j], ele};
                sort(val.begin(), val.end());
                st.insert(val);
            }
            hashSet.insert(arr[j]);
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

/**
 * @brief Finds all unique triplets in the array whose sum is zero (Optimal Two-Pointer approach).
 *
 * This method first sorts the array.
 * Then, for each element arr[i], it uses two pointers (j, k) to find pairs such that
 * arr[i] + arr[j] + arr[k] == 0.
 * Duplicate triplets are skipped efficiently by adjusting pointers.
 *
 * @param n The size of the array.
 * @param arr The input array.
 * @return A vector containing all unique triplets that sum to zero.
 *
 * Time Complexity: O(n²) — Sorting + two-pointer search for each element.
 * Space Complexity: O(1) — Ignoring output storage.
 */
vector<vector<int>> tripletOptimal(int n, vector<int> &arr)
{
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        // Skip duplicate elements for arr[i]
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            long long sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                // Skip duplicates for arr[j] and arr[k]
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Choose Method:
    // vector<vector<int>> result = tripletWithBrute(n, arr);
    // vector<vector<int>> result = tripletWithBetter(n, arr);
    vector<vector<int>> result = tripletOptimal(n, arr);

    cout << "\nAll unique triplets that sum to 0:\n";
    if (result.empty())
    {
        cout << "No triplets found.\n";
    }
    else
    {
        for (auto &triplet : result)
        {
            for (int val : triplet)
                cout << val << " ";
            cout << endl;
        }
    }

    return 0;
}
