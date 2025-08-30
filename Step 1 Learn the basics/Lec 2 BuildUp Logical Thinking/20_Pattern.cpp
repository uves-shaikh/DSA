#include <iostream>
using namespace std;

/*
 * Function: printHollowSquare
 * ---------------------------
 * Prints a hollow square pattern of size n.
 *
 * Example (n = 5):
 * * * * * *
 * *       *
 * *       *
 * *       *
 * * * * * *
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void printHollowSquare(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // Print star on boundary (first row, last row, first col, last col)
            if (i == 1 || i == n || j == 1 || j == n)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int n;

    cout << "Enter number of rows: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of rows must be positive!" << endl;
        return 1; // Exit with error code
    }

    printHollowSquare(n);

    return 0;
}
