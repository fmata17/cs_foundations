# attempting a least complex way (failed so far)
s = "hello"
t = "olleh"

s = list(s)
t = list(t)


def is_anagram(s, t):
	s, t = list(s), list(t)
	if s in t and len(s) == len(t):
		return True
	else:
		return False


# print(is_anagram(s, t))

# brute force
x = "animal"
y = "inamal"


def is_anagram_2(x, y):
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


print(is_anagram_2(x, y))


def brute_force(x, y):
	hashmap = {}
	for i, letter in enumerate(x):
		hashmap[i] = letter
	return hashmap


brute = brute_force(x, y)
#print(brute)
