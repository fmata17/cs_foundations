from typing import List
# You are given an integer array heights where
# heights[i] represents the height of the ith bar.

# You may choose any two bars to form a container.
# Return the maximum amount of water a container can store.


class Solution:
    #   height = [1,7,2,5,4,7,3,6]
    #   index  =  0 1 2 3 4 5 6 7
    #   optimal solution O(n)
    def maxArea(self, heights: List[int]) -> int:
        max_area = 0
        l, r = 0, len(heights) - 1

        while l < r:
            height = min(heights[l], heights[r])
            width = r - l
            max_area = max(max_area, (width * height))

            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1

        return max_area

s = Solution()
area = s.maxArea([1,7,2,5,4,7,3,6])
print(area)