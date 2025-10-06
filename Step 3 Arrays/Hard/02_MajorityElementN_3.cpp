#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Brute-force method to find all majority elements (> n/3 times).
 *
 * @param nums Input array.
 * @return Vector of elements appearing more than n/3 times.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
vector<int> findMajorityElementsBrute(vector<int> &nums)
{
    vector<int> result;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == nums[i])
                count++;
        }

        // Check condition and avoid duplicates
        if (count > n / 3 && find(result.begin(), result.end(), nums[i]) == result.end())
            result.push_back(nums[i]);
    }

    return result;
}

/**
 * @brief Map-based method to find all majority elements (> n/3 times).
 *
 * @param nums Input array.
 * @return Vector of elements appearing more than n/3 times.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
vector<int> findMajorityElementsUsingMap(vector<int> &nums)
{
    map<int, int> freq;
    for (int num : nums)
        freq[num]++;

    vector<int> result;
    int n = nums.size();
    for (auto &p : freq)
    {
        if (p.second > n / 3)
            result.push_back(p.first);
    }

    return result;
}

/**
 * @brief Optimal Boyer–Moore Voting Algorithm (extended for n/3).
 *
 * @param arr Input array.
 * @return Vector of elements appearing more than n/3 times.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
vector<int> majorityElementOptimal(vector<int> &arr)
{
    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    int n = arr.size();

    for (int num : arr)
    {
        if (cnt1 == 0 && num != ele2)
        {
            ele1 = num;
            cnt1 = 1;
        }
        else if (cnt2 == 0 && num != ele1)
        {
            ele2 = num;
            cnt2 = 1;
        }
        else if (num == ele1)
            cnt1++;
        else if (num == ele2)
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // Verify candidates
    cnt1 = cnt2 = 0;
    for (int num : arr)
    {
        if (num == ele1)
            cnt1++;
        else if (num == ele2)
            cnt2++;
    }

    vector<int> result;
    if (cnt1 > n / 3)
        result.push_back(ele1);
    if (cnt2 > n / 3)
        result.push_back(ele2);

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

    // Choose Method
    // vector<int> result = findMajorityElementsBrute(arr);
    // vector<int> result = findMajorityElementsUsingMap(arr);
    vector<int> result = majorityElementOptimal(arr);

    if (result.empty())
        cout << "None";
    else
        for (int x : result)
            cout << x << " ";
    cout << endl;

    return 0;
}
