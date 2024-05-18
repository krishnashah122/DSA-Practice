# Reverse a Stack (GFG)
# GFG Link : https://shorturl.at/rwJRU

# Time Complexity : O(n^2)
# Space Complexity : O(1)

from typing import List

class Solution:
    def insert(self, St, element):
        n = len(St)
        if n == 0:
            St.append(element)
            return
        
        topElement = St[n - 1]
        St.pop()
        self.insert(St, element)
        St.append(topElement)
    
    def reverse(self,St): 
        #code here
        n = len(St)
        if n == 1:
            return
        
        topElement = St[n - 1]
        St.pop()
        self.reverse(St)
        self.insert(St, topElement)
        
        return