# Maximum Nesting Depth of the Parentheses (Leetcode)
# Leetcode Link : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

# Time Complexity : O(n)
# Space Complexity : O(1)

class Solution:
    def maxDepth(self, s: str) -> int:
        validParentheses = 0
        counter = 0

        for ch in s:
            if ch == '(':
                counter += 1
            elif ch == ')' and counter != 0:
                counter -= 1
            
            if counter > validParentheses:
                validParentheses = counter
        
        return validParentheses