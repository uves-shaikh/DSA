#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the floor and ceil of a target value in a sorted array.
 *
 * Floor: greatest element <= x
 * Ceil: smallest element >= x
 *
 * @param a Sorted array.
 * @param n Size of the array.
 * @param x Target value.
 * @return pair<int, int> {floor, ceil}
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1;
    int floorVal = -1, ceilVal = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == x)
        {
            // Perfect match → both floor & ceil are x
            floorVal = ceilVal = a[mid];
            break;
        }
        else if (a[mid] < x)
        {
            floorVal = a[mid]; // potential floor
            low = mid + 1;
        }
        else
        {
            ceilVal = a[mid]; // potential ceil
            high = mid - 1;
        }
    }

    return {floorVal, ceilVal};
}

int main()
{
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

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

    cout << "Enter target: ";
    cin >> target;

    pair<int, int> result = getFloorAndCeil(arr, n, target);

    cout << "\nFloor: " << result.first << "\nCeil: " << result.second << endl;

    return 0;
}
