# Sum of Beauty of All Substrings (Leetcode)
# Leetcode Link : https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

# Time Complexity : O(n^2)
# Space Complexity : O(1)

class Solution:
    def beautySum(self, s: str) -> int:
        ans = 0 #for storing the beauty sum

        for i in range(len(s)): #loop through each character
            freq = [0]*26 #initialize frequency array to track character occurrences

            #iterate over substrings starting from index i to end of string
            for j in range(i, len(s)):
                freq[ord(s[j]) - 97] += 1 #update character frequency

                #calculate beauty of substring and add it to the answer
                beauty = max(freq) - min(x for x in freq if x)
                ans += beauty
        
        return ans