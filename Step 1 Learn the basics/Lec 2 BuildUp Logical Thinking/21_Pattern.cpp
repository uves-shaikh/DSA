#include <iostream>
using namespace std;

/*
 * Function: printConcentricSquare
 * -------------------------------
 * Prints a concentric number square pattern of size (2n-1) × (2n-1).
 *
 * Example (n = 4):
 * 4444444
 * 4333334
 * 4322234
 * 4321234
 * 4322234
 * 4333334
 * 4444444
 *
 * Logic:
 * - Each cell (i, j) depends on the minimum distance from the border.
 * - Value = n - min(top, bottom, left, right).
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void printConcentricSquare(int n)
{
    int size = 2 * n - 1;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int top = i;               // distance from top border
            int left = j;              // distance from left border
            int right = size - 1 - j;  // distance from right border
            int bottom = size - 1 - i; // distance from bottom border

            // Minimum distance from any border
            int layer = min(min(top, bottom), min(left, right));

            cout << (n - layer);
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

    printConcentricSquare(n);

    return 0;
}
