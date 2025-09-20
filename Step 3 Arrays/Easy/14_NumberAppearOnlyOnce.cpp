#include <bits/stdc++.h>
using namespace std;

/*
 * Function: findUniqueNumberBruteForce
 * ------------------------------------
 * Finds the number that appears only once in an array using brute force.
 *
 * Approach:
 * - For each element, loop through the entire array and count its frequency.
 * - If the frequency is 1, return that element.
 *
 * Parameters:
 * - inputArray: vector<int>, the input array
 * - arraySize: int, size of the array
 *
 * Returns:
 * - Integer that appears exactly once, or -1 if not found.
 *
 * Time Complexity: O(n^2) → Nested loops for frequency count
 * Space Complexity: O(1)  → No extra space used
 */
int findUniqueNumberBruteForce(vector<int> inputArray, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        int frequency = 0;
        for (int j = 0; j < arraySize; j++)
        {
            if (inputArray[i] == inputArray[j])
            {
                frequency++;
            }
        }
        if (frequency == 1)
            return inputArray[i];
    }
    return -1; // no unique number found
}

/*
 * Function: findUniqueNumberUsingMap
 * ----------------------------------
 * Finds the number that appears only once using a hash map.
 *
 * Approach:
 * - Store frequencies of elements in an unordered_map.
 * - Iterate through the map and return the element with frequency 1.
 *
 * Parameters:
 * - inputArray: vector<int>, the input array
 * - arraySize: int, size of the array
 *
 * Returns:
 * - Integer that appears exactly once, or -1 if not found.
 *
 * Time Complexity: O(n)   → Traverse array + map iteration
 * Space Complexity: O(n)  → Extra space for hash map
 */
int findUniqueNumberUsingMap(vector<int> inputArray, int arraySize)
{
    unordered_map<int, int> frequencyMap;

    for (int i = 0; i < arraySize; i++)
    {
        frequencyMap[inputArray[i]]++;
    }

    for (auto element : frequencyMap)
    {
        if (element.second == 1)
            return element.first;
    }

    return -1;
}

/*
 * Function: findUniqueNumberUsingXOR
 * ----------------------------------
 * Finds the number that appears only once using bitwise XOR.
 *
 * Approach:
 * - XOR of two same numbers is 0.
 * - XOR of a number with 0 is the number itself.
 * - Thus, XOR-ing all elements cancels out duplicates, leaving the unique number.
 *
 * Parameters:
 * - inputArray: vector<int>, the input array
 * - arraySize: int, size of the array
 *
 * Returns:
 * - Integer that appears exactly once.
 *
 * Time Complexity: O(n)  → Single pass through the array
 * Space Complexity: O(1) → No extra space used
 */
int findUniqueNumberUsingXOR(vector<int> inputArray, int arraySize)
{
    int xorResult = 0;

    for (int i = 0; i < arraySize; i++)
    {
        xorResult ^= inputArray[i]; // cancel out duplicates
    }

    return xorResult;
}

int main()
{
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    if (arraySize <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    vector<int> inputArray(arraySize);

    cout << "Enter " << arraySize << " elements: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> inputArray[i];
    }

    // Choose one approach to test:
    // int uniqueNumber = findUniqueNumberBruteForce(inputArray, arraySize);
    // int uniqueNumber = findUniqueNumberUsingMap(inputArray, arraySize);
    int uniqueNumber = findUniqueNumberUsingXOR(inputArray, arraySize);

    cout << "The number that appears only once is: " << uniqueNumber << endl;

    return 0;
}
