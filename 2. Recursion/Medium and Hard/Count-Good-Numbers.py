# Count Good Numbers (Leetcode)
# Leetcode Link : https://leetcode.com/problems/count-good-numbers/description/

# Time Complexity : O(Logn)
# Space Complexity : O(1)

class Solution:
    # function to calculate power of a number with modulo
    def pow(self, x, n):
        # defined mod as a constant
        mod = 1000000007
        if n == 0:
            return 1
        
        # if n is even
        if n%2 == 0:
            return self.pow((x*x) % mod, n//2)
        
        # if n is odd
        if n%2 == 1:
            return x * self.pow((x*x) % mod, (n-1)//2)

    def countGoodNumbers(self, n: int) -> int:
        # define mod as a constant
        mod = 1000000007
        # number of even places
        evenPlaces = n//2 + n%2
        # number of odd places
        oddPlaces = n//2
        # calculate the total no. of good numbers by multiplying the count of 5's for even and 4's for odd places, and then taking modulo to prevent overflow
        return (self.pow(5, evenPlaces) % mod * self.pow(4, oddPlaces) % mod) % mod