// Given an integer array nums, return all the triplets
// [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0,
// and the indices i, j and k are all distinct.

// The output should not contain any duplicate triplets.
// You may return the output and the triplets in any order.

// Input: nums      = [-1,0,1,2,-1,-4]
// sorted input     = [-4,-1,-1,0,1,2]
// Output:           [[-1,-1,2],[-1,0,1]]

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    // optimal solution:
    // sort and use two pointers and a for loop (twoSum2 in a for loop)
    {
        vector<vector<int>> res; // < i, j, k >

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) // avoid having the same i
                continue;
            int leftptr = i + 1;
            int rightptr = nums.size() - 1;
            while (leftptr < rightptr)
            {
                // evaluate sum and move pointer respectively to approach a sum of 0
                int threeSum = nums[i] + nums[leftptr] + nums[rightptr];
                if (threeSum < 0)
                {
                    ++leftptr;
                }
                else if (threeSum > 0)
                {
                    --rightptr;
                }
                else
                {
                    res.push_back({nums[i], nums[leftptr], nums[rightptr]});
                    // moving one pointer is enough; this changes the triplet,
                    // and the loop logic will adjust the right side as needed
                    ++leftptr;
                    // keep incrementing to avoid having the same j and avoid duplicating triplets
                    while (nums[leftptr] == nums[leftptr - 1] && leftptr < rightptr)
                    {
                        ++leftptr;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums({-1, 0, 1, 2, -1, -4});
    Solution s;
    for (vector<int> vector : s.threeSum(nums))
    {
        for (int num : vector)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
