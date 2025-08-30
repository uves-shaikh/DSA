#include <iostream>
using namespace std;

/*
 * Function: printNumberTriangle
 * -----------------------------
 * Prints a right-angled triangle pattern where each row contains
 * increasing numbers starting from 1 up to the row index.
 *
 * Parameters:
 *   n (int) - The number of rows.
 *
 * Example:
 *   Input: n = 4
 *   Output:
 *     1
 *     1 2
 *     1 2 3
 *     1 2 3 4
 *
 * Time Complexity: O(n^2)
 *   - Outer loop runs 'n' times.
 *   - Inner loop runs up to 'i' times per row.
 *   - Total operations = 1 + 2 + ... + n = O(n^2).
 *
 * Space Complexity: O(1)
 *   - Uses only a few variables regardless of input size.
 */
void printNumberTriangle(int n)
{
    // Outer loop for rows
    for (int i = 1; i <= n; i++)
    {
        // Inner loop prints numbers from 1 to i
        for (int j = 1; j <= i; j++)
        {
            cout << j << " "; // Print number followed by space
        }
        cout << endl; // Move to next line after finishing a row
    }
}

int main()
{
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    // Validate input
    if (n <= 0)
    {
        cout << "Number of rows must be positive!" << endl;
        return 1;
    }

    // Print the number triangle pattern
    printNumberTriangle(n);

    return 0;
}
