// Given an integer array nums, return all the triplets
// [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0,
// and the indices i, j and k are all distinct.

// The output should not contain any duplicate triplets.
// You may return the output and the triplets in any order.

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<int> numsSet(nums.begin(), nums.end());
        vector<int> numsVec(numsSet.begin(), numsSet.end());
        vector<vector<int>> zeroSums; // result vector
        for (int i = 0; i < numsVec.size() - 2; ++i)
        {
            int iNum = numsVec[i];
            int j = i + 1;
            while (j < numsVec.size() - 1)
            {
                int jNum = numsVec[j];
                int k = j + 1;
                while (k < numsVec.size())
                {
                    if (iNum + jNum + numsVec[k] == 0)
                        zeroSums.push_back({iNum, jNum, numsVec[k]});
                    ++k;
                }
                ++j;
            }
        }
        return zeroSums;
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
