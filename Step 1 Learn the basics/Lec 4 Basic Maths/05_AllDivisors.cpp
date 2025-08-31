#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Computes all divisors of a positive integer.
 *
 * iterate only up to sqrt(num).
 * For every divisor 'i' found, insert both 'i' and 'num/i'.
 *
 * @param num The number for which divisors are to be found (must be > 0).
 * @return set<int> A sorted set of all divisors of num.
 */
set<int> getDivisors(int num)
{
    set<int> divisors;

    if (num <= 0)
    {
        // For negative or zero, return empty set
        return divisors;
    }

    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            divisors.insert(i);       // Insert divisor
            divisors.insert(num / i); // Insert the complementary divisor
        }
    }

    return divisors;
}

int main()
{
    int n;
    cout << "Enter your number: ";
    cin >> n;

    set<int> result = getDivisors(n);

    cout << "Divisors: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
