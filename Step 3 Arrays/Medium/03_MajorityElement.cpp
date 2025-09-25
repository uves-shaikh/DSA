#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds all elements in the array that appear at least ⌊n/k⌋ times.
 *
 * @param arr Reference to the input array of integers.
 * @param n Size of the input array.
 * @param k Divisor for frequency threshold.
 * @return A vector containing elements that meet the frequency condition.
 *
 * Time Complexity: O(n^2) due to nested loops.
 * Space Complexity: O(n) for result storage.
 */
vector<int> findFrequentElements(vector<int> &arr, int n, int k)
{
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        // Count frequency of arr[i] by scanning the whole array
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        // If frequency meets threshold, add to result
        if (count >= n / k)
            result.emplace_back(arr[i]);
    }

    return result;
}

/**
 * @brief Brute-force method to find the majority element (appearing > n/2 times).
 *
 * @param nums Reference to the input array of integers.
 * @return Majority element if it exists, otherwise -1.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
int findMajorityElementBrute(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        // Count occurrences of nums[i]
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == nums[i])
            {
                count++;
            }
        }
        // If element appears more than n/2 times, return it
        if (count > nums.size() / 2)
            return nums[i];
    }

    return -1; // No majority element found
}

/**
 * @brief Improved approach using a hashmap to count frequencies.
 *
 * @param nums Reference to the input array of integers.
 * @return Majority element if it exists, otherwise -1.
 *
 * Time Complexity: O(n log n) due to map operations.
 * Space Complexity: O(n) for frequency map.
 */
int findMajorityElementUsingMap(vector<int> &nums)
{
    map<int, int> frequencyMap;

    // Count frequency of each element
    for (int i = 0; i < nums.size(); i++)
    {
        frequencyMap[nums[i]]++;
    }

    // Check for majority condition
    for (auto element : frequencyMap)
    {
        if (element.second > nums.size() / 2)
        {
            return element.first;
        }
    }

    return -1;
}

/**
 * @brief Optimal approach using Boyer-Moore Voting Algorithm.
 *
 * @param nums Reference to the input array of integers.
 * @return Majority element if it exists, otherwise -1.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int findMajorityElementOptimal(vector<int> &nums)
{
    int n = nums.size();
    int candidate = INT_MIN; // Potential majority element
    int count = 0;           // Counter for candidate

    // Phase 1: Find candidate element
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
            count = 1;
        }
        else if (candidate == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    // Phase 2: Verify if candidate is indeed the majority
    int freqCounter = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == candidate)
        {
            freqCounter++;
        }
    }

    if (freqCounter > n / 2)
        return candidate;

    return -1; // No majority element found
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

    // Using optimal solution
    int majorityElement = findMajorityElementOptimal(arr);

    cout << "The majority element is: " << majorityElement << endl;

    return 0;
}
