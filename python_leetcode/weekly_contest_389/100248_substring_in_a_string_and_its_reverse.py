def is_substring_present(s: str) -> bool:
    current_index = 0
    reversed_s = s[::-1]
    for i in range(len(s)):
        if s[current_index] + s[current_index+1] == reversed_s[current_index] + reversed_s[current_index+1]:
            current_index += 1
            return True
        else:
            current_index += 1
            return False


is_substring_present('leetcode')
