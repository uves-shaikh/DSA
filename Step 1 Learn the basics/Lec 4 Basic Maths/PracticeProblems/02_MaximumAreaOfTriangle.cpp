#include <bits/stdc++.h>
using namespace std;

double calculateArea(int n, vector<vector<int>> &points)
{
    double maxArea = 0.0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                // Extract coordinates
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int x3 = points[k][0], y3 = points[k][1];

                // Shoelace formula for triangle area
                double area = fabs(x1 * (y2 - y3) +
                                   x2 * (y3 - y1) +
                                   x3 * (y1 - y2)) /
                              2.0;

                maxArea = max(maxArea, area);
            }
        }
    }

    return maxArea;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    cout << "Enter " << n << " points (x y):" << endl;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << "x for element" << i + 1 << ": ";
        cin >> x;
        cout << "y for element" << i + 1 << ": ";
        cin >> y;

        points[i] = {x, y};

        cout << endl;
    }

    cout << "You entered:" << endl;
    for (auto &p : points)
    {
        cout << "[" << p[0] << ", " << p[1] << "]" << endl;
    }

    double area = calculateArea(n, points);

    cout << "maximum area: " << area;

    return 0;
}
