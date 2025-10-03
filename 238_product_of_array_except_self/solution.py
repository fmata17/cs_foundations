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
