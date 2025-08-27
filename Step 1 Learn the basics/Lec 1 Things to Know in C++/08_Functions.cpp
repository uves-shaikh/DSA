#include <bits/stdc++.h>
using namespace std;

// Function by value (a copy is passed)
void incrementByValue(int x)
{
    x++;
}

// Function by reference (actual variable is passed)
void incrementByReference(int &x)
{
    x++;
}

int main()
{
    int a = 5, b = 5;

    incrementByValue(a);     // won't change 'a'
    incrementByReference(b); // will change 'b'

    cout << "After incrementByValue, a = " << a << endl;
    cout << "After incrementByReference, b = " << b << endl;

    return 0;
}
