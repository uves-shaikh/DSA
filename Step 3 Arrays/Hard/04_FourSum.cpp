#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds all unique quadruplets in the array whose sum equals the target (Better approach using HashSet).
 *
 * For each pair (i, j), this method uses a hash set to find two additional numbers (k, l)
 * such that the total sum equals the target.
 * The quadruplets are sorted and stored in a set to avoid duplicates.
 *
 * @param nums The input array.
 * @param target The target sum value.
 * @return A vector containing all unique quadruplets that sum to the target.
 *
 * Time Complexity: O(n³) — Two outer loops and one inner loop with a hash lookup.
 * Space Complexity: O(n) — Due to the hash set used for lookups.
 */
vector<vector<int>> fourSumWithBetter(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    set<vector<int>> st;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hashMap;
            for (int k = j + 1; k < n; k++)
            {
                int required = target - (nums[i] + nums[j] + nums[k]);
                if (hashMap.find(required) != hashMap.end())
                {
                    vector<int> fourSumResult = {nums[i], nums[j], nums[k], required};
                    sort(fourSumResult.begin(), fourSumResult.end());
                    st.insert(fourSumResult);
                }
                hashMap.insert(nums[k]);
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

/**
 * @brief Finds all unique quadruplets in the array whose sum equals the target (Optimal approach).
 *
 * This approach first sorts the array.
 * Then, for each pair of elements (nums[i], nums[j]), it uses a two-pointer technique
 * to find the remaining two numbers that complete the target sum.
 * Duplicate quadruplets are skipped efficiently using pointer movement.
 *
 * @param nums The input array.
 * @param target The target sum value.
 * @return A vector containing all unique quadruplets that sum to the target.
 *
 * Time Complexity: O(n³) — Sorting and triple nested loop with two pointers.
 * Space Complexity: O(1) — Ignoring output storage.
 */
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        // Skip duplicate values for nums[i]
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            // Skip duplicate values for nums[j]
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    // Skip duplicate elements after finding a valid quadruplet
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
            }
        }
    }

    return result;
}

/**
 * @brief Driver function for demonstrating Four Sum problem.
 *
 * Takes array size, elements, and target value as input.
 * Allows selection between “Better” and “Optimal” methods.
 * Displays all unique quadruplets that sum up to the target.
 */
int main()
{
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter target: ";
    cin >> target;

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

    cout << "\nChoose method:\n";
    cout << "1. Better (O(n³) using HashSet)\n";
    cout << "2. Optimal (O(n³) using Two-Pointer)\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    vector<vector<int>> result;

    if (choice == 1)
        result = fourSumWithBetter(arr, target);
    else if (choice == 2)
        result = fourSum(arr, target);
    else
    {
        cout << "Invalid choice." << endl;
        return 1;
    }

    cout << "\nAll unique quadruplets that sum to target:\n";
    if (result.empty())
    {
        cout << "No quadruplets found.\n";
    }
    else
    {
        for (auto &quad : result)
        {
            for (int val : quad)
                cout << val << " ";
            cout << endl;
        }
    }

    return 0;
}
