#include <bits/stdc++.h>
using namespace std;

int findSecondLargestOptimal(int n, vector<int> a)
{
    int largest = a[0];
    int secondLargest = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > secondLargest)
        {
            secondLargest = a[i];
        }
    }

    return secondLargest;
}

int findSecondSmallestOptimal(int n, vector<int> a)
{
    int smallest = a[0];
    int secondSmallest = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] > smallest && a[i] < secondSmallest)
        {
            secondSmallest = a[i];
        }
    }

    return secondSmallest;
}

int findSecondLargest(int n, vector<int> a)
{
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > secondLargest && a[i] != largest)
        {
            secondLargest = a[i];
        }
    }

    return secondLargest;
}

int findSecondSmallest(int n, vector<int> a)
{
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < smallest)
        {
            smallest = a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] < secondSmallest && a[i] != smallest)
        {
            secondSmallest = a[i];
        }
    }

    return secondSmallest;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }

    int secondLargest = findSecondLargest(n, arr);
    int secondSmallest = findSecondSmallest(n, arr);

    int secondLargestOptimal = findSecondLargestOptimal(n, arr);
    int secondSmallestOptimal = findSecondSmallestOptimal(n, arr);

    cout << "Second Largest and Smallest Elements in array with better approach are: "
         << secondLargest << " and " << secondSmallest << endl;
    cout << "Second Largest and Smallest Elements in array with optimal approach are: "
         << secondLargestOptimal << " and " << secondSmallestOptimal;

    return 0;
}
