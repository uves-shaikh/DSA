#include <iostream>
using namespace std;

/*
 * Function: printAlphabetTriangle
 * -------------------------------
 * Prints a right-angled triangle where each row starts
 * with a decreasing alphabet (from 'A' + n - i)
 * and increments across the row.
 *
 * Example (n = 5):
 * E
 * D E
 * C D E
 * B C D E
 * A B C D E
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void printAlphabetTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + n - i; // Starting character for the row
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch++; // Move to next alphabet
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

    printAlphabetTriangle(n);

    return 0;
}
