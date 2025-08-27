#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Example 1: Arrays
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Array elements: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Example 2: Strings
    string s;
    cout << "Enter a word: ";
    cin >> s; // takes input until space

    cout << "You entered: " << s << endl;

    return 0;
}
