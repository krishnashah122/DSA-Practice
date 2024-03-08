# Sort Characters By Frequency (Leetcode)
# Leetcode Link : https://leetcode.com/problems/sort-characters-by-frequency/description/

# Time Complexity : O(nLogn)
# Space Complexity : O(n)

class Solution:
    def frequencySort(self, s: str) -> str:
        d = dict()

        for ch in s:
            d[ch] = d.get(ch, 0) + 1
        
        #sort dictionary on the basis of its values in decreasing order
        sorted_dict = sorted(d.keys(), key = lambda item:d[item], reverse = True) #O(nLogn)
        s = ''
        for ch in sorted_dict:
            s += ch*d[ch]
        
        return s