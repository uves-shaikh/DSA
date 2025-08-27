#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Example: Simple calculator using switch statement

    int a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> b;

    switch (op)
    {
    case '+':
        cout << "Result = " << a + b << endl;
        break;
    case '-':
        cout << "Result = " << a - b << endl;
        break;
    case '*':
        cout << "Result = " << a * b << endl;
        break;
    case '/':
        if (b != 0)
            cout << "Result = " << (double)a / b << endl;
        else
            cout << "Division by zero not allowed!" << endl;
        break;
    default:
        cout << "Invalid operator!" << endl;
    }

    return 0;
}
