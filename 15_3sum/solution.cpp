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
        vector<vector<int>> zeroSums;
        set<int> used; // TODO fix incorrect way to check for duplicates since its not element-wise but triplet-wise
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int i_element = nums[i];
            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                int j_element = nums[j];
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    int k_element = nums[k];

                    if (i_element + j_element + k_element == 0)
                    {
                        if (used.count(i_element) == 0 ||
                            used.count(j_element) == 0 ||
                            used.count(k_element) == 0)
                        {
                            zeroSums.push_back({i_element, j_element, k_element});
                            used.insert(i_element);
                            used.insert(j_element);
                            used.insert(k_element);
                        }
                    }
                }
            }
        }
        return zeroSums;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums({-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4});
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
