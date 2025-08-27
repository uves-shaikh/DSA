#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Example: Calculate sum of first N numbers (O(N))

    int n;
    cout << "Enter N: ";
    cin >> n;

    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i; // takes O(N) time
    }
    cout << "Sum (loop) = " << sum << endl;

    // Optimized way using formula (O(1))
    long long formulaSum = 1LL * n * (n + 1) / 2;
    cout << "Sum (formula) = " << formulaSum << endl;

    return 0;
}
