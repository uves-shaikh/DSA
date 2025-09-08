#include <bits/stdc++.h>
using namespace std;

/**
 * Find the largest element in the array
 *
 * @param arr The input array
 * @param n   Size of the array
 * @return    The maximum element
 */
int findLargest(const vector<int> &arr, int n)
{
    int largest = arr[0]; // Initialize with the first element

    for (int i = 1; i < n; i++) // Start from index 1
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
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

    int largestElement = findLargest(arr, n);

    cout << "Largest element in array is: " << largestElement << endl;

    return 0;
}
