#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Checks if a number is an Armstrong number.
 *
 * An Armstrong number (also called a narcissistic number) is a number that is
 * equal to the sum of its digits raised to the power of the number of digits.
 *
 * Example:
 *  - 153 = 1^3 + 5^3 + 3^3
 *  - 9474 = 9^4 + 4^4 + 7^4 + 4^4
 *
 * @param num The number to check.
 * @return true if the number is Armstrong, false otherwise.
 */
bool isArmstrong(long long num)
{
    if (num < 0)
        return false; // Negative numbers are not Armstrong

    long long number = num;
    int digits = 0;

    // Count number of digits
    long long temp = num;
    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }

    long long sum = 0;
    temp = num;

    // Compute sum of each digit raised to 'digits'
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += pow(digit, digits); // pow() may return double but small inputs are safe
        temp /= 10;
    }

    return (sum == num);
}

int main()
{
    long long n;
    cout << "Enter your number: ";
    cin >> n;

    bool result = isArmstrong(n);

    if (result)
    {
        cout << "Number is an Armstrong number." << endl;
    }
    else
    {
        cout << "Number is not an Armstrong number." << endl;
    }

    return 0;
}
