def insertion_sort(a):
	"""
	Sorts an array using the insertion sort algorithm.

	Args:
		a (list): The input list to be sorted in-place.

	Returns:
		a (list): The sorted version of the list.
	"""
	for i in range(1, len(a)):  # iterate through possible unsorted part of the list
		value_to_sort = a[i]  # keep track of the current value to sort
		j = i - 1  # pointer to check if elements to the left are sorted or not

		while j >= 0 and a[j] > value_to_sort:
			a[j + 1] = a[j]  # move all unsorted elements one space to the right
			j -= 1  # move pointer to stay consistent throughout the loop

		# insert target value at appropriate place after sliding unsorted elements to the right
		a[j + 1] = value_to_sort
	return a


a = [49, 20, 23, 34, 6, 29, 35, 32, 16, 9, 28, 19, 31, 21, 3, 11, 48, 2, 8, 51]

print(insertion_sort(a))
