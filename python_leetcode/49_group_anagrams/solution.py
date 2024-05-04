from collections import defaultdict


def group_anagrams(strs):
    anagrams = defaultdict(list)  # mapping the character count (key) to a list of anagrams (value)
    # used a default dictionary to avoid key missing errors and create an empty list instead

    for s in strs:  # for each word in the input
        count = [0] * 26  # create a list to track each occurrence of each letter in the alphabet

        for l in s:  # for each letter in each word
            count[ord(l) - ord('a')] += 1  # add the occurrence of each letter to its defined index using ASCII

        anagrams[tuple(count)].append(s)
        # map the count of the letter occurrence (key) to the list containing all word with same letters (value)

    return anagrams.values()


strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
anagrams = group_anagrams(strs)
print(anagrams)
