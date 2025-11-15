#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an array of intervals where intervals[i] = [starti, endi],
// merge all overlapping intervals, and return an array of the non-overlapping intervals
// that cover all the intervals in the input.
// Example:
// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return intervals;

        // sort intervals by start, std lexicographical sort works
        sort(intervals.begin(), intervals.end());

        // initialize answer vector to first interval
        vector<vector<int>> ans{intervals[0]};

        for (int i = 1; i < intervals.size(); ++i)
        {
            auto &last = ans.back();
            auto &curr = intervals[i];
            // if overlap exists, merge the bigger end
            if (curr[0] <= last[1])
            {
                last[1] = max(last[1], curr[1]);
            }
            else // append if it is a disjoint interval
            {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<vector<int>>> intervalsList{{{1, 3}, {2, 6}, {8, 10}, {15, 18}},
                                              {{1, 4}, {4, 5}},
                                              {{4, 7}, {1, 4}},
                                              {{1, 7}, {2, 2}}};

    Solution s;
    for (vector<vector<int>> intervals : intervalsList)
    {
        vector<vector<int>> merged = s.merge(intervals);
        for (vector<int> interval : merged)
        {
            cout << interval[0] << " " << interval[1] << "    ";
        }
        cout << "\n\n";
    }
    return 0;
}