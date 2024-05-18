# Pow(x, n) (Leetcode)
# Leetcode Link : https://leetcode.com/problems/powx-n/description/

# Time Complexity : O(logn)
# Space Complexity : O(n)

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        
        # If n is negative
        if n < 0:
            # For example, if x=2 and n=-3, it calculates (1/2)^3
            return self.myPow(1/x, -n)
        
        # If n is even
        if n % 2 == 0:
            # For example, if x=2 and n=10, it calculates (2^2)^5 = 4^5 = 1024
            return self.myPow(x*x, n/2)
        # If n is odd
        else:
            # For example, if x=2 and n=7, it calculates 2 * (2^2)^3 = 2 * 4^3 = 128
            return x * self.myPow(x*x, (n-1)/2)