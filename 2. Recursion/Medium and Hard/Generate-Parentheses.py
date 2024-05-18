# Generate Parentheses (Leetcode)
# Leetcode Link : https://leetcode.com/problems/generate-parentheses/description/

# Time Complexity : O(2^n)
# Space Complexity : O(n)

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        
        def solve(open, close, op):
            if open == 0 and close == 0:
                ans.append(op)
                return
            
            if open > 0:
                solve(open - 1, close, op + '(')
            
            if open < close:
                solve(open, close - 1, op + ')')
        
        solve(n, n, '')
        return ans