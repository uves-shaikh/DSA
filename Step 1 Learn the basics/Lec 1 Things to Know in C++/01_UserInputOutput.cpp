#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Example: Taking input from user and printing output

    int age;
    string name;

    cout << "Enter your name: "; // prompt user
    cin >> name;                 // input string (single word)

    cout << "Enter your age: ";
    cin >> age; // input integer

    // Output the result
    cout << "Hello " << name << ", you are " << age << " years old." << endl;

    return 0;
}
