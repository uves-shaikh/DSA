#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(const vector<int> &arr, int n)
{
    if (n < 2)
        return INT_MIN; // No second largest exists

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] < largest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int secondLargestElement = findSecondLargest(arr, n);

    if (secondLargestElement == INT_MIN)
        cout << "No second largest element exists (all elements equal or array too small)." << endl;
    else
        cout << "Second Largest Element in array is: " << secondLargestElement << endl;

    return 0;
}
