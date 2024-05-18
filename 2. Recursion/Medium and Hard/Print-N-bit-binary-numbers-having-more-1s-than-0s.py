# Print N-bit binary numbers having more 1s than 0s (GFG)
# GFG Link : https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

# Time Complexity : O(2^n)
# Space Complexity : O(n)

class Solution:
	def NBitBinary(self, n):
		# code here
        ans = []
        
        def solve(n, ones, zeros, op):
            if n == 0:
                ans.append(op)
                return
            
            solve(n - 1, ones + 1, zeros, op + '1')
            
            if ones > zeros:
                solve(n - 1, ones, zeros + 1, op + '0')
        
        solve(n, 0, 0, '')
        return ans
