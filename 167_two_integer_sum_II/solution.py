class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        for i in range(len(numbers) - 1):
            j = i + 1
            while j < len(numbers):
                if numbers[i] + numbers[j] == target:
                    return [i + 1, j + 1] # problem asks to return 1-indexed indexes
                j += 1
        return [-1]


s = Solution()
print(s.twoSum([1, 3, 5, 6], 6))
