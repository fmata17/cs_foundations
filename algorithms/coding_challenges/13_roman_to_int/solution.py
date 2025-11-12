# Given a roman numeral, convert it to an integer.

# Example:
# Input: s = "MCMXCIV"
# Output: 1994
# Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

class Solution:
    def romanToInt(self, s: str) -> int:
        romans = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        reversed_s = s[::-1]
        res = romans[reversed_s[0]]
        for i in range(1, len(s)):
            if romans[reversed_s[i]] >= romans[reversed_s[i - 1]]:
                res += romans[reversed_s[i]]
            else:
                res -= romans[reversed_s[i]]
        return res
    
s = Solution()
print(s.romanToInt("MCMXCIV"))