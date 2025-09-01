#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Checks if a given integer is a prime number.
 *
 * A prime number is a natural number greater than 1 that
 * has exactly two divisors: 1 and the number itself.
 *
 * @param n The integer to be checked.
 * @return true if n is prime, false otherwise.
 */
bool isPrime(int n)
{
    if (n <= 1)
        return false; // 0, 1, and negatives are not prime
    if (n == 2)
        return true; // 2 is the smallest prime
    if (n % 2 == 0)
        return false; // eliminate even numbers > 2

    // Check odd divisors up to sqrt(n)
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false; // divisor found → not prime
        }
    }

    return true; // no divisors found → prime
}

int main()
{
    int inputNumber;
    cout << "Enter a number: ";
    cin >> inputNumber;

    // Call function to check if number is prime
    bool result = isPrime(inputNumber);

    if (result)
    {
        cout << "Number is a prime." << endl;
    }
    else
    {
        cout << "Number is not a prime." << endl;
    }

    return 0;
}
