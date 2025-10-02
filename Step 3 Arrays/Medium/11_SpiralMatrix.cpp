#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPathMatrix(vector<vector<int>> &matrix, int n, int m)
{
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    vector<int> result;

    while (left <= right && top <= bottom)
    {
        // Traverse top row
        for (int i = left; i <= right; i++)
            result.push_back(matrix[top][i]);
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++)
            result.push_back(matrix[i][right]);
        right--;

        // Traverse bottom row (if still valid)
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                result.push_back(matrix[bottom][i]);
            bottom--;
        }

        // Traverse left column (if still valid)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                result.push_back(matrix[i][left]);
            left++;
        }
    }

    return result;
}

int main()
{
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    if (n <= 0 || m <= 0)
    {
        cout << "Size must be positive." << endl;
        return 1;
    }

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter " << n * m << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    vector<int> ans = spiralPathMatrix(matrix, n, m);

    cout << "\nSpiral order traversal: ";
    for (int val : ans)
        cout << val << " ";
    cout << endl;

    return 0;
}
