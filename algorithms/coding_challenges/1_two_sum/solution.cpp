#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
/*
Given an array of integers nums and an integer target,
return the indices i and j such that nums[i] + nums[j] == target and i != j.

You may assume exactly one valid pair exists.
Return the answer with the smaller index first.

************************************************
Optimized Solution — O(n) time, O(n) space:
-------------------------------------------
Use a hash map to track seen numbers:
- For each number, compute complement = target - num.
- If the complement exists in the map, we’ve found the pair → return its index + current index.
- Otherwise, insert {num: index} into the map for future lookups.
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> store; // maps value: index
        int complement = 0; // tracks complement of each num to reach target
        for (int i = 0; i < nums.size(); ++i)
        {
            complement = target - nums[i];
            if (store.count(complement))
                return {store[complement], i};
            store[nums[i]] = i;
        }
        return {-1};
    }
};

int main()
{
    vector<int> vec{3, 4, 5, 6};
    Solution s;
    vector<int> res = s.twoSum(vec, 7);

    for (int i: res)
        cout << i << ' ';
    cout << endl;
    return 0;
}
