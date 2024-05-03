# using a standard python library
from collections import Counter

s = "anagram"
t = "nagaram"


def is_anagram(s, t):
    return Counter(s) == Counter(t)


anagram = is_anagram(s, t)
print(anagram)


# using a hashmap
def is_anagram_2(s, t):
    if len(s) != len(t):
        return False

    hash_s, hash_t = {}, {}

    for i in range(len(s)):
        hash_s[s[i]] = 1 + hash_s.get(s[i], 0)
        hash_t[t[i]] = 1 + hash_t.get(t[i], 0)

    for c in hash_s:
        if hash_s[c] != hash_t.get(c, 0):
            return False

    return True


anagram_2 = is_anagram_2(s, t)
print(anagram_2)


# using a sorting algorithm
def is_anagram_3(s, t):
    return sorted(s) == sorted(t)


anagram_3 = is_anagram_3(s, t)
print(anagram_3)
