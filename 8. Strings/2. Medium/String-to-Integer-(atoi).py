# String to Integer (atoi) (Leetcode)
# Leetcode Link : https://leetcode.com/problems/string-to-integer-atoi/description/

# Time Complexity : O(n)
# Space Complexity: O(1)

class Solution:
    def myAtoi(self, s: str) -> int:
        max_int = 2 ** 31 - 1
        min_int = -2 ** 31
        i, num, sign = 0, 0, 1

        s = s.strip() #remove whitespaces
        
        #if s is empty then return 0
        if not s:
            return 0
        
        if s[i] == '+' or s[i] == '-':
            if s[i] == '-':
                sign = -1
            else:
                sign = 1
            i += 1
        
        while(i < len(s) and s[i].isdigit()):
            num = num * 10 + int(s[i])
            i += 1
        
        num = sign * num
        if num > max_int:
            num = max_int
        elif num < min_int:
            num = min_int
        
        return num