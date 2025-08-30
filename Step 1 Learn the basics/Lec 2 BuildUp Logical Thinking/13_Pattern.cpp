#include <iostream>
using namespace std;

/*
 * Function: printAlphabetTriangle
 * -------------------------------
 * Prints a right-angled triangle of alphabets up to n rows.
 *
 * Example (n = 5):
 *   A
 *   A B
 *   A B C
 *   A B C D
 *   A B C D E
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void printAlphabetTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // Print characters from 'A' up to ('A' + i - 1)
        for (char ch = 'A'; ch <= 'A' + i - 1; ch++)
        {
            cout << ch << " ";
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
    printAlphabetTriangle(n);

    return 0;
}
