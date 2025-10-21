#include <bits/stdc++.h>
using namespace std;

int binarySearchWithRecursive(vector<int> &nums, int target, int low, int high)
{
    if (low > high)
        return nums.size(); // return n if not found

    int mid = (low + high) / 2;

    if (nums[mid] >= target)
        // check left side to find earlier valid index
        return min(mid, binarySearchWithRecursive(nums, target, low, mid - 1));
    else
        // search right side
        return binarySearchWithRecursive(nums, target, mid + 1, high);
}

int binarySearchWithIterative(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int elementIndex = n; // default to n (not found)

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= target)
        {
            elementIndex = mid;
            high = mid - 1; // continue searching left
        }
        else
        {
            low = mid + 1;
        }
    }

    return elementIndex;
}

int main()
{
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter target: ";
    cin >> target;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Choose Method
    int index = binarySearchWithIterative(arr, target);
    // int index = binarySearchWithRecursive(arr, target, 0, n - 1);

    cout << "Lower bound index: " << index << endl;

    return 0;
}
