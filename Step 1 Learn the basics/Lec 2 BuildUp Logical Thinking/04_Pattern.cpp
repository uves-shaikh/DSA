#include <iostream>
using namespace std;

/*
 * Function: printRowNumberTriangle
 * --------------------------------
 * Prints a right-angled triangular pattern where each row consists
 * of the row number repeated.
 *
 * Parameters:
 *   n (int) - The number of rows.
 *
 * Example:
 *   Input: n = 4
 *   Output:
 *     1
 *     2 2
 *     3 3 3
 *     4 4 4 4
 *
 * Time Complexity: O(n^2)
 *   - Outer loop runs 'n' times.
 *   - Inner loop runs up to 'i' times per row.
 *   - Total operations = 1 + 2 + ... + n = O(n^2).
 *
 * Space Complexity: O(1)
 *   - Uses only a few variables regardless of input size.
 */
void printRowNumberTriangle(int n)
{
    // Outer loop controls rows
    for (int i = 1; i <= n; i++)
    {
        // Inner loop prints the current row number 'i', 'i' times
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl; // Move to next line after each row
    }
}

int main()
{
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    // Validate input: must be positive
    if (n <= 0)
    {
        cout << "Number of rows must be positive!" << endl;
        return 1; // Exit with error code
    }

    // Print the row-number triangle
    printRowNumberTriangle(n);

    return 0;
}
