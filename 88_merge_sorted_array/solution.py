def merge(nums1: list[int], m: int, nums2: list[int], n: int):
	"""
	Do not return anything, modify nums1 in-place instead.
	"""
	# get last element index expected for nums1
	last_index = m + n - 1
	# merge in reverse
	while m > 0 and n > 0:
		if nums1[m - 1] > nums2[n - 1]:
			nums1[last_index] = nums1[m - 1]
			m -= 1
		else:
			nums1[last_index] = nums2[n - 1]
			n -= 1
		last_index -= 1

	while n > 0:
		nums1[last_index] = nums2[n - 1]
		nums2, last_index = n - 1, last_index - 1
	print(nums1)


merge([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3)
