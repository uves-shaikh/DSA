#include <iostream>
using namespace std;

/*
 * Function: printReverseAlphabetTriangle
 * --------------------------------------
 * Prints a reverse right-angled triangle of alphabets.
 *
 * Example (n = 5):
 *   A B C D E
 *   A B C D
 *   A B C
 *   A B
 *   A
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void printReverseAlphabetTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // Print characters from 'A' up to ('A' + (n - i))
        for (char ch = 'A'; ch <= 'A' + (n - i); ch++)
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
    printReverseAlphabetTriangle(n);

    return 0;
}
