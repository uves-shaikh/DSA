#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Example: Sum of digits of a number using while loop

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int sum = 0;
    while (n > 0)
    {
        sum += n % 10; // add last digit
        n /= 10;       // remove last digit
    }

    cout << "Sum of digits = " << sum << endl;

    return 0;
}
