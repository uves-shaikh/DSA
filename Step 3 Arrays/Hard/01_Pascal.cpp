#include <bits/stdc++.h>
using namespace std;

// Factorial calculation (Brute)
long long calculateFactorial(int n)
{
    long long factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial *= i;
    return factorial;
}

// nCr using factorial (Brute)
long long calculateNcRWithBrute(int n, int r)
{
    return calculateFactorial(n) / (calculateFactorial(r) * calculateFactorial(n - r));
}

// nCr using iterative (Better)
long long calculateNcRWithBetter(int n, int r)
{
    long long result = 1;
    for (int i = 0; i < r; i++)
    {
        result = result * (n - i);
        result = result / (i + 1);
    }
    return result;
}

// Return k-th row of Pascal’s Triangle using combinatorics
vector<long long> kthRow(int k)
{
    vector<long long> result;
    for (int i = 1; i <= k; i++)
    {
        long long value = calculateNcRWithBetter(k - 1, i - 1);
        result.push_back(value);
    }
    return result;
}

// Optimal method (no factorials)
vector<long long> kthRowWithOptimal(int k)
{
    vector<long long> result;
    long long val = 1;
    result.push_back(val);

    for (int i = 1; i < k; i++)
    {
        val = val * (k - i);
        val = val / i;
        result.push_back(val);
    }

    return result;
}

// Print Pascal’s Triangle up to row n
vector<vector<long long>> printPascal(int n)
{
    vector<vector<long long>> result;

    for (int i = 0; i < n; i++)
    {
        vector<long long> temp;
        long long val = 1;
        temp.push_back(val);

        for (int j = 1; j <= i; j++)
        {
            val = val * (i - j + 1);
            val = val / j;
            temp.push_back(val);
        }

        result.push_back(temp);
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter Pascal row: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number must be positive." << endl;
        return 1;
    }

    vector<long long> result = kthRowWithOptimal(n);

    cout << "Row " << n << " of Pascal’s Triangle:\n";
    for (long long val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
