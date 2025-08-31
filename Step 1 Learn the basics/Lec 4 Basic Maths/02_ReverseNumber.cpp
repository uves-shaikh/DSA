#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Reverses the digits of an integer.
 *
 * This function extracts the last digit of the number using modulo (%),
 * and appends it to the reversed number by shifting the current reversed
 * digits left (multiplying by 10). The process continues until all digits
 * of the original number are processed.
 *
 * @param number The integer to be reversed.
 * @return int The reversed integer.
 *
 * Example:
 * reverseInteger(1234) -> 4321
 */
int reverseInteger(int number)
{
    int reversedNumber = 0;

    while (number > 0)
    {
        int lastDigit = number % 10;                        // Extract the last digit
        reversedNumber = (reversedNumber * 10) + lastDigit; // Append digit to reversed number
        number /= 10;                                       // Remove the last digit
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
