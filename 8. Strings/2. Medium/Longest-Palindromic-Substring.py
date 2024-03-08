# Longest Palindromic Substring (Leetcode)
# Leetcode Link : https://leetcode.com/problems/longest-palindromic-substring/description/

# Time Complexity : O(n^2)
# Space Complexity : O(1)

class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return s
        
        def expand(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left+1:right]
        
        result = ''
        for i in range(len(s)):
            #for odd length palindrome, consider the current character as the center and expand around it
            oddPalindrome = expand(i, i)
            if len(oddPalindrome) > len(result):
                result = oddPalindrome
            
            #for even length palindrome, consider the current character and the next character as the center and expand around it.
            evenPalindrome = expand(i, i+1)
            if len(evenPalindrome) > len(result):
                result = evenPalindrome
        
        return result