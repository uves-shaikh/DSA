#include <iostream>
using namespace std;

/*
 * Function: printAlphabetPyramid
 * -------------------------------
 * Prints a pyramid where each row contains alphabets
 * in palindromic order (increasing then decreasing).
 *
 * Example (n = 5):
 *         A
 *       A B A
 *     A B C B A
 *   A B C D C B A
 * A B C D E D C B A
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void printAlphabetPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Print leading spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }

        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;

        // Print characters in palindromic fashion
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch << " ";
            if (j <= breakpoint)
                ch++; // increase till middle
            else
                ch--; // decrease after middle
        }

        // Print trailing spaces (not necessary but keeps symmetry)
        for (int j = 0; j < n - i - 1; j++)
        {
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
        return 1;
    }

    printAlphabetPyramid(n);

    return 0;
}
