#include <iostream>
using namespace std;

/*
 * Function: printDiamond
 * ----------------------
 * Prints a diamond (rhombus) pattern of '*' characters by combining
 * a pyramid and an inverted pyramid.
 *
 * Parameters:
 *   n (int) - The number of rows for the upper half of the diamond.
 *
 * Example:
 *   Input: n = 4
 *   Output:
 *         *
 *       * * *
 *     * * * * *
 *   * * * * * * *
 *   * * * * * * *
 *     * * * * *
 *       * * *
 *         *
 *
 * Time Complexity: O(n^2)
 *   - Each half (pyramid + inverted pyramid) takes O(n^2).
 *   - Overall still O(n^2).
 *
 * Space Complexity: O(1)
 *   - Uses only a few variables regardless of input size.
 */
void printDiamond(int n)
{
    // ---------------------
    // Print upper pyramid
    // ---------------------
    for (int i = 1; i <= n; i++)
    {
        // Print leading spaces
        for (int j = 1; j <= (n - i); j++)
        {
            cout << "  ";
        }

        // Print stars
        for (int j = 1; j <= (2 * i) - 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // ---------------------
    // Print inverted pyramid
    // ---------------------
    for (int i = n; i > 0; i--)
    {
        // Print leading spaces
        for (int j = 1; j <= (n - i); j++)
        {
            cout << "  ";
        }

        // Print stars
        for (int j = 1; j <= (2 * i) - 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
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

    // Print the diamond pattern
    printDiamond(n);

    return 0; // Successful program termination
}
