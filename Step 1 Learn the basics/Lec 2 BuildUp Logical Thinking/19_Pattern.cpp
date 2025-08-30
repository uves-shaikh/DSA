#include <iostream>
using namespace std;

/*
 * Function: printButterflyPattern
 * -------------------------------
 * Prints a hollow butterfly pattern of size n.
 *
 * Example (n = 4):
 * *       *
 * * *   * *
 * * * * * *
 * * * * * *
 * * * * * *
 * * *   * *
 * *       *
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void printButterflyPattern(int n)
{
    // Upper half
    for (int i = 0; i < n; i++)
    {
        // Left stars
        for (int j = 0; j < i + 1; j++)
            cout << "* ";

        // Middle spaces
        for (int j = 1; j <= 2 * (n - i) - 2; j++)
            cout << "  ";

        // Right stars
        for (int j = 0; j < i + 1; j++)
            cout << "* ";

        cout << endl;
    }

    // Lower half
    for (int i = 1; i < n; i++)
    {
        // Left stars
        for (int j = 0; j < n - i; j++)
            cout << "* ";

        // Middle spaces
        for (int j = 1; j <= 2 * i; j++)
            cout << "  ";

        // Right stars
        for (int j = 0; j < n - i; j++)
            cout << "* ";

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

    printButterflyPattern(n);

    return 0;
}
