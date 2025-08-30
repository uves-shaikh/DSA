#include <iostream>
using namespace std;

/*
 * Function: printInvertedTriangle
 * -------------------------------
 * Prints an inverted right-angled triangle pattern of '*' characters.
 *
 * Parameters:
 *   n (int) - The number of rows.
 *
 * Example:
 *   Input: n = 4
 *   Output:
 *     * * * *
 *     * * *
 *     * *
 *     *
 *
 * Time Complexity: O(n^2)
 *   - Outer loop runs 'n' times.
 *   - Inner loop runs up to (n - i + 1) times per row.
 *   - Total operations = n + (n-1) + ... + 1 = O(n^2).
 *
 * Space Complexity: O(1)
 *   - Uses only a few variables regardless of input size.
 */
void printInvertedTriangle(int n)
{
    // Outer loop controls the number of rows
    for (int i = 1; i <= n; i++)
    {
        // Inner loop prints decreasing stars per row
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << "* ";
        }
        cout << endl; // Move to the next line after printing one row
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

    // Print the inverted right-angled triangle pattern
    printInvertedTriangle(n);

    return 0; // Successful program termination
}
