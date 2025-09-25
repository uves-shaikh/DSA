#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Rearranges an array so that positive and negative numbers
 *        alternate, starting with a positive number.
 *
 * @param nums Reference to the input array (modified in place).
 *
 * Example:
 * Input:  {3, 1, -2, -5, 2, -4}
 * Output: {3, -2, 1, -5, 2, -4}
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)  (uses extra arrays for positives/negatives)
 */
void rearrangeArrayBySign(vector<int> &nums)
{
    vector<int> posArray; // stores positive numbers
    vector<int> negArray; // stores negative numbers
    int n = nums.size();

    // Separate positives and negatives
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0) // treat 0 as positive
        {
            posArray.push_back(nums[i]);
        }
        else
        {
            negArray.push_back(nums[i]);
        }
    }

    // Fill positive numbers at even indices (0, 2, 4, ...)
    for (int i = 0; i < posArray.size(); i++)
    {
        nums[i * 2] = posArray[i];
    }

    // Fill negative numbers at odd indices (1, 3, 5, ...)
    for (int i = 0; i < negArray.size(); i++)
    {
        nums[(i * 2) + 1] = negArray[i];
    }
}

int main()
{
    int n;
    cout << "Enter size of array (must be positive and even): ";
    cin >> n;

    // ✅ Fix: input validation should use OR (||), not AND (&&)
    if (n <= 0 || (n % 2 != 0))
    {
        cout << "Array size must be positive and even." << endl;
        return 1;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> nums[i];
    }

    rearrangeArrayBySign(nums);

    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
