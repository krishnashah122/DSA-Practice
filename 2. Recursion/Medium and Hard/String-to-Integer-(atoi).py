# String to Integer (atoi) (Leetcode)
# Leetcode Link : https://leetcode.com/problems/string-to-integer-atoi/description/

# Time Complexity : O(n)
# Space Complexity : [Approach 1 - O(1)] or [Approach 2 - O(n)]

class Solution:
    def atoi(self, s, sign, i, result):
        max_int = 2 ** 31 - 1
        min_int = -2 ** 31

        if sign*result >= max_int:
            return max_int
        
        if sign*result <= min_int:
            return min_int
        
        if i >= len(s) or not s[i].isdigit():
            return sign*result
        
        result = self.atoi(s, sign, i+1, result * 10 + int(s[i]))
        return result

    def myAtoi(self, s: str) -> int:
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
        
        # Approach 1 : Iterative Method
        # while(i < len(s) and s[i].isdigit()):
        #     num = num * 10 + int(s[i])
        #     i += 1
        
        # num = sign * num
        # if num > max_int:
        #     num = max_int
        # elif num < min_int:
        #     num = min_int
        

        # Approach 2 : Recursive Method
        return self.atoi(s, sign, i, 0)