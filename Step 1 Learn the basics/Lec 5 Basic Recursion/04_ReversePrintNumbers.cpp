#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively prints numbers from n down to 1.
 *
 * @param n Starting number to print (should be >= 1).
 *
 * The function prints the current number, then calls itself
 * with (n - 1) until it reaches 0 (base case).
 *
 * Example: printNumber(5) will print:
 * 5
 * 4
 * 3
 * 2
 * 1
 */
void printNumberDescending(int n)
{
    // Base case: stop recursion when n becomes 0 or negative
    if (n <= 0)
        return;

    // Print the current number
    cout << n << endl;

    // Recursive call: decrement n
    printNumberDescending(n - 1);
}

int main()
{
    int n; // User input: starting number
    cout << "Enter a positive number: ";
    cin >> n;

    // Input validation: ensure n is >= 1
    if (n < 1)
    {
        cout << "Please enter a number greater than or equal to 1." << endl;
        return 1; // Exit with error code
    }

    // Call recursive function
    printNumberDescending(n);

    return 0;
}
