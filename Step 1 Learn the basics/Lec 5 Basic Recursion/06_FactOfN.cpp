#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively calculates the factorial of a number.
 *
 * @param n The number whose factorial is to be calculated.
 * @return int The factorial of n.
 *
 * Base case: factorial(1) = 1
 * Recursive case: factorial(n) = n * factorial(n - 1)
 *
 * Example:
 * factorial(5) = 5 * 4 * 3 * 2 * 1 = 120
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursion stack)
 */
int factorialOfN(int n)
{
    if (n == 1) // Base case
        return 1;

    return n * factorialOfN(n - 1); // Recursive step
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    // Input validation
    if (n < 0)
    {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1; // Error exit
    }
    if (n == 0)
    {
        cout << "Factorial of 0 is 1" << endl;
        return 0; // Special case
    }

    // Recursive call
    int result = factorialOfN(n);

    cout << "Factorial of " << n << " is " << result << endl;

    return 0;
}
