#include <iostream>
using namespace std;

/*
 * Function: printPattern
 * ----------------------
 * Prints a square pattern of '*' characters of size n x n.
 *
 * Parameters:
 *   n (int) - The number of rows and columns of the square.
 *
 * Example:
 *   Input: n = 3
 *   Output:
 *     ***
 *     ***
 *     ***
 *
 * Time Complexity: O(n^2) - Two nested loops iterate n * n times.
 * Space Complexity: O(1) - Constant extra space.
 */
void printPattern(int n)
{
    // Outer loop controls the number of rows
    for (int i = 0; i < n; i++)
    {
        // Inner loop prints 'n' stars per row
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl; // Move to the next line after printing one row
    }
}

int main()
{
    int n;

    // Prompt user for input
    cout << "Enter number of rows: ";
    cin >> n;

    // Validate input: number of rows must be positive
    if (n <= 0)
    {
        cout << "Number of rows must be positive!" << endl;
        return 1; // Exit with error code
    }

    // Print the square pattern
    printPattern(n);

    return 0; // Successful program termination
}
