# Given an integer array nums, return an array answer such that answer[i]
# is equal to theproduct of all the elements of nums except nums[i].

# The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
# You must write an algorithm that runs in O(n) time and without using the division operation.

# Example:
# Input: nums = [1,2,3,4]
# Output: [24,12,8,6]

# Follow up: Can you solve the problem in O(1) extra space complexity?
# (The output array does not count as extra space for space complexity analysis.)

from typing import List
from math import prod


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        products = []  # solution to list

        for i in range(len(nums)):
            numsTemp = nums[:i] + nums[i + 1:]
            products.append(prod(numsTemp))

        return products

    def productExceptSelfOptimal(self, nums: List[int]) -> List[int]:
        products = [1] * len(nums)
        prefix = 1
        postfix = 1
        for i in range(len(nums)):
            products[i] = prefix
            prefix *= nums[i]
        
        for i in range(len(nums) -1, -1, -1):
            products[i] *= postfix
            postfix *= nums[i]

        return products


s = Solution()
print(s.productExceptSelf([1, 3, 5, 7, 0]))
print(s.productExceptSelfOptimal([1, 3, 5, 7, 0]))
