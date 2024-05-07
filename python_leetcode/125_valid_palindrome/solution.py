def valid_palindrome(s):
	f = ""
	for letter in s.lower():  # can this be done without an extra variable?
		if letter.isalnum():
			f += letter

	if f == f[::-1]:  # use logic to solve problem
		return True  # palindromes read the same front and back
	else:
		return False


s = "A man, a plan, a canal: Panama"
print(valid_palindrome(s))
