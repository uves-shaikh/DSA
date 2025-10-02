#include <bits/stdc++.h>
using namespace std;

// Rotate matrix 90 degrees anti-clockwise
vector<vector<int>> rotateMatrixAntiClock90(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // After rotation: cols x rows matrix
    vector<vector<int>> result(cols, vector<int>(rows));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[cols - 1 - j][i] = matrix[i][j];
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

    vector<vector<int>> ans = rotateMatrixAntiClock90(matrix);

    cout << "\nRotated Matrix (90° Anti-Clockwise):\n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
