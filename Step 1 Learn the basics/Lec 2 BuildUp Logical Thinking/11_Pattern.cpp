#include <iostream>
using namespace std;

/*
 * Function: printNumberPattern
 * ----------------------------
 * Prints a symmetric number pattern.
 *
 * Example (n = 5):
 *   1                 1
 *   1 2             2 1
 *   1 2 3         3 2 1
 *   1 2 3 4     4 3 2 1
 *   1 2 3 4 5 5 4 3 2 1
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void printNumberPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // Print ascending numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        // Print spaces (double space for alignment)
        for (int j = 1; j <= (n - i) * 2; j++)
        {
            cout << " ";
        }

        // Print descending numbers
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
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
        return 1;
    }

    printNumberPattern(n);

    return 0;
}
