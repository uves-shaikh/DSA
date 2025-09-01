#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Calculates the HCF (GCD) of two integers using brute force.
 *
 * Starts from the smaller of the two numbers and checks downwards
 * until it finds the largest integer that divides both numbers.
 *
 * @param n1 First integer
 * @param n2 Second integer
 * @return int HCF of n1 and n2
 */
int getHcfByBruteForce(int n1, int n2)
{
    int hcf = 1;
    for (int i = min(n1, n2); i > 0; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            hcf = i;
            break;
        }
    }
    return hcf;
}

/**
 * @brief Calculates the HCF (GCD) of two integers using Euclid's algorithm.
 *
 * The algorithm repeatedly replaces the larger number with its remainder
 * when divided by the smaller number until one of them becomes 0.
 * The non-zero value is the HCF.
 *
 * @param a First integer
 * @param b Second integer
 * @return int HCF of a and b
 */
int getHcfByEuclid(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return max(a, b);
}

int main()
{
    int inputNumber1, inputNumber2;

    cout << "Enter number1: ";
    cin >> inputNumber1;

    cout << "Enter number2: ";
    cin >> inputNumber2;

    // Call function to get HCF using Brute Force
    int hcfBrute = getHcfByBruteForce(inputNumber1, inputNumber2);
    cout << "HCF (Brute Force) of " << inputNumber1 << " and " << inputNumber2 << " is " << hcfBrute << endl;

    // Call function to get HCF using Euclid's Algorithm
    int hcfEuclid = getHcfByEuclid(inputNumber1, inputNumber2);
    cout << "HCF (Euclid) of " << inputNumber1 << " and " << inputNumber2 << " is " << hcfEuclid << endl;

    return 0;
}
