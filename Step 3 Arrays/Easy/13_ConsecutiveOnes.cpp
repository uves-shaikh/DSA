#include <bits/stdc++.h>
using namespace std;

/*
 * Function: findMaxConsecutiveOnes
 * --------------------------------
 * Finds the length of the longest consecutive sequence of 1s in a binary array.
 *
 * Approach:
 * - Traverse the array while maintaining a running count of consecutive 1s.
 * - Reset count to 0 whenever a 0 is encountered.
 * - Keep track of the maximum count observed during traversal.
 *
 * Parameters:
 * - inputArray: vector<int>, array containing 0s and 1s
 * - arraySize: int, size of the array
 *
 * Returns:
 * - Integer representing the maximum number of consecutive 1s
 *
 * Time Complexity: O(n)  → single pass through the array
 * Space Complexity: O(1) → uses constant extra space
 */
int findMaxConsecutiveOnes(vector<int> inputArray, int arraySize)
{
    int currentCount = 0; // tracks current streak of consecutive 1s
    int maxCount = 0;     // stores the maximum streak found

    for (int i = 0; i < arraySize; i++)
    {
        if (inputArray[i] == 1)
        {
            currentCount++;
            maxCount = max(maxCount, currentCount); // update max when longer streak found
        }
        else
        {
            currentCount = 0; // reset streak when 0 is encountered
        }
    }

    return maxCount;
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

    cout << "Enter " << arraySize << " elements (0s and 1s only):" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> inputArray[i];
    }

    int maxLengthOfConsecutiveOnes = findMaxConsecutiveOnes(inputArray, arraySize);

    cout << "The maximum length of consecutive 1s is: " << maxLengthOfConsecutiveOnes << endl;

    return 0;
}
