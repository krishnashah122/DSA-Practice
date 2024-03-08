# Roman to Integer (Leetcode)
# Leetcode Link : https://leetcode.com/problems/roman-to-integer/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

class Solution:
    def romanToInt(self, s: str) -> int:
        #split the Roman Numeral string into Roman Symbols (character)
        mapRI = {
            'I' : 1,
            'V' : 5,
            'X' : 10,
            'L' : 50,
            'C' : 100,
            'D' : 500,
            'M' : 1000
        }

        n = len(s)
        result = mapRI[s[n-1]]

        #iterate for each symbol
        for i in range(n-1):
            #if current symbol value < next symbol value then subtract the current symbol value from result
            if mapRI[s[i]] < mapRI[s[i+1]]:
                result -= mapRI[s[i]]
            #if current symbol value >= next symbol value then add the current symbol value from result
            else:
                result += mapRI[s[i]]
        
        return result