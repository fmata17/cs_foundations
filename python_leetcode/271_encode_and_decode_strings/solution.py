"""
Design an algorithm to encode a list of strings to a single string.
The encoded string is then decoded back to the original list of strings.

Please implement encode and decode
"""
strings = ['hello', 'why', 'who are you', 'lets you do', 'at', 'the', 'dog']


def encode(strings):
    """
    Encodes a list of strings into a single string while keeping track of the
    length of the original strings for decoding.
    """
    res = ''  # string to save the list of strings all together
    for s in strings:
        res += f'{len(s)}#{s}'  # length of each string + '#' to mark the beginning of each string
    return res


def decode(string):
    """Decodes a single string back into the original list of strings."""
    res = []  # list of strings to be returned as answer
    i = 0  # pointer to read the length of the string

    while i < len(string):
        j = i  # pointer to find '#' which marks the beginning of each string

        while string[j] != '#':  # in case the length of each string is multiple digits
            j += 1
        length = int(string[i:j])

        res.append(string[j + 1: j + 1 + length])
        # append from the next character of '#' until the length of the string + 1

        i = j + 1 + length  # update pointer for each loop to keep moving forward in the strings
    return res


print(encode(strings))
print(decode(encode(strings)))
