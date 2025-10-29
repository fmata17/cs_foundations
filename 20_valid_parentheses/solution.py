# You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.
#
# The input string s is valid if and only if:
#
# Every open bracket is closed by the same type of close bracket.
# Open brackets are closed in the correct order.
# Every close bracket has a corresponding open bracket of the same type.
# Return true if s is a valid string, and false otherwise.
class Solution:
    def isValid(self, s: str) -> bool:
        """Brute force  -> O(n) time & space complexity"""
        # there is an odd number of symbols, therefore one would not match
        if (len(s) % 2) != 0:
            return False

        openers = {"(", "[", "{"}
        keys = {
            "(": ")",
            ")": "(",
            "[": "]",
            "]": "[",
            "{": "}",
            "}": "{",
        }
        stack = []

        for symbol in s:
            if symbol in openers:
                stack.append(symbol)
            # a closing symbols was found before an opening one
            elif len(stack) == 0:
                return False
            else:
                # a closing symbol found not matching the last opening one
                if symbol != keys[stack.pop()]:
                    return False

        # if only opening symbols where found and therefore never popped
        if len(stack) != 0:
            return False
        return True


class SolutionGPT:
    def isValid(self, s: str) -> bool:
        pairs = {")": "(", "]": "[", "}": "{"}
        stack = []

        for c in s:
            if c in pairs.values():  # opening
                stack.append(c)
            elif not stack or stack.pop() != pairs[c]:  # closing mismatch
                return False

        return not stack


s = Solution()
print(s.isValid("{{"))
