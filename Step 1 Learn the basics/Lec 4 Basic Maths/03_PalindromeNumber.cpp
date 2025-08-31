#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Checks if a given integer is a palindrome.
 *
 * A palindrome number is one that remains the same when its digits are reversed.
 * Example: 121, 1331, 12321 are palindromes.
 *
 * Steps:
 *  1. Store the original number.
 *  2. Reverse the number digit by digit.
 *  3. Compare the reversed number with the original.
 *
 * @param number The integer to be checked.
 * @return true if the number is a palindrome, false otherwise.
 */
bool isPalindrome(int number)
{
    int originalNumber = number;
    int reversedNumber = 0;

    while (number > 0)
    {
        int lastDigit = number % 10;                        // Extract last digit
        reversedNumber = (reversedNumber * 10) + lastDigit; // Append digit
        number /= 10;                                       // Remove last digit
    }

    return (originalNumber == reversedNumber);
}

int main()
{
    int inputNumber;

    cout << "Enter a number: ";
    cin >> inputNumber;

    // Call function to check if number is palindrome
    bool result = isPalindrome(inputNumber);

    if (result)
    {
        cout << "Number is a palindrome." << endl;
    }
    else
    {
        cout << "Number is not a palindrome." << endl;
    }

    return 0;
}
