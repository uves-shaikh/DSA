#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Reverses the digits of an integer with overflow handling.
 *
 * This function extracts the last digit using modulo (%), and builds
 * the reversed number step by step. Before each update, it checks if
 * the next multiplication/addition would overflow a 32-bit signed int.
 *
 * @param number The integer to be reversed.
 * @return int The reversed integer, or 0 if overflow occurs.
 *
 * Example:
 * reverseInteger(1234) -> 4321
 * reverseInteger(-123) -> -321
 * reverseInteger(1534236469) -> 0 (overflow)
 */
int reverseInteger(int number)
{
    int reversedNumber = 0;

    while (number != 0)
    {
        int lastDigit = number % 10;
        number /= 10;

        // overflow condition
        if (reversedNumber > INT_MAX / 10 ||
            (reversedNumber == INT_MAX / 10 && lastDigit > 7))
        {
            return 0;
        }
        if (reversedNumber < INT_MIN / 10 ||
            (reversedNumber == INT_MIN / 10 && lastDigit < -8))
        {
            return 0;
        }

        reversedNumber = reversedNumber * 10 + lastDigit;
    }

    return reversedNumber;
}

int main()
{
    int inputNumber;

    cout << "Enter a number: ";
    cin >> inputNumber;

    // Call function to reverse number
    int result = reverseInteger(inputNumber);

    cout << "Reversed number: " << result << endl;

    return 0;
}
