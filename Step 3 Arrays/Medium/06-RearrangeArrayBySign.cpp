#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Brute Force: Rearranges array so that positives and negatives
 *        alternate, starting with a positive number.
 *
 * Steps:
 * 1. Split positives and negatives into two separate arrays.
 * 2. Fill positives at even indices, negatives at odd indices.
 *
 * @param nums Input array (unchanged).
 * @return Rearranged array.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<int> rearrangeArrayBySignWithBrute(vector<int> &nums)
{
    vector<int> posArray; // stores positive numbers
    vector<int> negArray; // stores negative numbers
    int n = nums.size();

    // Step 1: Separate positives and negatives
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0) // treat 0 as positive
            posArray.push_back(nums[i]);
        else
            negArray.push_back(nums[i]);
    }

    // Step 2: Place them alternately in result
    vector<int> result(n);
    for (int i = 0; i < posArray.size(); i++)
        result[i * 2] = posArray[i];

    for (int i = 0; i < negArray.size(); i++)
        result[i * 2 + 1] = negArray[i];

    return result;
}

/**
 * @brief Better Approach: Uses two running indices (posIndex and negIndex)
 *        to directly place elements at correct positions.
 *
 * @param nums Input array (unchanged).
 * @return Rearranged array.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<int> rearrangeArrayBySignWithBetter(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 0);

    int posIndex = 0; // next position for positive
    int negIndex = 1; // next position for negative

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            result[negIndex] = nums[i];
            negIndex += 2;
        }
        else
        {
            result[posIndex] = nums[i];
            posIndex += 2;
        }
    }

    return result;
}

/**
 * @brief Alternative Better Variant: Similar to above, but uses
 *        while-loops instead of single-pass for extra flexibility.
 *
 * ⚠️ Fix applied: Index conditions should be < n (not < 2*n).
 *
 * @param nums Input array (unchanged).
 * @return Rearranged array.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<int> rearrangeArrayBySignWithBetterAnotherVariant(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 0);

    int posIndex = 0;
    int negIndex = 1;
    int i = 0;

    // Place positives and negatives alternately
    while (i < n && posIndex < n && negIndex < n)
    {
        if (nums[i] < 0)
        {
            result[negIndex] = nums[i];
            negIndex += 2;
        }
        else
        {
            result[posIndex] = nums[i];
            posIndex += 2;
        }
        i++;
    }

    // Fill any remaining positives
    while (i < n && posIndex < n)
    {
        result[posIndex] = nums[i];
        posIndex += 2;
        i++;
    }

    // Fill any remaining negatives
    while (i < n && negIndex < n)
    {
        result[negIndex] = nums[i];
        negIndex += 2;
        i++;
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter size of array (must be positive and even): ";
    cin >> n;

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

    // Choose the approach to test:
    // vector<int> result = rearrangeArrayBySignWithBrute(nums);
    // vector<int> result = rearrangeArrayBySignWithBetter(nums);
    vector<int> result = rearrangeArrayBySignWithBetterAnotherVariant(nums);

    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
