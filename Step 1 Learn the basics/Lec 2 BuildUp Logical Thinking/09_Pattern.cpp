#include <iostream>
using namespace std;

/*
 * Function: printHalfDiamond
 * --------------------------
 * Prints a half-diamond star pattern. The number of stars
 * increases row by row until 'n', then decreases symmetrically.
 *
 * Parameters:
 *   n (int) - The maximum number of stars in the middle row.
 *
 * Example:
 *   Input: n = 4
 *   Output:
 *     *
 *     * *
 *     * * *
 *     * * * *
 *     * * *
 *     * *
 *     *
 *
 * Time Complexity: O(n^2)
 *   - Outer loop runs 2n-1 times.
 *   - Inner loop prints up to n stars per row.
 *   - Total operations = O(n^2).
 *
 * Space Complexity: O(1)
 *   - Uses only a few variables regardless of input size.
 */
void printHalfDiamond(int n)
{
    // Outer loop runs from row 1 to (2n-1)
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;

        // After reaching 'n', stars decrease
        if (i > n)
            stars = (2 * n) - i;

        // Print stars for the current row
        for (int j = 1; j <= stars; j++)
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

    // Print the half-diamond pattern
    printHalfDiamond(n);

    return 0; // Successful program termination
}
