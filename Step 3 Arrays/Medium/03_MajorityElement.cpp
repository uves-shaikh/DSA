#include <bits/stdc++.h>
using namespace std;

int majorityElementBrute(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == nums[i])
            {
                count++;
            }
        }
        if (count > nums.size() / 2)
            return nums[i];
    }

    return -1;
}

int majorityElementBetter(vector<int> &nums)
{
    map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    for (auto ele : mpp)
    {
        if (ele.second > nums.size() / 2) // ✅ Fixed condition
        {
            return ele.first;
        }
    }

    return -1;
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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int elem = majorityElementBetter(arr);

    cout << "The majority element is: " << elem << endl;

    return 0;
}
