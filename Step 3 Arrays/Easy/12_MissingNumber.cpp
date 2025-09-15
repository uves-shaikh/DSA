#include <bits/stdc++.h>
using namespace std;

/*
 * Function: findMissingNumberWithBruteforce
 * -----------------------------------------
 * Finds the missing number in an array of size (n-1)
 * that should contain numbers from 1 to n.
 *
 * Approach:
 * - For each number from 1 to n, check if it exists in the array.
 * - If not found, return that number.
 *
 * Parameters:
 * - inputArray: vector of integers containing (n-1) elements
 * - totalNumbers: the expected size of the sequence (n)
 *
 * Returns:
 * - The missing number in the sequence
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
int findMissingNumberWithBruteforce(vector<int> inputArray, int totalNumbers)
{
    for (int number = 1; number <= totalNumbers; number++)
    {
        bool isFound = false;

        for (int j = 0; j < totalNumbers - 1; j++)
        {
            if (inputArray[j] == number)
            {
                isFound = true;
                break;
            }
        }

        if (!isFound)
        {
            return number;
        }
    }
    return -1; // safety return in case of invalid input
}

/*
 * Function: findMissingNumberWithHashing
 * --------------------------------------
 * Uses hashing (extra array) to mark presence of numbers.
 *
 * Approach:
 * - Create a hash array of size n+1 initialized to 0.
 * - Mark each number's index as present.
 * - The index which remains unmarked is the missing number.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int findMissingNumberWithHashing(vector<int> inputArray, int totalNumbers)
{
    vector<int> hash(totalNumbers + 1, 0);

    for (int i = 0; i < totalNumbers - 1; i++)
    {
        hash[inputArray[i]] = 1;
    }

    for (int number = 1; number <= totalNumbers; number++)
    {
        if (hash[number] == 0)
        {
            return number;
        }
    }
    return -1;
}

/*
 * Function: findMissingNumberWithSum
 * ----------------------------------
 * Uses the formula for sum of first n natural numbers.
 *
 * Approach:
 * - Expected sum of numbers 1..n = n*(n+1)/2
 * - Subtract the actual sum of array elements.
 * - The difference is the missing number.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int findMissingNumberWithSum(vector<int> inputArray, int totalNumbers)
{
    int expectedSum = (totalNumbers * (totalNumbers + 1)) / 2;
    int actualSum = 0;

    for (int value : inputArray)
    {
        actualSum += value;
    }

    return expectedSum - actualSum;
}

/*
 * Function: findMissingNumberWithXOR
 * ----------------------------------
 * Uses XOR to find the missing number.
 *
 * Approach:
 * - XOR of 1..n with XOR of array elements leaves the missing number.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int findMissingNumberWithXOR(vector<int> inputArray, int totalNumbers)
{
    int xorAllNumbers = 0;    // XOR of 1..n
    int xorArrayElements = 0; // XOR of array elements

    for (int i = 1; i <= totalNumbers; i++)
    {
        xorAllNumbers ^= i;
    }

    for (int value : inputArray)
    {
        xorArrayElements ^= value;
    }

    return xorAllNumbers ^ xorArrayElements;
}

int main()
{
    int totalNumbers;
    cout << "Enter the total number (n) in the sequence: ";
    cin >> totalNumbers;

    if (totalNumbers <= 0)
    {
        cout << "Number must be positive." << endl;
        return 1;
    }

    vector<int> inputArray(totalNumbers - 1);

    cout << "Enter " << totalNumbers - 1 << " numbers from the sequence (1 to " << totalNumbers << "), excluding one missing number:" << endl;
    for (int i = 0; i < totalNumbers - 1; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> inputArray[i];
    }

    // Uncomment the method you want to test
    // int missingNumber = findMissingNumberWithBruteforce(inputArray, totalNumbers);
    // int missingNumber = findMissingNumberWithHashing(inputArray, totalNumbers);
    // int missingNumber = findMissingNumberWithSum(inputArray, totalNumbers);
    int missingNumber = findMissingNumberWithXOR(inputArray, totalNumbers);

    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}
