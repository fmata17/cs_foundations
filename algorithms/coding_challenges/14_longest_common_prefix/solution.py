from typing import List

# Write a function to find the longest common prefix string amongst an array of strings.
# If there is no common prefix, return an empty string "".


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ""

        # loop over each character index *of the first word*.
        # the prefix can't be longer than strs[0], so this bounds the search.
        for i in range(len(strs[0])):

            # check the character at position i for *every* string
            for s in strs:

                # if this string is too short OR the character doesn't match
                # the i-th character of the first word, the prefix ends here
                if i == len(s) or s[i] != strs[0][i]:
                    return res

            # if all strings matched at this position, append this character
            res += strs[0][i]

        # if the loop finishes, the entire first word is a prefix
        return res


strs = ["flower", "flowers", "flowerly"]
s = Solution()
print(s.longestCommonPrefix(strs))
