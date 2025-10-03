# brute force
x = "anagram"
y = "nagaram"


def is_anagram(x, y):
	x = list(x)
	y = list(y)
	while x:
		for letter in x:
			if letter in y:
				y.remove(letter)
				x.remove(letter)
			else:
				return False
	if not x and not y:
		return True


anagram = (is_anagram(x, y))
print(anagram)
