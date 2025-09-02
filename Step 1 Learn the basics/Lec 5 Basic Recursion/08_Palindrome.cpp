#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively checks if a string is a palindrome.
 *
 * @param s     The input string.
 * @param left  Current left index.
 * @param right Current right index.
 *
 * Base case:
 * - If left >= right → the string is a palindrome (all pairs matched).
 *
 * Recursive case:
 * - If characters at left and right match → move inward.
 * - Otherwise → the string is not a palindrome.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursion stack)
 */
bool isPalindromeRecursive(const string &s, int left, int right)
{
    // Base case: crossed or met in the middle
    if (left >= right)
        return true;

    // If mismatch found → not palindrome
    if (s[left] != s[right])
        return false;

    // Move inward
    return isPalindromeRecursive(s, left + 1, right - 1);
}

int main()
{
    string s;

    cout << "Enter your string: ";
    cin >> s; // Reads a single word (no spaces). Use getline for full sentences.

    // Call recursive palindrome checker
    if (isPalindromeRecursive(s, 0, s.length() - 1))
        cout << s << " is a palindrome" << endl;
    else
        cout << s << " is not a palindrome" << endl;

    return 0;
}
