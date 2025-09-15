#include <bits/stdc++.h>
using namespace std;

/**
 * Find the union of two arrays using a brute-force approach with a set.
 *
 * This method inserts all elements from both arrays into a set
 * (which removes duplicates and sorts them automatically).
 *
 * @param arr1 The first input array
 * @param arr2 The second input array
 * @return     A vector containing the union of both arrays (sorted, unique)
 *
 * Time Complexity: O((n1 + n2) * log(n1 + n2))  // due to set insertion
 * Space Complexity: O(n1 + n2)                  // extra set + result array
 */
vector<int> findUnionBruteForce(vector<int> &arr1, vector<int> &arr2)
{
    set<int> uniqueSortedElements;

    // Insert elements of first array
    for (int num : arr1)
        uniqueSortedElements.insert(num);

    // Insert elements of second array
    for (int num : arr2)
        uniqueSortedElements.insert(num);

    // Copy set elements into result vector
    vector<int> unionArray(uniqueSortedElements.begin(), uniqueSortedElements.end());
    return unionArray;
}

/**
 * Find the union of two sorted arrays using a two-pointer approach.
 *
 * This method traverses both arrays simultaneously,
 * inserting elements into the result while avoiding duplicates.
 *
 * @param arr1 The first sorted array
 * @param arr2 The second sorted array
 * @return     A vector containing the union of both arrays (sorted, unique)
 *
 * Time Complexity: O(n1 + n2)  // linear traversal
 * Space Complexity: O(n1 + n2) // result vector
 */
vector<int> findUnionOptimal(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0, j = 0;
    int n1 = arr1.size(), n2 = arr2.size();
    vector<int> unionArray;

    // Traverse both arrays
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionArray.empty() || unionArray.back() != arr1[i])
                unionArray.push_back(arr1[i]);
            i++;
        }
        else
        {
            if (unionArray.empty() || unionArray.back() != arr2[j])
                unionArray.push_back(arr2[j]);
            j++;
        }
    }

    // Copy remaining elements of arr1
    while (i < n1)
    {
        if (unionArray.empty() || unionArray.back() != arr1[i])
            unionArray.push_back(arr1[i]);
        i++;
    }

    // Copy remaining elements of arr2
    while (j < n2)
    {
        if (unionArray.empty() || unionArray.back() != arr2[j])
            unionArray.push_back(arr2[j]);
        j++;
    }

    return unionArray;
}

int main()
{
    int n1, n2;

    cout << "Enter the size of array 1: ";
    cin >> n1;
    if (n1 <= 0)
    {
        cout << "Error: Array size must be positive." << endl;
        return 1;
    }

    vector<int> arr1(n1);
    cout << "Enter " << n1 << " elements of array 1:" << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr1[i];
    }

    cout << "Enter the size of array 2: ";
    cin >> n2;
    if (n2 <= 0)
    {
        cout << "Error: Array size must be positive." << endl;
        return 1;
    }

    vector<int> arr2(n2);
    cout << "Enter " << n2 << " elements of array 2:" << endl;
    for (int i = 0; i < n2; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr2[i];
    }

    // NOTE: For optimal approach, arrays should be sorted beforehand
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // vector<int> unionOfArrays = findUnionBruteForce(arr1, arr2);
    vector<int> unionOfArrays = findUnionOptimal(arr1, arr2);

    cout << "Union of array 1 and array 2: ";
    for (int val : unionOfArrays)
        cout << val << " ";
    cout << endl;

    return 0;
}
