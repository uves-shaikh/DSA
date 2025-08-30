#include <iostream>
using namespace std;

/*
 * Function: printPyramid
 * ----------------------
 * Prints a pyramid (isosceles triangle) pattern of '*' characters.
 *
 * Parameters:
 *   n (int) - The number of rows in the pyramid.
 *
 * Example:
 *   Input: n = 4
 *   Output:
 *         *
 *       * * *
 *     * * * * *
 *   * * * * * * *
 *
 * Time Complexity: O(n^2)
 *   - For each row, spaces and stars together take O(n) time.
 *   - Repeated for 'n' rows → O(n^2).
 *
 * Space Complexity: O(1)
 *   - Uses only a few variables regardless of input size.
 */
void printPyramid(int n)
{
    // Outer loop controls the number of rows
    for (int i = 1; i <= n; i++)
    {
        // Print leading spaces (to center the pyramid)
        for (int j = 1; j <= (n - i); j++)
        {
            cout << "  "; // Two spaces for alignment
        }

        // Print left half of pyramid (i stars)
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        // Print right half of pyramid (i - 1 stars)
        for (int j = 1; j <= (i - 1); j++)
        {
            cout << "* ";
        }

        cout << endl; // Move to next row
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

    // Print the pyramid pattern
    printPyramid(n);

    return 0; // Successful program termination
}
