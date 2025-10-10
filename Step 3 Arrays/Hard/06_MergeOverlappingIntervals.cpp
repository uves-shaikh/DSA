#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Merges overlapping intervals using the Brute Force approach.
 *
 * The method first sorts all intervals based on their starting times,
 * then iterates through each interval and merges overlapping ones
 * by checking pairwise overlaps.
 *
 * Steps:
 * 1. Sort all intervals by starting point.
 * 2. For each interval `i`, set its start and end.
 * 3. Compare it with all following intervals `j > i`:
 *    - If `intervals[j][0] <= end`, update `end` to max(end, intervals[j][1]).
 *    - Else, break (since sorted order ensures no further overlap).
 * 4. Push the merged interval into the result.
 *
 * @param intervals A vector of intervals represented as [start, end].
 * @return A vector of merged non-overlapping intervals.
 *
 * Time Complexity: O(n²) — Nested loops to check overlaps.
 * Space Complexity: O(n) — For storing the merged intervals.
 */
vector<vector<int>> mergeIntervalsBrute(vector<vector<int>> intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Skip if current interval is already covered by previous merged one
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }

        // Merge overlapping intervals
        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(intervals[j][1], end);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }

    return ans;
}

/**
 * @brief Merges overlapping intervals using the Optimal approach.
 *
 * This approach leverages sorting + a single linear pass.
 * - After sorting intervals by start time,
 *   compare each interval with the last merged interval.
 * - If overlapping (`current.start <= last.end`), merge them.
 * - Otherwise, add the new interval to the result.
 *
 * @param intervals A vector of intervals represented as [start, end].
 * @return A vector of merged non-overlapping intervals.
 *
 * Time Complexity: O(n log n) — Due to sorting.
 * Space Complexity: O(n) — For storing merged intervals.
 */
vector<vector<int>> mergeIntervalsOptimal(vector<vector<int>> intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        // If no intervals merged yet or no overlap, add current interval
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            // Merge with previous overlapping interval
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of intervals must be positive." << endl;
        return 1;
    }

    vector<vector<int>> arr(n);
    cout << "Enter " << n << " intervals (start end):" << endl;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << "Start of interval " << i + 1 << ": ";
        cin >> x;
        cout << "End of interval " << i + 1 << ": ";
        cin >> y;
        arr[i] = {x, y};
        cout << endl;
    }

    // Choose which approach to use:
    // vector<vector<int>> result = mergeIntervalsBrute(arr);
    vector<vector<int>> result = mergeIntervalsOptimal(arr);

    cout << "\nMerged intervals:\n";
    if (result.empty())
    {
        cout << "No intervals found.\n";
    }
    else
    {
        for (auto &interval : result)
        {
            cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
        }
    }

    return 0;
}
