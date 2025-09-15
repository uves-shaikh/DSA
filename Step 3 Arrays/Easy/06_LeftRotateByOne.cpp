#include <bits/stdc++.h>
using namespace std;

/**
 * Rotates the array to the left by one position.
 *
 * Example:
 * Input  : [1, 2, 3, 4, 5]
 * Output : [2, 3, 4, 5, 1]
 *
 * @param numbers The input array
 * @param size    Size of the array
 *
 * Approach:
 * - Store the first element temporarily.
 * - Shift every element one step left.
 * - Place the first element at the end of the array.
 *
 * Time Complexity: O(n)  → single pass for shifting
 * Space Complexity: O(1) → in-place rotation
 */
void rotateArrayLeftByOne(vector<int> &numbers, int size)
{
    int firstElement = numbers[0]; // Save the first element
    for (int i = 1; i < size; i++)
    {
        numbers[i - 1] = numbers[i]; // Shift elements left
    }
    numbers[size - 1] = firstElement; // Place first element at the end
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

    rotateArrayLeftByOne(numbers, size);

    cout << "Rotated Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
