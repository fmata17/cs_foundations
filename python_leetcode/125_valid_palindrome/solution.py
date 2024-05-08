# first attempt (successful but not optimized)
def valid_palindrome(s):
    f = ""
    for letter in s.lower():  # can this be done without an extra variable?
        if letter.isalnum():
            f += letter
    return f == f[::-1]  # palindromes read the same front and back


s = "A man, a plan, a canal: Panama"
print(valid_palindrome(s))


# Cleaner solution
def valid_palindrome2(s):
    s = [l for l in s.lower() if l.isalnum()]
    return s == s[::-1]


s = "A man, a plan, a canal: Panama"
print(valid_palindrome2(s))


# pointer solution using my own alphanumeric function
def is_alphanumeric(c):
    """Return True if c is a valid alphanumeric character, otherwise False."""
    return (ord("A") <= ord(c) <= ord("Z") or
            ord("a") <= ord(c) <= ord("z") or
            ord("0") <= ord(c) <= ord("9"))


def valid_palindrome3(s):
    l, r = 0, len(s) - 1  # two pointers to keep track of

    while l < r:
        # comparison needed because the variables can change inside the main loop
        while l < r and not is_alphanumeric(s[l]):
            l += 1
        # comparison needed because the variables can change inside the main loop
        while l < r and not is_alphanumeric(s[r]):
            r -= 1
        if s[l].lower() != s[r].lower():
            return False
        l, r = l + 1, r - 1
    return True


s = "A man, a plan, a canal: Panama"
print(valid_palindrome3(s))
