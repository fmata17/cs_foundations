def solution(nums, k):
	count = {}  # hashmap to keep track of each number's occurrence; number: occurrence

	freq = [[] for _ in range(len(nums) + 1)]
	# nested lists; the sub-list's index represents the occurrences and
	# the value it holds represents the numbers with such occurrences
	# variable ready for worse case scenario: all numbers are different

	ans = []  # list array to return the final answer

	"""
	use different loops for different purposes, 
	avoid saturating loops just like with functions
	"""

	for n in nums:
		# smart way to assign occurrences by using a default value of 0 if the key doesn't exist
		count[n] = count.get(n, 0) + 1

	for n, c in count.items():
		# append the number to its assigned sublist determined by
		# the index which refers to the number of its occurrences
		freq[c].append(n)

	# start from the last sublist which contains the numbers with most occurrences
	# move down to index 0 using a negative step
	for i in range(len(freq) - 1, 0, -1):
		# get the values in each sublist
		for n in freq[i]:
			# append the answer array
			ans.append(n)
			# finish loop and return answer when its length becomes K
			if len(ans) == k:
				return ans


nums = [1, 2, 2, 3, 3, 3]
print(solution(nums, 2))
