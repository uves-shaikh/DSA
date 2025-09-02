#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively prints numbers from `counter` up to `limit`.
 *
 * @param counter Current number to print (starting point).
 * @param limit   Maximum number to print.
 *
 * The function starts at `counter` and prints sequentially until
 * `counter > limit`, where recursion stops.
 *
 * Example: printNumber(1, 5) will print:
 * 1
 * 2
 * 3
 * 4
 * 5
 */
void printNumber(int counter, int limit)
{
    // Base case: stop recursion when counter exceeds limit
    if (counter > limit)
        return;

    // Print current number
    cout << counter << endl;

    // Recursive call: increment counter
    printNumber(counter + 1, limit);
}

int main()
{
    int n;                // User input: upper limit of numbers to print
    int startCounter = 1; // Start printing from 1

    cout << "Enter a positive number: ";
    cin >> n;

    // Input validation: ensure n is >= 1
    if (n < 1)
    {
        cout << "Please enter a number greater than or equal to 1." << endl;
        return 1; // Exit with error code
    }

    // Call recursive function
    printNumber(startCounter, n);

    return 0;
}
