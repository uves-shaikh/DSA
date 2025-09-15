#include <bits/stdc++.h>
using namespace std;

/**
 * Brute Force Approach:
 * Move all non-zero elements to a temporary array,
 * then copy them back followed by zeros.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void pushZerosAtEndWithBruteForce(vector<int> &numbers)
{
    int size = numbers.size();
    vector<int> nonZeroElements;

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] != 0)
        {
            nonZeroElements.push_back(numbers[i]);
        }
    }

    for (int i = 0; i < nonZeroElements.size(); i++)
    {
        numbers[i] = nonZeroElements[i];
    }

    for (int i = nonZeroElements.size(); i < size; i++)
    {
        numbers[i] = 0;
    }
}

/**
 * Optimal Approach:
 * Find the first zero, then swap with subsequent non-zero elements.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void pushZerosAtEndWithOptimal(vector<int> &numbers)
{
    int size = numbers.size();
    int zeroIndex = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] == 0)
        {
            zeroIndex = i;
            break;
        }
    }

    if (zeroIndex == INT_MIN)
        return;

    for (int i = zeroIndex + 1; i < size; i++)
    {
        if (numbers[i] != 0)
        {
            swap(numbers[i], numbers[zeroIndex]);
            zeroIndex++;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Error: Array size must be positive." << endl;
        return 1;
    }

    vector<int> numbers(size);
    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Choose the method:
    // pushZerosAtEndWithBruteForce(numbers);
    pushZerosAtEndWithOptimal(numbers);

    cout << "Array after moving zeros to the end: ";
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
