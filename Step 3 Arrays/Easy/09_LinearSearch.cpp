#include <bits/stdc++.h>
using namespace std;

/**
 * Find the index of a given element in the array.
 *
 * @param arr The input array
 * @param x   The element to search for
 * @return    Index of the element if found, otherwise -1
 *
 * Time Complexity: O(n)  (linear search through array)
 * Space Complexity: O(1) (no extra space used)
 */
int findElementIndex(vector<int> &arr, int x)
{
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
            return i; // return index when found
    }
    return -1; // element not found
}

int main()
{
    int size, target;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Error: Array size must be positive." << endl;
        return 1;
    }

    vector<int> arr(size);
    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }

    cout << "Enter the element to search in the array: ";
    cin >> target;

    int indexOfFoundElement = findElementIndex(arr, target);

    if (indexOfFoundElement != -1)
        cout << "Element " << target << " found at index " << indexOfFoundElement << "." << endl;
    else
        cout << "Element " << target << " not found in the array." << endl;

    return 0;
}
