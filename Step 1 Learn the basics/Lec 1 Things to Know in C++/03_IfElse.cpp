#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Example: Check whether a number is positive, negative or zero

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n > 0)
    {
        cout << n << " is positive." << endl;
    }
    else if (n < 0)
    {
        cout << n << " is negative." << endl;
    }
    else
    {
        cout << "Number is zero." << endl;
    }

    return 0;
}
