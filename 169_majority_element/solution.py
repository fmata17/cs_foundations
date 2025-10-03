def majority_element(nums):
    result, occurrences = 0, 0  # used to compare the occurrences of the elements in the for loop
    for num in nums:
        if occurrences == 0:
            result = num
        occurrences += (1 if num == result else -1)
    return result


nums = [2, 2, 1, 1, 1, 2, 2]
print(majority_element(nums))
