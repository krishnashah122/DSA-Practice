# Palindrome Partitioning (Leetcode)
# Leetcode Link : https://leetcode.com/problems/palindrome-partitioning/description/

# Time Complexity : O(2^n * n/2 * k)
# O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

# Space Complexity : O(k*x)
# k is the average length of the list having palindrome strings and x is the no. of lists having palindrome strings. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).

class Solution:
    def isPalindrome(self, s):
        l = 0
        r = len(s) - 1

        while(l <= r):
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        
        return True

    def solve(self, s, ind, op, ans):
        n = len(s)
        if ind >= n:
            ans.append(op[:])
            return
        
        for i in range(ind, n):
            if self.isPalindrome(s[ind : i+1]):
                op.append(s[ind : i+1])
                self.solve(s, i + 1, op, ans)
                op.pop()

    def partition(self, s: str) -> List[List[str]]:
        ans = []
        self.solve(s, 0, [], ans)

        return ans