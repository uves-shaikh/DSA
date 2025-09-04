#include <bits/stdc++.h>
using namespace std;

int main()
{
    /**
     * Problem: Count frequency of characters in a string
     *
     * Two approaches demonstrated:
     *  1. Hashing with array → works only for lowercase English letters.
     *  2. Hashing with map   → works for all characters (flexible).
     */

    string s;
    cout << "Enter string (lowercase only, without spaces): ";
    cin >> s;

    char targetChar;
    cout << "Enter character to find number of occurrences: ";
    cin >> targetChar;

    // ✅ Approach 1: Character hashing using array
    // Array of size 26 (for 'a' to 'z')
    vector<int> hash(26, 0);

    for (char ch : s)
    {
        // map character to index (e.g., 'a' → 0, 'b' → 1, ..., 'z' → 25)
        hash[ch - 'a']++;
    }

    // ✅ Approach 2: Character hashing using ordered map
    map<char, int> freqMap;
    for (char ch : s)
    {
        freqMap[ch]++;
    }

    cout << "\nResults:\n";
    cout << "Array Hash → '" << targetChar << "' found "
         << hash[targetChar - 'a'] << " times\n";

    cout << "Map Hash   → '" << targetChar << "' found "
         << freqMap[targetChar] << " times\n";

    return 0;
}
