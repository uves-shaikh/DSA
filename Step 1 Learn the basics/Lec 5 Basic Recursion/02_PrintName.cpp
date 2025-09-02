#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively prints a given name a specified number of times.
 *
 * @param counter Current repetition count.
 * @param limit   Total number of times the name should be printed.
 * @param name    The name string to be printed.
 *
 * This function uses recursion to repeatedly print the provided name.
 * It terminates when the counter exceeds the limit.
 *
 * Example: printName(1, 3, "Alex") will print "Alex" three times.
 */
void printName(int counter, int limit, const string &name)
{
    // Base case: stop recursion if counter exceeds the limit
    if (counter > limit)
        return;

    // Print the name
    cout << name << endl;

    // Recursive call: increment counter
    printName(counter + 1, limit, name);
}

int main()
{
    int repetitions; // Number of times to print the name
    string userName; // User-provided name

    cout << "Hey, what's your name? ";
    cin >> userName;

    cout << "Greetings!! " << userName << endl;
    cout << "How many times do you want your name printed? ";
    cin >> repetitions;

    // Input validation: ensure repetitions is non-negative
    if (repetitions < 0)
    {
        cout << "Please enter a non-negative number." << endl;
        return 1; // Exit with error code
    }

    int startCounter = 1; // Start counting from 1

    // Call recursive function
    printName(startCounter, repetitions, userName);

    return 0;
}
