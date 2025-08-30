#include <iostream>
using namespace std;

/*
 * Function: printPattern
 * ----------------------
 * Prints a right-angled triangular pattern of '*' characters.
 *
 * Parameters:
 *   n (int) - The number of rows to print.
 *
 * Example:
 *   Input: n = 3
 *   Output:
 *     *
 *     * *
 *     * * *
 *
 * Time Complexity: O(n^2)
 *   - The outer loop runs 'n' times.
 *   - The inner loop runs up to 'i' times per row.
 *   - Total operations = 1 + 2 + ... + n = O(n^2).
 *
 * Space Complexity: O(1)
 *   - Uses only a few extra variables regardless of input size.
 */
void printPattern(int n)
{
    // Outer loop controls the number of rows
    for (int i = 1; i <= n; i++) // Start from 1 so first row prints 1 star
    {
        // Inner loop prints '*' characters for the current row
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl; // Move to the next line after finishing one row
    }
}

int main()
{
    int n;

    // Prompt user to input
    cout << "Enter number of rows: ";
    cin >> n;

    // Validate input: number of rows must be positive
    if (n <= 0)
    {
        cout << "Number of rows must be positive!" << endl;
        return 1; // Exit with error code
    }

    // Print the right-angled triangle pattern
    printPattern(n);

    return 0; // Successful program termination
}
