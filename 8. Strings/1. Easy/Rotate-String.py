# Rotate String (Leetcode)
# Leetcode Link : https://leetcode.com/problems/rotate-string/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        
        concatenated = s + s

        if goal in concatenated:
            return True
        
        return False