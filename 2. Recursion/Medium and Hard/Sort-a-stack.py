# Sort a stack (GFG)
# GFG Link : https://shorturl.at/eBJX3

# Time Complexity : O(n^2)
# Space Complexity : O(n)

class Solution:
    # your task is to complete this function
    # function sort the stack such that top element is max
    # funciton should return nothing
    # s is a stack
    def insert(self, s, element):
        n = len(s)
        if n == 0 or s[n-1] <= element:
            s.append(element)
            return
        
        topElement = s[n-1]
        s.pop()
        self.insert(s, element)
        s.append(topElement)
    
    def Sorted(self, s):
        # Code here
        n = len(s)
        if n == 1:
           return
        
        topElement = s[n-1]
        s.pop()
        self.Sorted(s)
        self.insert(s, topElement)
        
        return