# Remove Outermost Parentheses (Leetcode)
# Leetcode Link : https://leetcode.com/problems/remove-outermost-parentheses/description/

# Time Complexity : O(N)
# Space Complexity : O(N)

class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        open = 0
        ans = ''
        for i in s:
            if (i == '('):
                if (open > 0):
                    ans += i
                open += 1
            else:
                open -= 1
                if (open > 0):
                    ans += i
        
        return ans