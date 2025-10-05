#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Marks an entire column as -1 (temporary flag) except for zeros.
 * @param matrix 2D matrix passed by reference.
 * @param col Column index to mark.
 */
void markColumn(vector<vector<int>> &matrix, int col)
{
    int rows = matrix.size();
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][col] != 0)
        {
            matrix[i][col] = -1; // mark for later conversion
        }
    }
}

/**
 * @brief Marks an entire row as -1 (temporary flag) except for zeros.
 * @param matrix 2D matrix passed by reference.
 * @param row Row index to mark.
 */
void markRow(vector<vector<int>> &matrix, int row)
{
    int cols = matrix[0].size();
    for (int i = 0; i < cols; i++)
    {
        if (matrix[row][i] != 0)
        {
            matrix[row][i] = -1; // mark for later conversion
        }
    }
}

/**
 * @brief Brute Force approach to set matrix zeroes.
 *
 * Marks all elements in the same row and column as 0 wherever
 * a 0 is found. Temporarily uses -1 to avoid cascading updates.
 *
 * Time Complexity: O((N*M)*(N+M)) ≈ O(N²*M + M²*N)
 * Space Complexity: O(1)
 */
void setMatrixZeroesBrute(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Step 1: Mark affected rows and columns using -1
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, i);
                markColumn(matrix, j);
            }
        }
    }

    // Step 2: Convert all marked (-1) elements to 0
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

/**
 * @brief Better approach using additional arrays to track zeroed rows/columns.
 *
 * Uses two auxiliary arrays (one for rows, one for columns)
 * to mark which rows and columns need to be set to zero.
 *
 * Time Complexity: O(N*M)
 * Space Complexity: O(N+M)
 */
void setMatrixZeroesBetter(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> rowFlags(rows, 0); // 1 if this row should be zeroed
    vector<int> colFlags(cols, 0); // 1 if this column should be zeroed

    // Step 1: Record which rows and columns contain zeros
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowFlags[i] = 1;
                colFlags[j] = 1;
            }
        }
    }

    // Step 2: Update matrix based on recorded flags
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (rowFlags[i] || colFlags[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

/**
 * @brief Optimal approach with O(1) space using first row and column as markers.
 *
 * Uses matrix[0][j] and matrix[i][0] as flags instead of auxiliary arrays.
 * Handles the first column separately using a variable `col0`.
 *
 * Time Complexity: O(N*M)
 * Space Complexity: O(1)
 */
void setMatrixZeroesOptimal(vector<vector<int>> &matrix)
{

    // vector<int> rowsArray(rows, 0); matrix[...][0]
    // vector<int> colsArray(cols, 0); matrix[0][...]

    int rows = matrix.size();
    int cols = matrix[0].size();
    int col0 = 1; // Flag to track if first column needs to be zeroed

    // Step 1: Mark rows and columns using first row and first column
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // mark first cell of row
                if (j != 0)
                    matrix[0][j] = 0; // mark first cell of column
                else
                    col0 = 0; // special case for first column
            }
        }
    }

    // Step 2: Zero out cells based on markers
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: Handle first row separately
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // Step 4: Handle first column separately
    if (col0 == 0)
    {
        for (int i = 0; i < rows; i++)
        {
            matrix[i][0] = 0;
        }
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
        cout << "Matrix size must be positive." << endl;
        return 1;
    }

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "\nEnter " << n * m << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Uncomment one of the methods to test
    setMatrixZeroesBrute(matrix);
    // setMatrixZeroesBetter(matrix);
    // setMatrixZeroesOptimal(matrix);

    cout << "\nMatrix after setting zeroes:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
