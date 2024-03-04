# Largest Odd Number in String (Leetcode)
# Leetcode Link : https://leetcode.com/problems/largest-odd-number-in-string/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

class Solution:
    def largestOddNumber(self, num: str) -> str:
        ans = ''
        
        for i in range(len(num)):
            if int(num[i]) % 2 != 0:
                ans = num[:i+1]
        
        return ans