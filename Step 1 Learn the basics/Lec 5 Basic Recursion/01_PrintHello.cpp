#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively prints "Hello" a given number of times.
 *
 * @param counter Current count of printed "Hello".
 * @param limit   Total number of times "Hello" should be printed.
 *
 * This function uses recursion. On each call, it prints "Hello" and
 * increments the counter until the counter exceeds the limit.
 *
 * Example: printHello(1, 3) will output "Hello" three times.
 */
void printHello(int counter, int limit)
{
    // Base case: if the counter exceeds the limit, stop recursion
    if (counter > limit)
        return;

    // Print the message
    cout << "Hello" << endl;

    // Recursive call: increment counter and continue
    printHello(counter + 1, limit);
}

int main()
{
    int n;                // Number of times user wants to print "Hello"
    int startCounter = 1; // Start counter at 1 for recursion

    cout << "Enter the number of times you want to print Hello: ";
    cin >> n;

    // Input validation: ensure n is non-negative
    if (n < 0)
    {
        cout << "Please enter a non-negative number." << endl;
        return 1; // Exit with error code
    }

    // Call recursive function
    printHello(startCounter, n);

    return 0;
}
