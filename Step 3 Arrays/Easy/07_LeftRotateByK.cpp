#include <bits/stdc++.h>
using namespace std;

/**
 * Rotates the array to the left by k positions.
 *
 * Example:
 * Input  : [1, 2, 3, 4, 5], k = 2
 * Output : [3, 4, 5, 1, 2]
 *
 * @param numbers The input array
 * @param size    Size of the array
 * @param k       Number of positions to rotate
 *
 * Approach:
 * - Use modulo to handle cases where k >= size.
 * - Create a temporary copy of the original array.
 * - Place each element at its rotated index: (i + k) % size.
 *
 * Time Complexity: O(n)  → one pass through the array
 * Space Complexity: O(n) → extra space for temporary array
 */
void rotateArrayLeftByK(vector<int> &numbers, int size, int k)
{
    k = k % size; // Handle case where k >= size
    vector<int> temp = numbers;

    for (int i = 0; i < size; i++)
    {
        numbers[i] = temp[(i + k) % size]; // Shift elements by k
    }
}

int main()
{
    int size, k;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Error: Array size must be positive." << endl;
        return 1;
    }

    cout << "Enter the number of positions to rotate (k): ";
    cin >> k;

    vector<int> numbers(size);
    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    rotateArrayLeftByK(numbers, size, k);

    cout << "Array after rotating left by " << k % size << " positions: ";
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
