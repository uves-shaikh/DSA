#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Functional recursion approach to calculate sum of first n natural numbers.
 *
 * @param n The number up to which the sum is calculated.
 * @return int The computed sum.
 *
 * This function works by returning n + sumN(n-1) until n reaches 0.
 * Example: sumN(5) = 5 + 4 + 3 + 2 + 1 = 15
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (due to recursion stack)
 */
int sumN(int n)
{
    if (n == 0)
        return 0; // Base case: sum up to 0 is 0

    return n + sumN(n - 1); // Recursive case
}

/**
 * @brief Parameterized recursion approach to calculate sum of first n natural numbers.
 *
 * @param n   Current number to be added.
 * @param sum Accumulator that carries the computed sum across recursive calls.
 *
 * This function doesn’t return a value, instead prints the result once recursion ends.
 * Example: sumOfN(5, 0) -> prints 15
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (due to recursion stack)
 */
void sumOfN(int n, int sum)
{
    if (n <= 0)
    {
        cout << "Sum is: " << sum << endl;
        return; // Base case
    }

    // Recursive call with decremented n and updated sum
    sumOfN(n - 1, sum + n);
}

int main()
{
    int n;
    cout << "Enter a positive number: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Please enter a number greater than or equal to 1." << endl;
        return 1; // Invalid input
    }

    // --- Functional recursion call ---
    int sum = sumN(n);
    cout << "Sum of first " << n << " natural numbers (Functional): " << sum << endl;

    // --- Parameterized recursion call ---
    sumOfN(n, 0);

    return 0;
}
