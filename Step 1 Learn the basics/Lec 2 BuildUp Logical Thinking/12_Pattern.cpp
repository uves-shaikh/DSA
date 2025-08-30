#include <iostream>
using namespace std;

/*
 * Function: printFloydsTriangle
 * -----------------------------
 * Prints Floyd’s Triangle pattern up to n rows.
 *
 * Example (n = 5):
 *   1
 *   2 3
 *   4 5 6
 *   7 8 9 10
 *   11 12 13 14 15
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void printFloydsTriangle(int n)
{
    int number = 1; // start counting from 1
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << number << " ";
            number++;
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

    // Call the renamed function
    printFloydsTriangle(n);

    return 0;
}
