# brute force solution
def twoSum(numbers, targeted):
    # first loop stops on second to last index
    for i in range(len(numbers) - 1):
        # second loop starts on second index and ends on last index
        for j in range(i + 1, len(numbers)):
            # check if solution has been reached, else keep iterating
            if numbers[i] + numbers[j] == targeted:
                return i, j


print(twoSum(numbers=[3, 3], targeted=6))


# single-pass hashmap solution
def twosum(nums, target):
    hashmap = {}  # num: index
    for i, num in enumerate(nums):  # enumerate() returns an index, value pair
        difference = target - num
        if difference in hashmap:
            return [hashmap[difference], i]
        else:
            hashmap[num] = i  # add to hashmap in correct format


nums = [3, 3]
target = 6

print(twosum(nums, target))
