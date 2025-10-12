#include <vector>
#include <iostream>
using namespace std;
/*
Given an array of integers numbers that is sorted in non-decreasing order.

Return the indices (1-indexed) of two numbers, [index1, index2],
such that they add up to a given target number target and index1 < index2.
Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.

There will always be exactly one valid solution.

Your solution must use O(1) additional space.
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        for (int i = 0; i < numbers.size() - 1; ++i)
        {
            int j = i + 1;
            while (j < numbers.size())
            {
                if (numbers[i] + numbers[j] == target)
                    return {i + 1, j + 1};
                ++j;
            }
        }
        return {-1};
    }
};

int main()
{
    vector<int> v = {1, 3, 5, 6};
    Solution s;
    vector<int> res = s.twoSum(v, 6);
    for (int i : res)
    {
        cout << i;
    }
    cout << endl;
    return 0;
}
