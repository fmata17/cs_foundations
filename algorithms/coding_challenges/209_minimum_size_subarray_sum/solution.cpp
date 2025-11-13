// Given an array of positive integers nums and a positive integer target,
// return the minimal length of a subarray whose sum is greater than or equal to target.
// If there is no such subarray, return 0 instead.

// Example:
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// NOTE: subarray means that the relative placement has to be the same in the children as in the parent.
#include <vector>
#include <print>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;
        int currSum = 0;
        int minLen = nums.size() + 1;

        for (int right = 0; right < nums.size(); ++right)
        {
            currSum = currSum + nums[right];
            while (currSum >= target)
            {
                minLen = std::min(minLen, right - left + 1);
                currSum = currSum - nums[left];
                ++left;
            }
        }
        return minLen == nums.size() + 1 ? 0 : minLen;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> nums{2,3,1,2,4,3};
    int res = s.minSubArrayLen(7, nums);
    std::println("{}", res);
    return 0;
}
