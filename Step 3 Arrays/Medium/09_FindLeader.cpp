#include <bits/stdc++.h>
using namespace std;

/**
 * Finds all leaders in the array.
 * A leader is an element that is greater than all elements to its right.
 *
 * @param elements Reference to the input array
 * @param n Size of the input array
 * @return Vector containing all leaders in the same order as they appear
 *
 * Time Complexity: O(n)  (single traversal from right to left)
 * Space Complexity: O(n) (for storing leaders)
 */
vector<int> findLeaders(vector<int> &elements, int n)
{
    int currentMax = INT_MIN; // Tracks the maximum element seen so far from the right
    vector<int> leaders;      // Stores all leaders found

    // Traverse the array from right to left
    for (int j = n - 1; j >= 0; j--)
    {
        if (elements[j] > currentMax)
        {
            leaders.push_back(elements[j]); // Current element is a leader
        }
        currentMax = max(currentMax, elements[j]); // Update running maximum
    }

    // Leaders were collected in reverse order -> restore original order
    reverse(leaders.begin(), leaders.end());

    return leaders;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Size must be positive." << endl;
        return 1;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    vector<int> leaders = findLeaders(arr, n);

    cout << "Leaders in the array: ";
    for (int val : leaders)
        cout << val << " ";
    cout << endl;

    return 0;
}
