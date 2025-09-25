#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Converts an integer to its binary representation stored in a vector.
 *
 * @param n Input integer.
 * @return Vector containing binary digits in LSB -> MSB order.
 */
vector<int> convertToBinary(int n)
{
    if (n == 0)
        return {0};

    vector<int> binaryDigits;
    while (n > 0)
    {
        binaryDigits.push_back(n % 2); // store least significant bit first
        n = n / 2;
    }

    return binaryDigits;
}

/**
 * @brief Finds the position of the set bit if the number has exactly one set bit.
 *        Returns -1 if the number has zero or more than one set bit.
 *
 * @param number Input integer.
 * @return Position of the set bit (1-based), or -1 if invalid.
 *
 * Example:
 * number = 8 (1000 in binary) => returns 4
 * number = 10 (1010 in binary) => returns -1
 */
int findSingleSetBitPosition(int number)
{
    vector<int> binary = convertToBinary(number);
    int position = -1; // position of set bit (1-based)
    int setBitCount = 0;

    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] == 1)
        {
            position = i + 1;
            setBitCount++;
        }

        if (setBitCount > 1)
            return -1; // more than one set bit found
    }

    if (setBitCount == 0)
        return -1; // no set bits

    return position;
}

/**
 * @brief Optimized approach using bitwise operations.
 *        Returns the position of the only set bit (1-based) or -1 if zero or multiple bits set.
 *
 * @param number Input integer.
 * @return Position of set bit (1-based) or -1.
 */
int findSingleSetBitPositionOptimized(int number)
{
    // Check if number is a power of 2 (only one set bit)
    if (number <= 0 || (number & (number - 1)) != 0)
        return -1;

    int position = 1;
    while ((number & 1) == 0)
    {
        number >>= 1;
        position++;
    }
    return position;
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number must be positive." << endl;
        return 1;
    }

    int pos = findSingleSetBitPositionOptimized(n);
    cout << "The position of the single set bit is: " << pos << endl;

    return 0;
}
