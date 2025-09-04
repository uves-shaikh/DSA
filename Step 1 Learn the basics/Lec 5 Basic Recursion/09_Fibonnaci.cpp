#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively computes the nth Fibonacci number.
 *
 * @param n Index (0-based) of the Fibonacci sequence.
 * @return int The nth Fibonacci number.
 *
 * Base cases:
 * - F(0) = 0
 * - F(1) = 1
 *
 * Recursive case:
 * - F(n) = F(n-1) + F(n-2)
 *
 * Example:
 * Input: n = 5
 * Output: 5  (sequence: 0, 1, 1, 2, 3, 5)
 *
 * Time Complexity: O(2^n) (exponential, due to repeated subproblems)
 * Space Complexity: O(n) (recursion stack depth)
 */
int fibonacciRecursive(int n)
{
    if (n <= 1) // Base case
        return n;

    // Recursive calls
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main()
{
    int n;
    cout << "Enter position (n >= 0): ";
    cin >> n;

    // Input validation
    if (n < 0)
    {
        cout << "Fibonacci is not defined for negative numbers." << endl;
        return 1;
    }

    int result = fibonacciRecursive(n);

    cout << "Fibonacci number at position " << n << " is " << result << endl;

    return 0;
}
