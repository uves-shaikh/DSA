#include <iostream>
using namespace std;

/*
 * Function: printAlphabetTriangle
 * -------------------------------
 * Prints a right-angled triangle where each row contains
 * repeated alphabets, starting from 'A'.
 *
 * Example (n = 5):
 *   A
 *   B B
 *   C C C
 *   D D D D
 *   E E E E E
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void printAlphabetTriangle(int n)
{
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        ch++; // Move to next alphabet for next row
        cout << endl;
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
        return 1;
    }

    // Print the alphabet triangle pattern
    printAlphabetTriangle(n);

    return 0; // Successful program termination
}
