#include <bits/stdc++.h>
using namespace std;

void bubbleRecursiveSort(vector<int> &arr, int n)
{
    // Base case: when only one element is left
    if (n == 1)
        return;

    // Perform one pass of bubble sort (largest element goes to end)
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call for the remaining array
    bubbleRecursiveSort(arr, n - 1);
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

    cout << "Array before sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    bubbleRecursiveSort(arr, n);

    cout << "Array after sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
