#include <bits/stdc++.h>
using namespace std;

// Rotate matrix 90 degrees anti-clockwise (works for any n × m)
vector<vector<int>> rotateMatrixAntiClock90(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // After rotation: cols x rows
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

// Rotate matrix 90 degrees clockwise (in-place, only for n × n)
void rotateMatrixClock90InPlace(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
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

    cout << "\nChoose rotation:\n";
    cout << "1. Rotate 90° Anti-Clockwise (works for any matrix)\n";
    cout << "2. Rotate 90° Clockwise (only for square matrices)\n";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
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
    }
    else if (choice == 2)
    {
        if (n != m)
        {
            cout << "Clockwise rotation only works for square matrices (n == m)." << endl;
        }
        else
        {
            rotateMatrixClock90InPlace(matrix);

            cout << "\nRotated Matrix (90° Clockwise):\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
