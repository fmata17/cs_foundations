# Given two strings s and t, return true if s is a subsequence of t,
# or false otherwise.
# A subsequence of a string is a new string that is formed from the original string by
# deleting some (can be none) of the characters without disturbing the relative positions of
# the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

# Example 1:

# Input: s = "abc", t = "ahbgdc"
# Output: true

# Example 2:

# Input: s = "axc", t = "ahbgdc"
# Output: false

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        subptr = 0
        tptr = 0
        while tptr < len(t) and subptr < len(s):
            if s[subptr] == t[tptr]:
                subptr += 1
                tptr += 1
            else:
                tptr += 1
        return subptr == len(s)

s = Solution()
print(s.isSubsequence("AbC", "AbGDC"))