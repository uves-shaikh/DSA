#include <iostream>
using namespace std;

/*
 * Function: printInvertedPyramid
 * ------------------------------
 * Prints an inverted pyramid (upside-down triangle) pattern of '*' characters.
 *
 * Parameters:
 *   n (int) - The number of rows in the inverted pyramid.
 *
 * Example:
 *   Input: n = 4
 *   Output:
 *     * * * * * * *
 *       * * * * *
 *         * * *
 *           *
 *
 * Time Complexity: O(n^2)
 *   - For each row, spaces and stars together take O(n).
 *   - Repeated for 'n' rows → O(n^2).
 *
 * Space Complexity: O(1)
 *   - Uses only a few variables regardless of input size.
 */
void printInvertedPyramid(int n)
{
    // Outer loop for rows (from n down to 1)
    for (int i = n; i > 0; i--)
    {
        // Print leading spaces to center align the pyramid
        for (int j = 1; j <= (n - i); j++)
        {
            cout << "  "; // Two spaces for alignment
        }

        // Print stars for the current row
        for (int j = 1; j <= ((2 * i) - 1); j++)
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

    // Print the inverted pyramid pattern
    printInvertedPyramid(n);

    return 0; // Successful program termination
}
