#include <bits/stdc++.h>
using namespace std;

/**
 * Generates the next lexicographical permutation of the array.
 * If no such permutation exists (i.e., the array is in descending order),
 * it rearranges the array into the lowest (ascending) order.
 *
 * @param nums Reference to the input array (modified in place).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int index = -1;

    // Step 1: Find the first index from the right where nums[i] < nums[i+1]
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    // Step 2: If no such index exists, array is highest permutation -> reverse to lowest
    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find the smallest number greater than nums[index] to the right
    for (int i = n - 1; i > index; i--)
    {
        if (nums[i] > nums[index])
        {
            swap(nums[i], nums[index]);
            break;
        }
    }

    // Step 4: Reverse the suffix after index to get the next smallest arrangement
    reverse(nums.begin() + index + 1, nums.end());
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Size must be positive." << endl;
        return 1;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    nextPermutation(arr);

    cout << "Next permutation: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}
