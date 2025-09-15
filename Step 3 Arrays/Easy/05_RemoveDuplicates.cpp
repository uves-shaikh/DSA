#include <bits/stdc++.h>
using namespace std;

/**
 * Removes duplicates from a sorted array in-place.
 * Keeps only unique elements in the front part of the array.
 *
 * @param numbers   The input array (must be sorted)
 * @param size      Size of the array
 * @return          Count of unique elements
 *
 * Approach:
 * - Use two pointers (uniqueIndex and currentIndex).
 * - Pointer `uniqueIndex` tracks the last unique element.
 * - Pointer `currentIndex` moves through the array and compares with numbers[uniqueIndex].
 * - If numbers[currentIndex] is different, place it at numbers[uniqueIndex + 1]
 *   and move uniqueIndex forward.
 *
 * Time Complexity: O(n)  → single pass through array
 * Space Complexity: O(1) → in-place, no extra array used
 */
int removeDuplicatesFromSortedArray(vector<int> &numbers, int size)
{
    if (size == 0)
        return 0; // Edge case: empty array

    int uniqueIndex = 0; // Last index of unique elements

    for (int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        if (numbers[currentIndex] != numbers[uniqueIndex])
        {
            numbers[uniqueIndex + 1] = numbers[currentIndex]; // Place next unique element
            uniqueIndex++;
        }
    }

    return (uniqueIndex + 1); // Count of unique elements
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    vector<int> numbers(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> numbers[i];
    }

    int uniqueCount = removeDuplicatesFromSortedArray(numbers, size);

    cout << "Number of unique elements: " << uniqueCount << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; i++)
        cout << numbers[i] << " ";
    cout << endl;

    return 0;
}
