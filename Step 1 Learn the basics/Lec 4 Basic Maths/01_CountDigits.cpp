#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Counts the number of digits in a given integer.
 *
 * This function repeatedly divides the number by 10 until it becomes 0,
 * incrementing a counter at each step. The final count is the total
 * number of digits in the integer.
 *
 * @param number The integer input for which the digit count is calculated.
 * @return int The total number of digits in the input integer.
 *
 * Example:
 * countNumberOfDigits(1234) -> 4
 */
int countNumberOfDigits(int number)
{
    // Handle the case when the input is 0 (should return 1 digit)
    if (number == 0)
        return 1;

    int digitCount = 0;

    // Remove last digit in each iteration until the number becomes 0
    while (number > 0)
    {
        number /= 10; // Equivalent to removing the last digit
        digitCount++; // Increase the digit counter
    }

    return digitCount;
}

int main()
{
    int inputNumber;

    cout << "Enter a number: ";
    cin >> inputNumber;

    // Call the function to count digits
    int result = countNumberOfDigits(inputNumber);

    // Display result
    cout << "Number of digits in the input: " << result << endl;

    return 0;
}
