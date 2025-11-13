// Given an integer array nums, return an array answer such that answer[i]
// is equal to theproduct of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Follow up: Can you solve the problem in O(1) extra space complexity?
// (The output array does not count as extra space for space complexity analysis.)

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> products(nums.size(), 1); // solution vector
        int prefix = 1;
        int postfix = 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            products[i] = prefix;
            prefix = prefix * nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            products[i] = products[i] * postfix;
            postfix = postfix * nums[i];
        }

        return products;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec = {1, 3, 5, 10};
    vec = s.productExceptSelf(vec);
    for (int n : vec)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
