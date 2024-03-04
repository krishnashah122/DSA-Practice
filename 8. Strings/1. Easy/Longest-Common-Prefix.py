# Longest Common Prefix (Leetcode)
# Leetcode Link : https://leetcode.com/problems/longest-common-prefix/description/

# Time Complexity : O(n)
# Space Complexity : O(n)
# where, n is the length of the smallest string of list strs

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort() #sort the array
        num = len(strs[0]) #store the length of first element (smallest length)
        ans = ''

        for i in range(num):
            if strs[0][i] == strs[-1][i]: #check for common prefix between the first & the last element
                ans += strs[0][i]
            else:
                break

        return ans