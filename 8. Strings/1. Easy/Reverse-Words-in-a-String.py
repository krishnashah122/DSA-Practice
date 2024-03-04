# Reverse Words in a String (Leetcode)
# Leetcode Link : https://leetcode.com/problems/reverse-words-in-a-string/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

class Solution:
    def reverseWords(self, s: str) -> str:
        ans = []
        temp = ''

        for ch in s:
            if ch != ' ':
                temp += ch
            elif temp != '':
                ans.append(temp)
                temp = ''
        
        if temp != '':
            ans.append(temp)
        
        return ' '.join(ans[::-1])