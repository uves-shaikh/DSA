#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Generates all permutations using extra space (freq array).
 *
 * @param nums Input numbers
 * @param result Stores all permutations
 * @param freq Tracks used indices
 * @param ds Current permutation being built
 *
 * Time Complexity: O(n! * n)  (n! permutations, each copy takes O(n))
 * Space Complexity: O(n) for freq + recursion stack
 */
void permuteWithFreq(vector<int> &nums, vector<vector<int>> &result, vector<int> &freq, vector<int> &ds)
{
    if (ds.size() == nums.size())
    {
        result.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;

            permuteWithFreq(nums, result, freq, ds);

            freq[i] = 0;
            ds.pop_back();
        }
    }
}

/**
 * @brief Generates all permutations in-place using swap.
 *
 * @param index Current index
 * @param nums Input numbers (modified in-place)
 * @param result Stores all permutations
 *
 * Time Complexity: O(n! * n)
 * Space Complexity: O(1) (only recursion stack)
 */
void permuteWithSwap(int index, vector<int> &nums, vector<vector<int>> &result)
{
    if (index == nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        permuteWithSwap(index + 1, nums, result);
        swap(nums[i], nums[index]); // backtrack
    }
}

/**
 * @brief Wrapper to find all permutations.
 * Switch between freq-based or swap-based method.
 */
vector<vector<int>> findAllPermutations(vector<int> &nums)
{
    vector<vector<int>> result;

    // Method 1: Freq-based
    // vector<int> freq(nums.size(), 0), ds;
    // permuteWithFreq(nums, result, freq, ds);

    // Method 2: Swap-based
    permuteWithSwap(0, nums, result);

    return result;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> nums[i];
    }

    vector<vector<int>> permutations = findAllPermutations(nums);

    cout << "\nAll permutations:\n";
    for (auto &perm : permutations)
    {
        for (int val : perm)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
