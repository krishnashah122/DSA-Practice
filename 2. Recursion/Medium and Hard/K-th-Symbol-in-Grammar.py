# K-th Symbol in Grammar (Leetcode)
# Leetcode Link : https://leetcode.com/problems/k-th-symbol-in-grammar/description/

# Time Complexity : O(n)
# Space Complexity : O(1)

class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1 and k == 1:
            return 0
        
        mid = pow(2, n-1) // 2
        if k <= mid:
            return self.kthGrammar(n-1, k)
        else:
            return 1 ^ self.kthGrammar(n-1, k - mid)