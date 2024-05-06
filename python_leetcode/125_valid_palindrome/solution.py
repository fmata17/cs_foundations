def valid_palindrome(s):
	f = ""
	for letter in s.lower():  # can this be done without an extra variable?
		if letter.isalnum():
			f += letter

	for i in range(len(f) - 1):
		for j in range(len(f) - 1, -1):  # is not starting the pointer at last position
			if f[i] != f[j]:
				return False
			return True


s = "A man, a plan, a canal: Panama"
print(valid_palindrome(s))
