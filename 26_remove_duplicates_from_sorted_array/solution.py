def solution(nums) -> int:
    index = 0
    while index < (len(nums) - 2):
        if nums[index] == nums[index + 1]:
            del nums[index]
            index -= 1
        index += 1

    if len(nums) > 1 and nums[-1] == nums[-2]:
        del nums[-1]
    return len(nums)


nums = [1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 6]
print(solution(nums))
print(nums)
