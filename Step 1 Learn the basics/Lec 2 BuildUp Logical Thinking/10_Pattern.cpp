#include <iostream>
using namespace std;

/*
 * Function: printBinaryTriangle
 * -----------------------------
 * Prints a right-angled triangle of binary numbers (0s and 1s)
 * where each row alternates between 1 and 0.
 *
 * Rule:
 *   - Odd rows start with 1.
 *   - Even rows start with 0.
 *   - Each subsequent number alternates.
 *
 * Parameters:
 *   n (int) - The number of rows.
 *
 * Example:
 *   Input: n = 5
 *   Output:
 *     1
 *     01
 *     101
 *     0101
 *     10101
 *
 * Time Complexity: O(n^2)
 *   - Outer loop runs 'n' times.
 *   - Inner loop runs up to 'i' times per row.
 *   - Total operations = O(n^2).
 *
 * Space Complexity: O(1)
 *   - Uses only a few variables regardless of input size.
 */
void printBinaryTriangle(int n)
{
    int start;

    // Outer loop controls the number of rows
    for (int i = 1; i <= n; i++)
    {
        // Decide starting value for each row
        if (i % 2 == 0)
            start = 0;
        else
            start = 1;

        // Inner loop prints alternating 1s and 0s
        for (int j = 1; j <= i; j++)
        {
            cout << start;
            start = 1 - start; // Toggle between 1 and 0
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

    // Print the binary triangle pattern
    printBinaryTriangle(n);

    return 0; // Successful program termination
}
