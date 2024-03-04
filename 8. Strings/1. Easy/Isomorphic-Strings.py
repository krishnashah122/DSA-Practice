# Isomorphic Strings (Leetcode)
# Leetcode Link : https://leetcode.com/problems/isomorphic-strings/description/

# Time Complexity : O(n)
# Space Complexity: O(n)

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        mapST, mapTS = {}, {}

        for ch1, ch2 in zip(s, t):
            #check if (ch1 -> ch2) in mapST & (ch2 -> ch1) in mapTS or not
            if ((ch1 in mapST and mapST[ch1] != ch2) or (ch2 in mapTS and mapTS[ch2] != ch1)):
                return False
            
            #if (ch1 -> ch2) is not in mapST & (ch2 -> ch1) is not in mapTS then add it
            mapST[ch1] = ch2
            mapTS[ch2] = ch1
        
        return True