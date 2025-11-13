# Given an array of positive integers nums and a positive integer target,
# return the minimal length of a subarray whose sum is greater than or equal to target.
# If there is no such subarray, return 0 instead.

# Example:
# Input: target = 7, nums = [2,3,1,2,4,3]
# Output: 2
# Explanation: The subarray [4,3] has the minimal length under the problem constraint.
# NOTE: subarray means that the relative placement has to be the same in the children as in the parent.
from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left_ptr = 0
        curr_sum = 0
        min_len = float("inf")

        for right_ptr in range(len(nums)):
            curr_sum += nums[right_ptr]
            # close window from left when current sum is greater or equal to target
            while curr_sum >= target:
                min_len = min(min_len, right_ptr - left_ptr + 1)
                curr_sum -= nums[left_ptr]
                left_ptr += 1
        return 0 if min_len == float("inf") else int(min_len)

s = Solution()
print(s.minSubArrayLen(7, [2,3,1,2,4,3]))