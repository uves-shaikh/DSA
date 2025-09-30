#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the maximum profit possible with only one buy and one sell.
 *
 * @param prices Reference to vector containing stock prices on each day.
 * @return Maximum profit (0 if no profit is possible).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int findMaxProfitSingleTransaction(vector<int> &prices)
{
    int maxProfit = 0;      // Tracks maximum profit
    int minPrice = INT_MAX; // Tracks lowest price seen so far

    for (int i = 0; i < prices.size(); i++)
    {
        // Update the lowest price so far
        minPrice = min(minPrice, prices[i]);

        // Calculate profit if we sell today, update maxProfit
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}

/**
 * @brief Finds the maximum profit possible with multiple transactions.
 *        You can buy and sell multiple times, but must sell before buying again.
 *
 * @param prices Reference to vector containing stock prices on each day.
 * @return Maximum profit achievable.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int findMaxProfitMultipleTransactions(vector<int> &prices)
{
    long maxProfit = 0; // Long to avoid overflow on large inputs

    for (int i = 1; i < prices.size(); i++)
    {
        // If today's price is greater than yesterday's, we take the profit
        if (prices[i] > prices[i - 1])
        {
            maxProfit += prices[i] - prices[i - 1];
        }
    }

    return static_cast<int>(maxProfit);
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

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter price on day " << i + 1 << ": ";
        cin >> prices[i];
    }

    // Example: Single transaction version
    int singleProfit = findMaxProfitSingleTransaction(prices);
    cout << "Maximum profit with one transaction: " << singleProfit << endl;

    // Example: Multiple transactions version
    int multipleProfit = findMaxProfitMultipleTransactions(prices);
    cout << "Maximum profit with multiple transactions: " << multipleProfit << endl;

    return 0;
}
