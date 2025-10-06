#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds all unique triplets in the array whose sum is zero (Brute Force approach).
 *
 * This method checks every possible triplet (i, j, k) and stores valid ones in a set
 * to automatically remove duplicates.
 *
 * @param n The size of the array.
 * @param arr The input array.
 * @return A vector containing all unique triplets that sum to zero.
 *
 * Time Complexity: O(n³)
 * Space Complexity: O(number of unique triplets)
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

    vector<vector<int>> result(st.begin(), st.end());
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

    vector<vector<int>> result = tripletWithBrute(n, arr);

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
