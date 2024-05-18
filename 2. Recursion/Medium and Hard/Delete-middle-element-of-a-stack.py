# Delete middle element of a stack (GFG)
# GFG Link : https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

# Time Complexity : O(n)
# Space Complexity : O(n)

class Solution:
    def helper(self, s, mid):
        n = len(s)
        if mid == 1:
            s.pop()
            return
        
        topElement = s[n - 1]
        s.pop()
        self.helper(s, mid - 1)
        s.append(topElement)
    
    #Function to delete middle element of a stack.
    def deleteMid(self, s, sizeOfStack):
        # code here
        if len(s) == 0:
            return
        
        if len(s) % 2 == 0:
            mid = ((sizeOfStack + 1) // 2) + 1
        else:
            mid = (sizeOfStack + 1) // 2
        
        self.helper(s, mid)
        
        return