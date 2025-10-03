from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        store = set(nums)
        for n in nums:
            if (n - 1) not in store:  # n is the beginning of a sequence
                streak = 0
                while (n + streak) in store:
                    streak += 1
                res = max(res, streak)

        return res


s = Solution()
print(s.longestConsecutive([100, 3, 4, -5, 5, 99, 99, 99, -4, -3, -2, -1]))
