def twosum(nums, target):
    hashmap = {}  # number:index
    for i, n in enumerate(nums):
        if target - n in hashmap.values():
            return [hashmap[]]
