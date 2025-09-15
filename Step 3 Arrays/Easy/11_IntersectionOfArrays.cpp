#include <bits/stdc++.h>
using namespace std;

/**
 * Find the intersection of two arrays using a brute-force approach.
 *
 * This method compares each element of arr1 with each element of arr2,
 * and stores common elements in a set to avoid duplicates.
 *
 * @param arr1 The first input array
 * @param arr2 The second input array
 * @return     A vector containing the intersection of both arrays (unique, sorted)
 *
 * Time Complexity: O(n1 * n2)   // nested loops
 * Space Complexity: O(min(n1, n2)) // set + result vector
 */
vector<int> findIntersectionBruteForce(vector<int> &arr1, vector<int> &arr2)
{
    set<int> uniqueIntersection;

    for (int num1 : arr1)
    {
        for (int num2 : arr2)
        {
            if (num1 == num2)
                uniqueIntersection.insert(num1);
        }
    }

    vector<int> intersectionArray(uniqueIntersection.begin(), uniqueIntersection.end());
    return intersectionArray;
}

/**
 * Find the intersection of two sorted arrays using the two-pointer technique.
 *
 * This method traverses both arrays simultaneously and collects common elements,
 * while avoiding duplicates in the result.
 *
 * @param arr1 The first sorted array
 * @param arr2 The second sorted array
 * @return     A vector containing the intersection of both arrays (unique, sorted)
 *
 * Time Complexity: O(n1 + n2)   // linear traversal
 * Space Complexity: O(min(n1, n2)) // result vector
 */
vector<int> findIntersectionOptimal(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0, j = 0;
    int n1 = arr1.size(), n2 = arr2.size();
    vector<int> intersectionArray;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] == arr2[j])
        {
            if (intersectionArray.empty() || intersectionArray.back() != arr1[i])
                intersectionArray.push_back(arr1[i]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    return intersectionArray;
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

    // NOTE: For the optimal method, arrays should be sorted
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // vector<int> intersectionOfArrays = findIntersectionBruteForce(arr1, arr2);
    vector<int> intersectionOfArrays = findIntersectionOptimal(arr1, arr2);

    cout << "Intersection of array 1 and array 2: ";
    for (int val : intersectionOfArrays)
        cout << val << " ";
    cout << endl;

    return 0;
}
